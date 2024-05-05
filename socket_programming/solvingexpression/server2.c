#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>


int main(int argc ,char* argv[]){

int sfd,cfd;
int port = atoi(argv[1]);
socklen_t addr_len;
struct sockaddr_in my_addr,peer_addr;

sfd = socket(AF_INET,SOCK_STREAM,0);

memset(&my_addr,0,sizeof(my_addr));
my_addr.sin_family = AF_INET;
my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
my_addr.sin_port = htons(port);

bind(sfd,(struct sockaddr *)&my_addr,sizeof(my_addr));

listen(sfd,3);

addr_len = sizeof(peer_addr);
while(1){
cfd = accept(sfd,(struct sockaddr *)&peer_addr,&addr_len);

//----------------------------------Data sending and recieving starts here-------------------------//

pid_t pid = fork();
if(pid==0){ 
close(sfd);
char buffer1[10]; 
ssize_t bytesread1 = read(cfd, buffer1,sizeof(buffer1));
buffer1[bytesread1] = '\0';
printf("Read first number waiting for second\n");
int first = atoi(buffer1);

char buffer2[10]; 
ssize_t bytesread2 = read(cfd, buffer2,sizeof(buffer2));
buffer2[bytesread2] = '\0';
printf("Read second number waiting for expression\n");



int second = atoi(buffer2);

char buffer3[10]; 
ssize_t bytesread3 = read(cfd, buffer3,sizeof(buffer3));
printf("Read  expression\n");
char exp = buffer3[0];

int ans;
if(exp=='+'){
ans = first+second;


}
else if(exp=='-'){

ans = first-second;

}
else if(exp=='*'){
ans = first*second;
}
else{

ans=first/second;
}


char ansdata[1024];

sprintf(ansdata,"%d",ans);


printf("the final answer bieng sent to client is -- %d",ans);

ssize_t byteswrite = write(cfd, ansdata ,sizeof(ansdata));
close(cfd);
exit(0);
}
else if(pid<0){

perror("fork");
close(cfd);

}
else{

close(cfd);
}


}





 








return 0;

}



