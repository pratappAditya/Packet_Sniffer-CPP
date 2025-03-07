#include <pcap.h>  // Include pcap header for packet capture
#include <iostream>  // Include iostream for input/output operations

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    std::cout << "Packet captured!" << std::endl;  // Print a message when a packet is captured
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];  // Buffer to store error messages
    pcap_t *handle;  // Handle for the packet capture session

    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);  // Open the network interface for packet capture
    if (handle == nullptr) {
        std::cerr << "Couldn't open device eth0: " << errbuf << std::endl;  // Print an error message if the interface couldn't be opened
        return 2;  // Return 2 to indicate an error
    }

    if (pcap_datalink(handle) != DLT_EN10MB) {  // Check if the interface is an Ethernet interface
        std::cerr << "eth0 is not an Ethernet" << std::endl;  // Print an error message if the interface is not Ethernet
        return 2;  // Return 2 to indicate an error
    }

    pcap_loop(handle, 0, packet_handler, nullptr);  // Capture packets in a loop and call the packet_handler function for each packet

    pcap_close(handle);  // Close the packet capture session
    return 0;  // Return 0 to indicate successful execution
}