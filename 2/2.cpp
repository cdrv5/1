#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
using namespace std;
int main() {
    int clientSock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.3");
    server.sin_port = htons(1236);
    const char* message = "Hello, server!";
    sendto(clientSock, message, strlen(message), 0, (struct sockaddr*)&server, sizeof(server));
    char echoedMessage[1024];
    struct sockaddr_in serverAddress;
    socklen_t serverAddressLen = sizeof(serverAddress);
    ssize_t receivedBytes = recvfrom(clientSock, echoedMessage, sizeof(echoedMessage), 0, (struct sockaddr*)&serverAddress, &serverAddressLen);
    cout << "Received echoed message from server: " << echoedMessage << endl;
    close(clientSock);
    return 0;
}