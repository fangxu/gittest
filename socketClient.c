#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
	int sockfd,len;
	struct sockaddr_in address;
	int result;
	char ch='A';
	char *ss="adf";
	char s[100];
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	address.sin_family=AF_INET;
	address.sin_addr.s_addr=inet_addr("127.0.0.1");
	address.sin_port=9734;
	len=sizeof(address);
	result=connect(sockfd,(struct sockaddr *)&address,len);
	
	if(result==-1)
	{
		perror("fialed");
		return 1;
	}
	//write(sockfd,&ch,1);
	//read(sockfd,&ch,1);
	//printf("feedback message:%c\n",ch);
	//close(sockfd);
	//return 0;
	
	
		
		//scanf("%s",s);
		//result=strlen(s);
		send(sockfd,ss,3,0);
		printf("send message\n");
		
	
	close(sockfd);
}
