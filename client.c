#include <stdio.h>
#include <string.h> //strlen
#include <sys/socket.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h> //close

int main(int argc, char *argv[]){
    int socket_desc;
    struct sockaddr_in server;
    char *message, server_reply[2000];

    //AF_INET - IPv4, SOCK_STREAM - tcp,0 - IP
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if(socket_desc == -1){
        printf("Não foi possível criar o socket");
        return 1;
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1"); //converte IP para long
    server.sin_family = AF_INET;   //IPv4
    server.sin_port = htons(8888);

    if(connect(socket_desc, (struct sockaddr *) &server, sizeof(server))<0){
        printf("Erro ao conectar-se\n");
        return 1;
    }
    printf("Conectado.\n");

    //envia dados
    message = "Olá, Mundo!";
    if(send(socket_desc, message, strlen(message), 0) <0){
        printf("Erro ao enviar\n");
        return 1;
    }
    printf("Dados enviados.\n");

    //recebe dados do servidor
    if(recv(socket_desc, server_reply, 2000, 0)<0){
        printf("Falha no recv\n");
        return 1;
    }
    printf("Resposta recebida.\n");
    printf("%s\n", server_reply);

    //encerra a conexão
    close(socket_desc);

    return 0;
}