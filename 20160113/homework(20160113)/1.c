#include <stdio.h>
#include <stdlib.h>
#include "string.h"
// ftell函数
typedef struct student{
	int num;
	char name[20];
	float score;
}stud,*pstud;

void func_gets(FILE*);
void func_puts(FILE*);
void func_fscanf(FILE*,pstud);
void func_fprintf(FILE*,pstud);
void main(int argc,char* argv[])
{
	FILE* fp;
	char c[10];
	stud st1;
	if(argc!=2)
	{
		printf("error args\n");
		return;
	}

	fp=fopen(argv[1],"r+");

	if(fp==NULL)
	{
		perror("fopen1");
		return;
	}
	//func_gets(fp);
	/*memset(c,0,sizeof(c));
	fread(c,sizeof(char),5,fp);
	printf("the position is %d\n",ftell(fp));*/
	func_fscanf(fp,&st1);
	func_fprintf(fp,&st1);
	fclose(fp);
	system("pause");

}

// fgets 和 fputs函数
// 从文本中按行读取数据
void func_gets(FILE* fp)
{
	char c[100];
	memset(c,0,sizeof(c));
	//func_puts(fp);
	fgets(c,sizeof(c),fp);  // 读一行出来
	printf("%s\n",c);
}

// 从开头开始加进去数据
void func_puts(FILE* fp)
{
	int i;
	i=fputs("hello",fp);
	if(i==EOF)
	{
		perror("fputs");
	}
	fflush(fp);
}

// 从文本中格式化读取数据
void func_fscanf(FILE* fp,pstud st1)
{
	int i;
	memset(st1,0,sizeof(stud));
	i=fscanf(fp,"%d%s%f",&st1->num,st1->name,&st1->score); // 读取之后，指针自动偏移到后面
	if(i==3)
	{
		printf("num=%d,name=%s,score=%f\n",st1->num,st1->name,st1->score);
	}
}

// 输出到文件里面
void func_fprintf(FILE* fp,pstud st1)
{
	st1->num = st1->num+1;
	fputc('\n',fp);
	fprintf(fp,"%d %s %2.1f",st1->num,st1->name,st1->score);
	fflush(fp);
}