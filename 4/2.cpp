#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

int main() {
    int clientSock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(12345);

    cout << "Enter the command to execute: ";
    string command;
    getline(cin, command);

    // Send the command to the server
    sendto(clientSock, command.c_str(), command.size(), 0,
           (struct sockaddr*)&server, sizeof(server));

    char result[1024];
    socklen_t serverLen = sizeof(server);

    // Receive the result from the server
    ssize_t receivedBytes = recvfrom(clientSock, result, sizeof(result), 0,
                                     (struct sockaddr*)&server, &serverLen);

    result[receivedBytes] = '\0';

    cout << "Result from the server: " << result << endl;

    // Close the socket when done
    close(clientSock);

    return 0;
}
