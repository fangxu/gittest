#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> /*for struct sockaddr_in*/
#include<stdio.h>

#define DEST_IP   "127.0.0.1"
#define DEST_PORT 4000

int main()
{
	int res;
	int sockfd;
	struct sockaddr_in dest_addr;

	char *msg ;
	int len, bytes_sent;

	/* 取得一个套接字*/
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) 
	{
		perror("socket()");
		exit(1);
	}

	/* 设置远程连接的信息*/
	dest_addr.sin_family = AF_INET;                 /* 注意主机字节顺序*/
	dest_addr.sin_port = htons(DEST_PORT);          /* 远程连接端口, 注意网络字节顺序*/
	dest_addr.sin_addr.s_addr = inet_addr(DEST_IP); /* 远程 IP 地址, inet_addr() 会返回网络字节顺序*/
	bzero(&(dest_addr.sin_zero), 8);                /* 其余结构须置 0*/

	/* 连接远程主机，出错返回 -1*/
	res = connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr_in));
	if (res == -1) 
	{
		perror("connect()");
		exit(1);
	}
	scanf("%s",msg);
	len = strlen(msg);
	bytes_sent = send(sockfd, /* 连接描述符*/
						msg,    /* 发送内容*/
						len,    /* 发关内容长度*/
						0);     /* 发送标记, 一般置 0*/
  

	/* 关闭连接*/
	close(sockfd);
	return 0;
}
