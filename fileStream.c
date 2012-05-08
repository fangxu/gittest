#include<stdio.h>
#define SIZE 65536 //64kb   stream buff
#define LENGTH 1024 //1kb read length

int main()
{
	char buf[SIZE]={0};
	int l=0;
	for(;l<SIZE;l++)
		buf[l]='U';
	FILE *fp;
	fp=fopen("testFileStream","rw+");//file exists
	if(fp != NULL)
		puts("open file stream successfully.");
	else
	{
		perror("open file");
		return 1;
	}
	
	fwrite(buf,LENGTH,SIZE/LENGTH,fp);  //fwrite and fread
	fflush(fp);
	
	fread(buf,10,2,fp);
	for(l=0;l<10*2;l++)
		putchar(buf[l]);
	putchar('\n');
	
	if(fclose(fp) != -1)
		puts("close file");
	else
	{
		perror("close file");
		return 1;
	}
	
	fp = fopen("testFileStream0","rw+");   //fprintf and fscanf
	fprintf(fp,"<name>%s <ID>%d <address>%s","Tom",18,"hdu");
	close(fp);
	fp= fopen("testFileStream0","rw+");
	int ID;
	char name[60],address[60];
	fscanf(fp,"<name>%s <ID>%d <address>%s",name,&ID,address);
	printf("%s %d %s\n",name,ID,address);
	close(fp);
	return 0;
}
