from network_config import *


class RoundTripLatencyCalculator:

    def __init__(self, input_config):
        self.config = input_config

    def calculate_total_RTT(self):
        total = 0
        for i in range(self.config['num_links']):
            total += self.calculate_link_contribution(i)
        return total*2

    def calculate_link_contribution(self, hop_number):
        return self.calculate_transmission_delay(hop_number) + self.calculate_propagation_delay(hop_number) +\
               self.calculate_processing_delay(hop_number) + self.calculate_queuing_delay(hop_number)

    def calculate_transmission_delay(self, hop_number):
        return self.config['packet_length'] / self.config['bandwidths'][hop_number]

    def calculate_propagation_delay(self, hop_number):
        return self.config['distances'][hop_number] / self.config['transmission_speeds'][hop_number]

    def calculate_processing_delay(self, hop_number):
        return self.config['processing_delays'][hop_number]

    def calculate_queuing_delay(self, hop_number):
        delay_factor = (self.config['packet_length'] * self.config['average_packet_arrival_rates'][hop_number]) /\
                       self.config['bandwidths'][hop_number]

        return 0.1 / (1 - delay_factor) - 0.1


# You do not need to change anything in the main method. It will not be called by the testing suite, so anything
# you implement here will not register when you submit your code. It is intended for your own personal testing only
if __name__ == "__main__":
    calc = RoundTripLatencyCalculator(config)

    latency = calc.calculate_total_RTT()
    print(latency)
