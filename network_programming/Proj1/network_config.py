# TODO: Define a variable named 'config' that contains a dictionary with the entries
#       'packet_length', 'num_links', 'bandwidths', 'distances', 'transmission_speeds', 'processing_delays', and 'average_packet_arrival_rate'
#       These variables will contain all of the information we need to compute a packets round trip latency through a network.
#       'packet_length' should store the length of the packet in bytes
#       'num_links' should store the number of links the packet will pass through
#       the remaining entries should store lists of length 'num_links', where each entry in the list corresponds with the value associated with that link

config = {}
config['packet_length'] = 1000
config['num_links'] = 2
config['bandwidths'] = [10, 10]
config['distances'] = [5, 5]
config['transmission_speeds'] = [200000000, 200000000]
config['processing_delays'] = [0.1, 0.1]
config['average_packet_arrival_rates'] = [1, 1]

