#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

void reverse(char* str){

int len = strlen(str);
for(int i=0;i<len/2;i++){
    char temp = str[i];
    str[i] = str[len-i-1];
    str[len-i-1] = temp;
    


}



}




int main(int argc, char* argv[]){

    int port = atoi(argv[1]);
    int sfd,cfd;
    struct sockaddr_in server_addr,client_addr;
    socklen_t addr_len;
    sfd = socket(AF_INET,SOCK_STREAM,0);
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);
    
    
    
    
    //bind
    bind(sfd,(struct sockaddr *)&server_addr,sizeof(server_addr));
    
    //listen
    listen(sfd,3);
    
    printf("Server is listening on port numbver - %d\n",port);
    
    addr_len=sizeof(client_addr);
    
    //accept
    cfd = accept(sfd,(struct sockaddr *)&client_addr,&addr_len);
    
    char buffer[1024];
    ssize_t readbytes =read(cfd , buffer , sizeof(buffer) );
    buffer[readbytes]='\0';
    
    
    printf("Data from client is -- %s\n",buffer);
    reverse(buffer);
    
    ssize_t sendbytes = write(cfd ,buffer , sizeof(buffer) );
    
    close(cfd);
    close(sfd);

return 0;


}
