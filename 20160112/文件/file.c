#include <stdio.h>
#include <stdlib.h>

void main(int argc,char* argv[])
{
	FILE *fp; // �ļ�ָ��
	char c;
	if(argc != 2) // ������ļ��Ͷ���������
	{
		printf("the arg is wrong\n");
		return;
	}

	fp=fopen(argv[1],"r+");
	if(fp==NULL)
	{
		perror("fopen1");
	}else{
		printf("open success\n");
	}

	do{
		c=fgetc(fp);
		putchar(c);
	}while(c!=EOF);


	//fputc('3',fp);  // ���ַ���1��д��ȥ
	//fputc('1',fp);
	//fflush(fp);
	
	/*c=fgetc(fp);
	printf("the c is %c\n",c);
	c=fgetc(fp);
	printf("the c is %c\n",c);*/
	fclose(fp);
	system("pause");
}