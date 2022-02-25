from socket import *
import unittest
import threading, random, string, time
#from gradescope_utils.autograder_utils.decorators import weight
#from gradescope_utils.autograder_utils.files import check_submitted_files
from buffered_client import BufferedTCPClient
from buffered_server import BufferedTCPEchoServer

class TestMessaging(unittest.TestCase):
    def setUp(self):
        pass
    
    def tearDown(self):
        pass

    def launch_server(self, server, server_started_event):
        server_started_event.set()
        server.start()

    def create_message_of_length(self, length):
        return ''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(length))

    def check_client_shutdown(self, client):
        client.shutdown()
        time.sleep(1)

        try:
            client.send_message("Checking to see if the socket is closed. An exception should be thrown")
        except Exception as err:
            errorTypeCorrect = type(err) == OSError or type(err) == IOError

            self.assertTrue(errorTypeCorrect, """
                    Your client socket does not appear to have been closed. To test this, the client's send_message function
                    was called after calling the client's shutdown() method. This should return an OSError (number 10038) indicating 
                    that an operation has been attempted on something that is not a socket (this error applies because the socket
                    has been closed). This exception was not raised, indicating something is wrong. """)
            return
        

        self.assertTrue(False, """
                Your client socket does not appear to have been closed. To test this, the client's send_message function
                was called after calling the client's shutdown() method. This should return an OSError (number 10038) indicating 
                that an operation has been attempted on something that is not a socket (this error applies because the socket
                has been closed). This exception was not raised, indicating something is wrong. """)


    def check_server_shutdown(self, server, server_addr, server_port):
        server.keep_running = False
        # time.sleep(60)
        # try:
        #     print("Testing is server is shut down. Creating a new client and attempting to conenct to it")
        #     new_client = socket(AF_INET, SOCK_STREAM)
        #     new_client.connect((server_addr, server_port))

        # except Exception as err:

        #     print("SERVER: Exception occured on shutdown: " + str(err.errno))

        #     self.assertTrue(type(err) == ConnectionRefusedError, """
        #             Your server socket has not been closed. To test this, a new socket was created that then attempted to connect
        #             to the server socket. If the socket was closed, a ConnectionRefusedError should be generated, indicating that
        #             the remote server did not accept the connection request. This exception was not raised, indicting something is wrong. """)
        #     return
        
        # self.assertTrue(False, """
        #             Your server socket has not been closed. To test this, a new socket was created that then attempted to connect
        #             to the server socket. If the socket was closed, a ConnectionRefusedError should be generated, indicating that
        #             the remote server did not accept the connection request. This exception was not raised, indicting something is wrong. """)


    ### This is a basic test, send a short message and check to see if it is returned correctly
    ### Works without requiring any buffering
    #@weight(1)
    def test_short_message(self):
        """Test a message that is smaller than the buffer size"""
        input_message = self.create_message_of_length(32)
        
        server = BufferedTCPEchoServer('', 36002, 1024)
        server_started_event = threading.Event()
        server_thread = threading.Thread(target=self.launch_server, args=(server,server_started_event), daemon=True)
        server_thread.start()

        server_started_event.wait()

        client = BufferedTCPClient("localhost", 36002, 1024)

        client.send_message(input_message)
        response, success = client.receive_message()

        # Check the basic connectivity
        self.assertEqual(input_message[10:], response, """
                    The client did not received back the expected response. It differed 
                    from the string that was sent to the server.""")

        correct = self.check_client_shutdown(client)

        correct = self.check_server_shutdown(server, "localhost", 36002)


    ### This is a slightly more complex test, requires an additional read and addition to the buffer
    #@weight(2)
    def test_medium_message(self):
        """Test a message that is slightly longer than the buffer size"""
        input_message = self.create_message_of_length(1245)

        server = BufferedTCPEchoServer('', 36003, 1024)
        server_started_event = threading.Event()
        server_thread = threading.Thread(target=self.launch_server, args=(server,server_started_event), daemon=True)
        server_thread.start()

        server_started_event.wait()

        client = BufferedTCPClient("localhost", 36003, 1024)

        client.send_message(input_message)
        response, success = client.receive_message()

        # Check the basic connectivity
        self.assertEqual(input_message[10:], response, """
                    The client did not received back the expected response. It differed 
                    from the string that was sent to the server.""")

        self.check_client_shutdown(client)
        self.check_server_shutdown(server, "localhost", 36003)
    
    
    ### Now sends a message much longer than the buffer size, requiring many iterations
    #@weight(2)
    def test_long_message(self):
        """Test a message that is several times longer than the buffer size"""
        input_message =  self.create_message_of_length(650000)

        server = BufferedTCPEchoServer('', 36004)
        server_started_event = threading.Event()
        server_thread = threading.Thread(target=self.launch_server, args=(server,server_started_event), daemon=True)
        server_thread.start()

        server_started_event.wait()

        client = BufferedTCPClient("localhost", 36004)

        client.send_message(input_message)
        response, success = client.receive_message()

        # Check the basic connectivity
        self.assertEqual(input_message[10:], response, """
                    The client did not received back the expected response. It differed 
                    from the string that was sent to the server.""")

        self.check_client_shutdown(client)
        self.check_server_shutdown(server, "localhost", 36004)


    ### This test sends multiple messages, waiting between each sending to receive the previous message
    #@weight(3)
    def test_multiple_messages_in_series(self):
        """Test sending several messages in series, waiting for the response before sending the next"""
        input_message_1 =  self.create_message_of_length(1500)
        input_message_2 =  self.create_message_of_length(1500)
        input_message_3 =  self.create_message_of_length(1500)

        server = BufferedTCPEchoServer('', 36005)
        server_started_event = threading.Event()
        server_thread = threading.Thread(target=self.launch_server, args=(server,server_started_event), daemon=True)
        server_thread.start()

        server_started_event.wait()

        client = BufferedTCPClient("localhost", 36005)

        client.send_message(input_message_1)
        response_1, success = client.receive_message()

        # Check the basic connectivity
        self.assertEqual(input_message_1[10:], response_1, """
                    The client did not received back the expected response. It differed 
                    from the string that was sent to the server.""")


        client.send_message(input_message_2)
        response_2, success = client.receive_message()

        # Check the basic connectivity
        self.assertEqual(input_message_2[10:], response_2, """
                    The client did not received back the expected response. It differed 
                    from the string that was sent to the server.""")


        client.send_message(input_message_3)
        response_3, success = client.receive_message()

        # Check the basic connectivity
        self.assertEqual(input_message_3[10:], response_3, """
                    The client did not received back the expected response. It differed 
                    from the string that was sent to the server.""")
    
        self.check_client_shutdown(client)
        self.check_server_shutdown(server, "localhost", 36005)


    


    ### This test sends multiple messages, waiting between each sending to receive the previous message
    #@weight(3)
    def test_multiple_messages_in_parallel(self):
        """Testing sending several messages at once, and then receiving the responses"""
        input_message_1 =  self.create_message_of_length(1500)
        input_message_2 =  self.create_message_of_length(1500)
        input_message_3 =  self.create_message_of_length(1500)

        server = BufferedTCPEchoServer('', 36006)
        server_started_event = threading.Event()
        server_thread = threading.Thread(target=self.launch_server, args=(server,server_started_event), daemon=True)
        server_thread.start()

        server_started_event.wait()

        client = BufferedTCPClient("localhost", 36006)

        client.send_message(input_message_1)
        client.send_message(input_message_2)
        client.send_message(input_message_3)

        response_1, success = client.receive_message()

        # Check the basic connectivity
        self.assertEqual(input_message_1[10:], response_1, """
                    The client did not received back the expected response. It differed 
                    from the string that was sent to the server.""")


        response_2, success = client.receive_message()

        # Check the basic connectivity
        self.assertEqual(input_message_2[10:], response_2, """
                    The client did not received back the expected response. It differed 
                    from the string that was sent to the server.""")


        response_3, success = client.receive_message()

        # Check the basic connectivity
        self.assertEqual(input_message_3[10:], response_3, """
                    The client did not received back the expected response. It differed 
                    from the string that was sent to the server.""")

        self.check_client_shutdown(client)
        self.check_server_shutdown(server, "localhost", 36006)

if __name__ == '__main__':
    t = TestMessaging()
    t.test_long_message()