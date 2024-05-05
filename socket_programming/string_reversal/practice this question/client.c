#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>


int main(int argc, char* argv[]){

    int sfd;
    int port = atoi(argv[2]);
    char* ip = argv[1];
    
    struct sockaddr_in server_addr;
    
    sfd = socket(AF_INET,SOCK_STREAM,0);
    
    memset(&server_addr,0,sizeof(server_addr));
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr =  inet_addr(ip);
    server_addr.sin_port  = htons(port);
    
    connect(sfd, (struct sockaddr *)&server_addr ,sizeof(server_addr));
    
    char* buffer = "AMERICA";
    
    ssize_t byteswrite = write(sfd, buffer,strlen(buffer));
    
    char readdata[1024];
    
    ssize_t readbytes = read(sfd, readdata,sizeof(readdata));
    
    readdata[readbytes]='\0';
    printf("data Recieved from server is -- %s\n ",readdata);
    
    close(sfd);
    
    
    
    
    
       






}
