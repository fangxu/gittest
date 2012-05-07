#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
	int f;
	const char *f_path = "testFile";
	mode_t f_attrib;
	f_attrib = S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH;
	f = open(f_path,O_RDONLY);
	if(f == -1)
	{
		f = open(f_path,O_RDWR|O_CREAT,f_attrib);
		if(f != -1)
			puts("Creat a new file");
		else
		{
			puts("Can't creat new file,exit.");
			return 1;
		}
	}
	else
		puts("Open successfully");
	close(f);
	return 0;
}
