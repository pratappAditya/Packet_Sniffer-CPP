1.Installation:
Install libpcap on your system. On Ubuntu: sudo apt-get install libpcap-dev.
Create a new C++ project in your preferred IDE.

2.Compile and Run:
Save the code in a file named packet_sniffer.cpp.
Compile the code: g++ packet_sniffer.cpp -o packet_sniffer -lpcap.
Run the executable: sudo ./packet_sniffer.

3.Testing:
Run the packet sniffer on your attack machine.
Generate some network traffic (e.g., ping another machine) and observe the output.