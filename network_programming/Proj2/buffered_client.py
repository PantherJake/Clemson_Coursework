from socket import *
from struct import *


class BufferedTCPClient:
    def __init__(self, server_host='localhost', server_port=36001, buffer_size=1024):
        self.buffer_size = buffer_size

        self.fixed_header_length = 4
        self.tcp_client = socket(AF_INET, SOCK_STREAM)
        self.tcp_client.connect((server_host, server_port))

    # This method is called by the auto grader. You must implement it,
    # and you cannot change the method signature. It should accept a message
    # from the user, which is packed according to the format specified
    # for this assignment and then sent into the socket.
    def send_message(self, message):
        print('CLIENT: Attempting to send a message...')
        data = pack('!I' + str(len(message)) + 's', len(message), message.encode())
        self.tcp_client.send(data)

    # This method is called by the auto grader. You must implement it,
    # and you cannot change the method signature. It should wait to receive a
    # message from the socket, which is then returned to the user. It should
    # return two values: the message received and whether or not it was received
    # successfully. In the event that it was not received successfully, return an empty string for the message.
    def receive_message(self):
        print('CLIENT: Attempting to receive a message...')
        data = self.tcp_client.recv(self.fixed_header_length)
        if data:
            first_part = data[0:4]
            first_part = unpack('!I', first_part)[0]
            message = data[4:]
            while len(message) < first_part:
                self.buffer_size = min(self.buffer_size, first_part - len(message))
                data = self.tcp_client.recv(self.buffer_size)
                message += data
            message = message.decode()
            return message, True
        else:
            return '', False

    def shutdown(self):
        print("CLIENT: Attempting to shut down...")
        self.tcp_client.close()


if __name__ == "__main__":
    l = BufferedTCPClient(server_host="localhost", server_port=36001)
    l.send_message("Four score and seven years ago")
    response = l.receive_message()
    print(response)
