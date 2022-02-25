from network_simulator import NetworkSimulator, Packet, EventEntity
from enum import Enum
from struct import pack, unpack


class GBNHost:
    # The __init__ method accepts:
    # - a reference to the simulator object
    # - the value for this entity (EntityType.A or EntityType.B)
    # - the interval for this entity's timer
    # - the size of the window used for the Go-Back-N algorithm
    def __init__(self, simulator, entity, timer_interval, window_size):
        # These are important state values that you will need to use in your code
        self.simulator = simulator
        self.entity = entity

        # Sender properties
        self.timer_interval = timer_interval  # The duration the timer lasts before triggering
        self.window_size = window_size  # The size of the seq/ack window
        self.window_base = 0  # The last ACKed packet. This starts at 0 because no packets
        # have been ACKed
        self.next_seq_num = 0  # The SEQ number that will be used next
        self.seq_expected = 0
        self.unACKed_buffer = []
        self.app_layer_buffer = []
        self.last_ACK = self.make_pkt(-1, "ACK")

    def make_pkt(self, packet_num, payload):
        if payload == "ACK":
            packed_data = pack("!HiHI", 0, packet_num, 0, 0)
            check_sum = self.get_checksum(packed_data)
            packed_data = pack("!HiHI", 0, packet_num, check_sum, 0)
            return packed_data
        else:
            packed_data = pack("!HiHI%is" % len(payload), 128, packet_num, 0, len(payload), payload.encode())
            check_sum = self.get_checksum(packed_data)
            packed_data = pack("!HiHI%is" % len(payload), 128, packet_num, check_sum, len(payload), payload.encode())
            return packed_data

    def get_checksum(self, message):
        if len(message) % 2 != 0:
            message = message + bytes(1)

        word_sum = 0
        for i in range(0, len(message), 2):
            words = message[i] << 8 | message[i + 1]
            word_sum += words
            word_sum = (word_sum & 0xffff) + (word_sum >> 16)

        check_sum = ~word_sum & 0xffff
        return check_sum

    def get_sequence_num(self, message):
        packet = unpack("!HiHI", message[:12])
        return packet[1]

    def check_ack(self, packet):
        message = unpack("!HiHI", packet[:12])
        if message[0] == 0:
            return True
        return False

    def get_ack_num(self, packet):
        ack = unpack("!HiHI", packet[:12])
        return ack[1]

    ###########################################################################################################
    # Core Interface functions that are called by Simulator
    # This function implements the SENDING functionality. It should implement retransmit-on-timeout. 
    # Refer to the GBN sender flowchart for details about how this function should be implemented
    def receive_from_application_layer(self, payload):
        if self.next_seq_num < self.window_base + self.window_size:
            # self.unACKed_buffer[self.next_seq_num] = self.make_pkt(self.next_seq_num, payload)
            # self.simulator.pass_to_network_layer(self.entity, self.unACKed_buffer[self.next_seq_num],
            #                                      self.check_ack(self.unACKed_buffer[self.next_seq_num]))
            self.unACKed_buffer.append(self.make_pkt(self.next_seq_num, payload))
            self.simulator.pass_to_network_layer(self.entity, self.unACKed_buffer[self.next_seq_num],
                                                 self.check_ack(self.unACKed_buffer[self.next_seq_num]))

            if self.window_base == self.next_seq_num:
                self.simulator.start_timer(self.entity, self.timer_interval)
            self.next_seq_num += 1
        else:
            self.app_layer_buffer.append(payload)

    # This function implements the RECEIVING functionality. This function will be more complex that
    # receive_from_application_layer(), it includes functionality from both the GBN Sender and GBN receiver
    # FSMs (both of these have events that trigger on receive_from_network_layer). You will need to handle
    # data differently depending on if it is a packet containing data, or if it is an ACK.
    # Refer to the GBN receiver flowchart for details about how to implement responding to data packets, and
    # refer to the GBN sender flowchart for details about how to implement responding to ACKs
    def receive_from_network_layer(self, byte_data):
        if self.check_ack(byte_data) and not self.is_corrupt(byte_data):
            ack_num = self.get_ack_num(byte_data)
            if ack_num >= self.window_base:
                self.window_base = ack_num + 1
                self.simulator.stop_timer(self.entity)
                if self.window_base != self.next_seq_num:
                    self.simulator.start_timer(self.entity, self.timer_interval)
                while len(self.app_layer_buffer) > 0 and self.next_seq_num < self.window_base + self.window_size:
                    payload = self.app_layer_buffer.pop()
                    self.unACKed_buffer.append(self.make_pkt(self.next_seq_num, payload))
                    self.simulator.pass_to_network_layer(self.entity, self.unACKed_buffer[self.next_seq_num],
                                                         self.check_ack(self.unACKed_buffer[self.next_seq_num]))
                    if self.window_base == self.next_seq_num:
                        self.simulator.start_timer(self.entity, self.timer_interval)
                    self.next_seq_num += 1
        elif self.get_sequence_num(byte_data) != self.seq_expected or self.is_corrupt(byte_data):
            self.simulator.pass_to_network_layer(self.entity, self.last_ACK, self.check_ack(self.last_ACK))
        else:
            try:
                data = unpack("!HiHI", byte_data[:12])
                payload = unpack("!%is" % data[3], byte_data[12:])
                data = payload[0].decode()
            except Exception:
                self.simulator.pass_to_network_layer(self.entity, self.last_ACK, self.check_ack(self.last_ACK))

            self.simulator.pass_to_application_layer(self.entity, data)
            self.last_ACK = self.make_pkt(self.seq_expected, "ACK")
            self.simulator.pass_to_network_layer(self.entity, self.last_ACK, self.check_ack(self.last_ACK))
            self.seq_expected += 1

    # This function is called by the simulator when a timer interrupt is triggered due to an ACK not being 
    # received in the expected time frame. All unACKed data should be resent, and the timer restarted
    def timer_interrupt(self):
        self.simulator.start_timer(self.entity, self.timer_interval)
        for i in range(self.window_base, self.next_seq_num, 1):
            self.simulator.pass_to_network_layer(self.entity, self.unACKed_buffer[i],
                                                 self.check_ack(self.unACKed_buffer[i]))

    # This function should check to determine if a given packet is corrupt. The packet parameter accepted
    # by this function should contain a byte array
    def is_corrupt(self, payload):
        message = unpack("!HiHI", payload[:12])
        check_sum = message[2]
        packet_head = pack("!HiHI", message[0], message[1], 0, message[3])
        payload = packet_head + payload[12:]

        if check_sum != self.get_checksum(payload):
            return True
        return False
