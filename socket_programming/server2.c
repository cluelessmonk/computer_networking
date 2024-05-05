#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080
int main(){


   int server_fd,client_fd;
   
   ssize_t valread;
   
   char buffer[1024]={0};
   char* message ="Hello From Server";
   
   //struct to hold socket info
   struct sockaddr_in address1;
   //size of socketaddress struct
   socklen_t address_size = sizeof(address1);
   
   //-----------------------------------Declaration Complete----------------------------//
   //------------------------------Initialization Starts Here---------------------------//
   
   //socket system call
   server_fd = socket(AF_INET,SOCK_STREAM,0);
   
   //struct filling address
   address1.sin_family = AF_INET;
   address1.sin_addr.s_addr = INADDR_ANY;
   address1.sin_port = htons(PORT);
   
   //bind system call implemented
   bind(server_fd ,(struct sockaddr *) &address1,sizeof(address1) );
   
   //listen system call
   listen( server_fd,3 );
   
   //accept the conection through client fd
   client_fd = accept(server_fd, (struct sockaddr *)&address1, &address_size);
   //reading data from client
   valread=read(client_fd,buffer,1024-1);
   printf("%s\n",buffer);
   close(client_fd);
   close(server_fd);
   
  //---------------------------------Initializations done------------------------------//


}
