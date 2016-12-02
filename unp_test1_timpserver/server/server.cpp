#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>


const static int MAXLINE = 4096;

#define SA struct sockaddr

int main()
{
	std::cout<<"server start"<<std::endl;
	struct sockaddr_in servaddr;
	char buff[MAXLINE];

	time_t ticks;

	int listenfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(12345);

	bind(listenfd, (SA*)&servaddr, sizeof(servaddr));

	listen(listenfd, 1024);

	while(1)
	{
		int connfd = accept(listenfd, (SA*)NULL, NULL);

		printf("connfd: %d\n", connfd);

		ticks = time(NULL);

		snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
		write(connfd, buff, strlen(buff));
		close(connfd);
	}
	
	return 0;
}
