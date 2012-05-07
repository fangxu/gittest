#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#define LENGTH 200

int main()
{
	char c[LENGTH];
	int f,i;
	puts("input some words to write:");
	if((i=read(0,c,LENGTH))<1)
	{
		puts("read failed");
		return 1;
	}
	f=open("testFile",O_RDWR|O_CREAT,0664);
	if(f != -1)
	{
		if(write(f,c,i)!=i)
			perror("write failed");
		puts("save successfully");
		close(f);
	}
	else
		perror("open file");
}
