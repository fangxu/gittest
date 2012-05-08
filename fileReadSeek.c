#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#define LENGTH 200

int main()
{
	int f,j=0;
	char c[LENGTH];
	f=open("testFile",O_RDONLY,0664);
	lseek(f,2,SEEK_SET);
	int i = read(f,c,2);
	for(;i>0;i--)
		putchar(c[j++]);
	putchar('\n');
	close(f);
	return 0;
}
