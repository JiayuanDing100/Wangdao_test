#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 将一个链表拆分（奇数位置上的节点构成一个链表，偶数位置上的节点构成另外一个链表）

// 定义结构体
typedef struct student{
	int num;
	struct student* pnext;
}stud,*pstud;

//声明函数
void list_tail_insert(pstud*,pstud*,int);
void list_print(pstud);
void list_split(pstud,pstud);

void main(int argc, char* argv[])
{
	pstud phead,ptail,phead1;
	int i;
	phead=NULL;
	ptail=NULL;
	while(scanf("%d",&i) != EOF)
	{
		list_tail_insert(&phead,&ptail,i);
	}
	list_print(phead);
	phead1=phead->pnext;   
	list_split(phead,phead1);
	list_print(phead);
	list_print(phead1);
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

//拆分链表
void list_split(pstud phead,pstud phead1)
{
	int i;
	pstud p1,p2;
	p1=phead;
	p2=phead1;
	for(i=1;(p1->pnext!=NULL) && (p2->pnext != NULL);i++)
	{
		if(i%2 != 0)
		{
			p1->pnext=p2->pnext;
			p1=p2->pnext;	
		}else
		{
			p2->pnext=p1->pnext;
			p2=p1->pnext;	
		}
	}
	p1->pnext=NULL;
	p2->pnext=NULL;
}