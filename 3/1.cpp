#include <iostream>
#include <fstream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

void receiveFile(int socket, const string& filename) {
    ofstream outputFile(filename, ios::binary);

    if (!outputFile.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    char buffer[1024];
    ssize_t bytesRead;

    while ((bytesRead = recv(socket, buffer, sizeof(buffer), 0)) > 0) {
        outputFile.write(buffer, bytesRead);
    }

    outputFile.close();
}

int main() {
    int serverSock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(12345);

    bind(serverSock, (struct sockaddr*)&server, sizeof(server));

    cout << "UDP File Transfer Server listening on port 12345" << endl;

    struct sockaddr_in client;
    socklen_t clientLen = sizeof(client);

    char filename[256];
    recvfrom(serverSock, filename, sizeof(filename), 0,
             (struct sockaddr*)&client, &clientLen);

    cout << "Receiving file: " << filename << endl;

    receiveFile(serverSock, filename);

    cout << "File received successfully." << endl;

    // Close the socket when done
    close(serverSock);

    return 0;
}
