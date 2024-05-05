#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main(int argc ,char* argv[]){

int sfd;
int port = atoi(argv[2]);
char* ip = argv[1];

struct sockaddr_in my_addr;
sfd = socket(AF_INET,SOCK_STREAM,0);

memset(&my_addr,0,sizeof(my_addr));
my_addr.sin_family = AF_INET;
my_addr.sin_addr.s_addr = INADDR_ANY;
my_addr.sin_port = htons(port);
connect(sfd,(struct sockaddr *)&my_addr,sizeof(my_addr));
//----------------_Data sening and recieving-------------------------------//


//first
printf("Enter first number--\n");
char first[10];
fgets(first,sizeof(first),stdin);
ssize_t firstwritten = write(sfd,first,sizeof(first));

//second
printf("Enter second number--\n");
char second[10];
fgets(second,sizeof(second),stdin);
ssize_t secondwritten = write(sfd,second,sizeof(second));

//exp
printf("Enter expresion\n");
char expr[10];
fgets(expr,sizeof(expr),stdin);
ssize_t exprwritten = write(sfd,expr,sizeof(expr));


//data result from server
char buffer[100];

ssize_t dataans = read(sfd,buffer,sizeof(buffer));
buffer[dataans]='\0';
printf("Ans recieved from client is -- %s \n",buffer);


close(sfd);













}
