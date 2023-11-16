#include <iostream>
#include <fstream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

void sendFile(int socket, const string& filename) {
    ifstream inputFile(filename, ios::binary);

    if (!inputFile.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    char buffer[1024];
    while (!inputFile.eof()) {
        inputFile.read(buffer, sizeof(buffer));
        ssize_t bytesRead = inputFile.gcount();

        send(socket, buffer, bytesRead, 0);
    }

    inputFile.close();
}

int main() {
    int clientSock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(12345);

    cout << "Enter the name of the file to send: ";
    string filename;
    cin >> filename;

    sendto(clientSock, filename.c_str(), filename.size(), 0,
           (struct sockaddr*)&server, sizeof(server));

    cout << "Sending file: " << filename << endl;

    sendFile(clientSock, filename);

    cout << "File sent successfully." << endl;

    // Close the socket when done
    close(clientSock);

    return 0;
}
