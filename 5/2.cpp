#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

int main() {
    int clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in serverAddress;

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddress.sin_port = htons(12345);

    cout << "Enter the target IP address: ";
    string targetIP;
    cin >> targetIP;

    // Send the target IP address to the server
    sendto(clientSocket, targetIP.c_str(), targetIP.size(), 0,
           (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    char responseMAC[18];
    socklen_t serverLen = sizeof(serverAddress);

    // Receive the MAC address response from the server
    ssize_t receivedBytes = recvfrom(clientSocket, responseMAC, sizeof(responseMAC), 0,
                                     (struct sockaddr*)&serverAddress, &serverLen);

    responseMAC[receivedBytes] = '\0';

    cout << "Received MAC address from server: " << responseMAC << endl;

    // Close the socket when done
    close(clientSocket);

    return 0;
}
