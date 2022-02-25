from layer_header import LayerHeader
from struct import pack, unpack

class TCPHeader(LayerHeader):
    def __init__(self, pkt):
        # TODO: Replace the value of header_length with the length of an Ethernet header
        header_length = 20
        
        # TODO: If this header can be variable length, you will need to update the contents of 
        #       self.header_bytes once you know the full length of the header in order to ensure
        #       that all of the bytes associated with this header are saved. 
        #       You can leave it as is for now.
        self.header_bytes = pkt[:header_length]
        head = unpack("!HHIIBBHHH", self.header_bytes)

        self.source_port = head[0]
        self.dest_port = head[1]
        self.SEQ = head[2]
        self.ACK = head[3]
        self.data_offset = (head[4] >> 4)
        self.NS_flag = (head[4] & 0x0100)
        self.CWR_flag = (head[5] >> 7) & 0x0001
        self.ECE_flag = (head[5] >> 6) & 0x0001
        self.URG_flag = (head[5] >> 5) & 0x0001
        self.ACK_flag = (head[5] >> 4) & 0x0001
        self.PSH_flag = (head[5] >> 3) & 0x0001
        self.RST_flag = (head[5] >> 2) & 0x0001
        self.SYN_flag = (head[5] >> 1) & 0x0001
        self.FIN_flag = (head[5] & 0x0001)
        self.window_size = head[6]
        self.checksum = head[7]
        self.urg_pointer = head[8]
        if self.data_offset > 5:
            options = (self.data_offset * 4) - header_length
            padded_head = unpack("!HHIIBBHHH" + str(options) + 's', pkt)
            self.options_bytes = padded_head[9]
        else:
            self.options_bytes = None
        # TODO: Unpack the header and assign the values to the above variables

        # TODO: You do not need to unpack any options, if they are present in the header. However, if options 
        #       are present, store the bytes associated with them in self.options_bytes.

    def protocol(self):
        return "TCP"

    def header_bytes(self):
        return self.header_bytes

    def print_header(self):
        print("")
        print("TCP HEADER: ")
        line_width = (96+4)

        ####################################################################
        # Print first line
        print("-"*line_width)
        
        # Compose the contents of the first row of the header
        version_str = "SOURCE PORT: " + str(self.source_port)
        white_space = (48 - len(version_str))//2
        first_row_str = "|" + " "*white_space + version_str + " "*white_space + "|"

        ihl_str = "DEST PORT: " + str(self.dest_port)
        white_space = (48 - len(ihl_str))//2
        first_row_str += " "*white_space + ihl_str + " "*white_space + "|"

        # Print the first row of the header
        print(first_row_str)
        


        ####################################################################
        # Print first line
        print("-"*line_width)
        
        # Compose the contents of the first row of the header
        version_str = "SEQ NUMBER: " + str(self.SEQ)
        white_space = (96 - len(version_str))//2
        first_row_str = "|" + " "*white_space + version_str + " "*white_space + "|"

        # Print the first row of the header
        print(first_row_str)


        ####################################################################
        # Print first line
        print("-"*line_width)
        
        # Compose the contents of the first row of the header
        version_str = "ACK NUMBER: " + str(self.ACK)
        white_space = (96 - len(version_str))//2
        first_row_str = "|" + " "*white_space + version_str + " "*white_space + "|"

        # Print the first row of the header
        print(first_row_str)


        ####################################################################
        # Print first line
        print("-"*line_width)
        
        # Compose the contents of the first row of the header
        version_str = "OFFSET: " + str(self.data_offset)
        white_space = (16 - len(version_str))//2
        first_row_str = "|" + " "*white_space + version_str + " "*white_space + "|"

        ihl_str = "  ---  |"
        first_row_str += ihl_str

        ihl_str = "NS:" + ("1" if self.NS_flag else "0")
        white_space = (5 - len(ihl_str))//2
        first_row_str += " "*white_space + ihl_str + " "*white_space + "|"

        ihl_str = "CWR:" + ("1" if self.CWR_flag else "0")
        white_space = (5 - len(ihl_str))//2
        first_row_str += " "*white_space + ihl_str + " "*white_space + "|"

        ihl_str = "ECE:" + ("1" if self.ECE_flag else "0")
        white_space = (5 - len(ihl_str))//2
        first_row_str += " "*white_space + ihl_str + " "*white_space + "|"

        ihl_str = "URG:" + ("1" if self.URG_flag else "0")
        white_space = (5 - len(ihl_str))//2
        first_row_str += " "*white_space + ihl_str + " "*white_space + "|"

        ihl_str = "ACK:" + ("1" if self.ACK_flag else "0")
        white_space = (5 - len(ihl_str))//2
        first_row_str += " "*white_space + ihl_str + " "*white_space + "|"

        ihl_str = "PSH:" + ("1" if self.PSH_flag else "0")
        white_space = (5 - len(ihl_str))//2
        first_row_str += " "*white_space + ihl_str + " "*white_space + "|"

        ihl_str = "RST:" + ("1" if self.RST_flag else "0")
        white_space = (5 - len(ihl_str))//2
        first_row_str += " "*white_space + ihl_str + " "*white_space + "|"

        ihl_str = "SYN:" + ("1" if self.SYN_flag else "0")
        white_space = (5 - len(ihl_str))//2
        first_row_str += " "*white_space + ihl_str + " "*white_space + "|"

        ihl_str = "FIN:" + ("1" if self.FIN_flag else "0")
        white_space = (5 - len(ihl_str))//2
        first_row_str += " "*white_space + ihl_str + " "*white_space + "|"

        ihl_str = "WIN:" + str(self.window_size)
        white_space = (20 - len(ihl_str))//2
        first_row_str += " "*white_space + ihl_str + " "*white_space + "|"

        # Print the first row of the header
        print(first_row_str)



        ####################################################################
        # Print first line
        print("-"*line_width)
        
        # Compose the contents of the first row of the header
        version_str = "CHECKSUM: " + str(self.checksum)
        white_space = (48 - len(version_str))//2
        first_row_str = "|" + " "*white_space + version_str + " "*white_space + "|"

        # Compose the contents of the first row of the header
        version_str = "URG POINTER: " + str(self.urg_pointer)
        white_space = (48 - len(version_str))//2
        first_row_str += " "*white_space + version_str + " "*white_space + "|"

        # Print the first row of the header
        print(first_row_str)

        ####################################################################
        # Print a line divider
        print("-"*line_width)

        return super().print_header()