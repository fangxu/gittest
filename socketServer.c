#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
	int server_sockfd,client_sockfd;
	int server_len,client_len;
	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	server_sockfd=socket(AF_INET,SOCK_STREAM,0);
	server_address.sin_family=AF_INET;
	server_address.sin_addr.s_addr=inet_addr("127.0.0.1");
	server_address.sin_port=9734;
	server_len=sizeof(server_address);
	bind(server_sockfd,(struct sockaddr *)&server_address,server_len);
	listen(server_sockfd,5);
	
	while(1)
	{
		char ch;
		char s[200];
		int recvbyte;
		printf("wait for message\n");
		client_len=sizeof(client_address);
		client_sockfd=accept(server_sockfd,(struct sockaddr *)&client_address,(socklen_t *__restrict)&client_len);
		//while(read(client_sockfd,&ch,1)!=0)
		//{
		//	putchar(ch);
		//}
		recvbyte=recv(client_sockfd,s,1, 0);
		//s[recvbyte]='\n';
		printf("%s\n",s);
		//ch++;
		//write(client_sockfd,&ch,1);
		close(client_sockfd);
	}
}
