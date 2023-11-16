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
    connect(sock,(struct sockaddr*)&address,sizeof(address));
    char message[1024];
    cout << "Enter a message to send: ";
    cin>>message;
    send(sock,message,sizeof(message),0);
    return 0;
}