#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

#include <unistd.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include "client.h"

//#include "unp.h"

const static char addr[] = "192.168.1.131";
const static int MAXLINE = 4096;

#define SA struct sockaddr

int main()
{
	std::cout<<"client start"<<std::endl;
	
	char recvline[MAXLINE + 1];
	struct sockaddr_in servaddr;
	
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		std::cout<<"error"<<std::endl;
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(12345);
	
	inet_pton(AF_INET, addr, (SA*)&servaddr.sin_addr);

	bool conRes = connect(sockfd, (SA*)&servaddr, sizeof(servaddr));
	if(conRes < 0)
	{
		std::cout<<"connect error"<<std::endl;		
	}
	
	int n = 0;
	while(1)
	{
		n = read(sockfd, recvline, sizeof(recvline));
		if(n <= 0)break;
		recvline[n] = 0;
		if(fputs(recvline, stdout) == EOF)
		{
			std::cout<<"fputs error"<<std::endl;
		}

	}
	if(n<0)std::cout<<"read error"<<std::endl;

	return 0;
}
