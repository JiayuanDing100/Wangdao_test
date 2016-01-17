#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 输出链表的中间节点

// 定义结构体
typedef struct student{
	int num;
	struct student* pnext;
}stud,*pstud;

//声明函数
void list_tail_insert(pstud*,pstud*,int);
void list_print(pstud);
void list_count_node(pstud,pstud,int*);
int list_locate_node(pstud,pstud,int,int);


void main(int argc, char* argv[])
{
	pstud phead,ptail;
	int i,t,k;
	int a[2]={0};
	phead=NULL;
	ptail=NULL;
	while(scanf("%d",&i) != EOF)
	{
		list_tail_insert(&phead,&ptail,i);
	}
	
	list_count_node(phead,ptail,&k);// k为节点的个数
	t=list_locate_node(phead,ptail,k,a);
	if(k%2 != 0)
	{
		printf("中间的数为：%d\n",a[0]);
	}else
	{
		printf("中间的数为：%d和%d\n",a[0],a[1]);
	}
}


// 尾插法插入节点
void list_tail_insert(pstud* phead,pstud* ptail,int i) //ptail和 phead都是二级指针   
{
	pstud pcur;
	pcur=(pstud)malloc(sizeof(stud));  // 为什么要给pcur动态分配内存，phead和ptail不用
	pcur->num=i;
	pcur->pnext=NULL;
	if(*ptail == NULL)
	{
		*phead = pcur;
		*ptail = pcur;
	}else{
		(*ptail)->pnext=pcur;
		*ptail=pcur;
	}
}

// 打印链表
void list_print(pstud phead)
{
	pstud pcur;
	pcur=phead;
	while(pcur != NULL)
	{
		printf("%3d",pcur->num);
		pcur=pcur->pnext;
	}
	printf("\n");
}

// 计算链表几个k节点
void list_count_node(pstud phead,pstud ptail,int* k)
{
	pstud pcur;
	pcur=phead;
	(*k)=0;
	while(pcur != NULL)
	{
		pcur=pcur->pnext;
		(*k)++;
	}
}

//定位中间的node
int list_locate_node(pstud phead,pstud ptail,int k,int a[])
{
	int i;
	pstud pcur,pfront;
	pfront=phead;
	if((k%2)!=0)
	{
		for(i=1;i<=(k/2)+1;i++)
		{
			pfront=pfront->pnext;
		}
	}else
	{
		for(i=1;i<=(k/2)+1;i++)
		{
			pfront=pfront->pnext;
		}
	}
	pcur=phead;
	while(pfront != NULL)
	{
		pfront=pfront->pnext;
		pcur=pcur->pnext;
	}
	if(k%2 != 0)
	{
		a[0]=pcur->num;
	}else
	{
		a[0]=pcur->num;
		a[1]=(pcur->pnext)->num;
	}
}
