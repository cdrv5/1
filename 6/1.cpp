#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

int main(){
    int sock = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(1234);
    bind(sock,(struct sockaddr*)&address,sizeof(address));
    listen(sock,2);
    struct sockaddr_in clientaddress;
    socklen_t clientlen = sizeof(clientaddress);
    int clientsock = accept(sock,(struct sockaddr*)&clientaddress,&clientlen);
    int count = 10;
    while(count--){
    char message[1024],message1[1024];
    recv(clientsock,message,sizeof(message),0);
    cout<<"Message recieved from client : "<<message<<"\n";
    cout<<"Enter a message to be sent to client : ";
    cin>>message1;
    send(clientsock,message1,sizeof(message1),0);
    cout<<"Message sent to server successfully\n";
    }
 return 0;   
}