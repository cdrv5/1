#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

int main() {
    int serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in serverAddress;

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(12345);

    bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    cout << "ARP-like Server (Responder) listening on port 12345" << endl;

    while (true) {
        char targetIP[16];
        struct sockaddr_in clientAddress;
        socklen_t clientLen = sizeof(clientAddress);

        // Receive the target IP address from the client
        recvfrom(serverSocket, targetIP, sizeof(targetIP), 0,
                 (struct sockaddr*)&clientAddress, &clientLen);

        targetIP[15] = '\0';

        cout << "Received ARP-like request for IP: " << targetIP << endl;

        // Simulate a response with a MAC address (for demonstration purposes)
        const char* simulatedMAC = "01:23:45:67:89:ab";

        // Send the simulated MAC address back to the client
        sendto(serverSocket, simulatedMAC, strlen(simulatedMAC), 0,
               (struct sockaddr*)&clientAddress, clientLen);

        cout << "Responded with MAC address: " << simulatedMAC << endl;
    }

    // Close the socket when done
    close(serverSocket);

    return 0;
}
