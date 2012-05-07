#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#define LENGTH 200

int main()
{
	char c[LENGTH];
	int f,i,j=0;
	f = open("testFile",O_RDONLY,LENGTH);
	if(f != -1)
	{
		i = read(f,c,LENGTH);
		if(i>0)
		{
			for(;i>0;i--)
				putchar(c[j++]);
		}
		else
			perror("read");
	}
	else
		perror("open file");
	return 0;
}
