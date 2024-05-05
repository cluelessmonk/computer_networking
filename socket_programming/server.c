// Server side C program to demonstrate Socket
// programming
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080
int main()
{
        //file descriptor of server socket and newly accepted socket connection  
	int server_fd, client_fd;
	//size of the  value to be read by the socket 
	ssize_t valread;
	//Struct to hold server address information 
	struct sockaddr_in address;
	//variable to store the length of the address
	socklen_t addrlen = sizeof(address);
	//character array to store the nessage from client
	char buffer[1024] = { 0 };
	char* hello = "Hello from server";
	

	// Creating socket file descriptor
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	

	
	// Now filling the details in the address struct that was previously made to store the socket data.
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	// Forcefully attaching socket to the port 8080
	bind(server_fd, (struct sockaddr*)&address,
			sizeof(address));
	//listen for connection
	listen(server_fd, 3);
	//accepting new connection using accept system call
	client_fd
		= accept(server_fd, (struct sockaddr*)&address,
				&addrlen)
	//reading data using valread size and storing the data in buffer			
	valread = read(client_fd, buffer,
				1024 - 1); // subtract 1 for the null
							// terminator at the end
	printf("%s\n", buffer);
	//sending message back to the client
	send(client_fd, hello, strlen(hello), 0);
	printf("Hello message sent\n");

	// closing the connected socket
	close(client_fd);
	// closing the listening socket
	close(server_fd);
	return 0;
}

