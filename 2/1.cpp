#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
using namespace std;
int main() {
    int serverSock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(1236);
    bind(serverSock, (struct sockaddr*)&server, sizeof(server));
    char message[1024];
    struct sockaddr_in client;
    socklen_t clientLen = sizeof(client);
    ssize_t receivedBytes = recvfrom(serverSock, message, sizeof(message), 0,(struct sockaddr*)&client, &clientLen);
    sendto(serverSock, message, receivedBytes, 0, (struct sockaddr*)&client, clientLen);
    cout << "Received and echoed message: " << message << endl;
    close(serverSock);
    return 0;
}