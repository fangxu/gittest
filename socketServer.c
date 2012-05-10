#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> /* for struct sockaddr_in*/

#define BACKLOG 10
#define MYPORT  4000

int main()
{
	char *addr;
	int sockfd;
	int new_fd;
	struct sockaddr_in my_addr, their_addr;

	int res;
	int sin_size;

	char *buf;
	/* 取得套接字描述符*/
	sockfd = socket(AF_INET,     /* domain*/
					SOCK_STREAM, /* type*/
					0);          /* protocol*/

	if (sockfd == -1) 
	{
		perror("socket");
		exit(1);
	}

	/* Init sockaddr_in */
	my_addr.sin_family = AF_INET;                /* 注意: 应使用主机字节顺序*/
	my_addr.sin_port = htons(MYPORT);            /* 注意: 应使用网络字节顺序*/
	my_addr.sin_addr.s_addr = htonl(INADDR_ANY); /* 使用自己的 IP 地址 */
	bzero(&(my_addr.sin_zero), 8);               /* 结构的其余的部分须置 0*/

	/* 指定一个套接字使用的地址及端口*/
	res = bind(sockfd, (struct sockaddr*)&my_addr, sizeof(struct sockaddr));
	if (res == -1) 
	{
		perror("bind");
		exit(1);
	}

	/* 监听请求, 等待连接*/
	res = listen(sockfd,
				BACKLOG);  /* 未经处理的连接请求队列可容纳的最大数目*/               
	if (res == -1) {
		perror("listen");
		exit(1);
	}

	/* 接受对方的连接请求, 建立连接，返回一个新的连接描述符.
	* 而第一个套接字描述符仍在你的机器上原来的端口 listen()
	*/
	sin_size = sizeof(struct sockaddr_in);
	new_fd = accept(sockfd, (void *)&their_addr, &sin_size);

	buf = (char *)malloc(255);
	if (buf == NULL) {
		printf("malloc failed\n");
		exit(1);
	}

	/* 接受对方发来的数据*/
	res = recv(new_fd, buf, 255, 0);
	if (res == -1) {
		perror("recv()");
		exit(1);
	}

	/* 关闭本次连接*/
	close(new_fd);

	/* 关闭系统监听*/
	close(sockfd);

	printf("recv data:%s\n", buf);
	free(buf);
	return 0;
}
