#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
using namespace std;
int main(){
    int sock = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.2");
    address.sin_port = htons(1234);
    bind(sock,(struct sockaddr*) &address,sizeof(sockaddr));
    listen(sock,2);
    struct sockaddr_in client;
    socklen_t clilen = sizeof(client);
    int clientadrr = accept(sock,(struct sockaddr * )&client,&clilen);
    char message[1024];
    recv(clientadrr, message, 1024, 0);
    cout << "Received message from client: " << message << endl;
    return 0;
}