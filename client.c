#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr

int main(int argc, char *argv[]){
    int socket_desc;
    struct sockaddr_in server;
    /*AF_INET - IPv4, SOCK_STREAM - tcp, 0 - IP */
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if(socket_desc ==-1){
        printf("Não foi possível criar o socket");
        return 1;
    }


    return 0;
}