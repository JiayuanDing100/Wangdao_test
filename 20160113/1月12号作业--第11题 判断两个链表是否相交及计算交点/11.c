#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// 判断两个链表是否相交，以及计算交点: list1:1 2 3 4 5 6 7 8 9, list2:12 13接到list1的一个点
// 两个方法：1. 一个while，一个for，如果相等就是相交
//2.计算两个链表的长度，d=L1-L2, 长的先走d个长度，然后同时如果有值相同，记录下位置，说明相交

typedef struct student{
	int num;
	struct student* pnext;
}stud,*pstud;

void list_tail_insert(pstud*,pstud*,int);
void list_print(pstud);
void list_count_node(pstud phead,int* );
void list_judge_intersect(pstud,pstud);


void main(int argc,char* argv[])
{
	pstud pcur1,phead1,ptail1,phead2,ptail2;
	int i,k;
	phead1 = NULL;
	ptail1 = NULL;
	phead2 = NULL;
	ptail2 = NULL;
	while(scanf("%d",&i) != EOF)
	{
		list_tail_insert(&phead1,&ptail1,i);
	}
	printf("the first list is:\n");
	list_print(phead1);

	while(scanf("%d",&i) != EOF)
	{
		list_tail_insert(&phead2,&ptail2,i);
	}
	// 将一条链表连接到另一条上
	pcur1=phead1;
	pcur1=pcur1->pnext->pnext;
	ptail2->pnext=pcur1;
	ptail2=ptail1;

	printf("the second list is:\n");
	list_print(phead2);

	list_judge_intersect(phead1,phead2);
	
}


// 尾插法新增链表
void list_tail_insert(pstud* phead,pstud* ptail,int num)
{
	pstud pcur;
	pcur=(pstud)malloc(sizeof(stud));
	pcur->num= num;
	pcur->pnext=NULL;
	if(*ptail==NULL)  //说明原来的是空节点，插入的节点是第一个节点 
	{
		*phead=pcur;
		*ptail=pcur;
	}else{
		(*ptail)->pnext=pcur; // 将原来的链表的尾部节点的pnext指向现在的插入的界节点
		(*ptail)=pcur;// 当前节点变成尾部
	}
}

// 打印链表
void list_print(pstud phead)
{
	pstud pcur;
	pcur= phead;
	while(pcur!=NULL)
	{
		printf("%3d",pcur->num);
		pcur=pcur->pnext;
	}
	printf("\n");
}

// 计算链表有多少个节点
void list_count_node(pstud phead,int* k)
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

//判断链表是否相交，如果相交，计算节点
void list_judge_intersect(pstud phead1,pstud phead2)
{
	int i,d,L1,L2;
	pstud pcur1,pcur2;
	pcur1=phead1;
	pcur2=phead2;
	list_count_node(phead1,&L1);
	list_count_node(phead2,&L2);
	d=abs(L1-L2);
	if(L1>L2)
	{
		for(i=0;i<d;i++)
		{
			pcur1=pcur1->pnext;
		}

	}else
	{
		for(i=0;i<d;i++)
		{
			pcur2=pcur2->pnext;
		}
	}

	while(pcur1->pnext != NULL)
	{
		pcur1=pcur1->pnext;
		pcur2=pcur2->pnext;
		if(pcur1==pcur2)
		{
			printf("the two lists intersect!\n");
			printf("the intersection is:%d\n",pcur1->num);
			break;
		}
	}
}