#include <iostream>
#include <cstdlib>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

string executeCommand(const string& command) {
    string result;
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        cerr << "Error executing command." << endl;
        return "Error executing command.";
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }

    pclose(pipe);
    return result;
}

int main() {
    int serverSock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(12345);

    bind(serverSock, (struct sockaddr*)&server, sizeof(server));

    cout << "UDP Remote Command Execution Server listening on port 12345" << endl;

    struct sockaddr_in client;
    socklen_t clientLen = sizeof(client);

    char command[256];
    ssize_t receivedBytes = recvfrom(serverSock, command, sizeof(command), 0,
                                     (struct sockaddr*)&client, &clientLen);

    command[receivedBytes] = '\0';

    cout << "Received command: " << command << endl;

    string result = executeCommand(command);

    // Send the result back to the client
    sendto(serverSock, result.c_str(), result.size(), 0,
           (struct sockaddr*)&client, clientLen);

    // Close the socket when done
    close(serverSock);

    return 0;
}
