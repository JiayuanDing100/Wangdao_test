#include <stdio.h>
#include <stdlib.h>

//  π”√fread£¨fwrite
void main(int argc,char* argv[])
{
	FILE *fp;
	int a[10];
	if(argc!=2)
	{
		printf("error args\n");
	}
	fp=fopen(argv[1],"w+");
	if(fp==NULL)
	{
		perror("fopen1");
		return;
	}
}