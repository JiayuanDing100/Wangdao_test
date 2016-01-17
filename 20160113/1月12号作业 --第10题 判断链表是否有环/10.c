#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//判断单链表是否有环

typedef struct student{
	int num;
	struct student* pnext;
}stud,*pstud;

void list_tail_insert(pstud*,pstud*,int);
void list_print(pstud);
void list_count_node(pstud phead,int* );
void list_judge_is_hoop(pstud,int);


void main(int argc,char* argv[])
{
	pstud phead,ptail;
	int i,k;
	phead = NULL;
	ptail = NULL;
	while(scanf("%d",&i) != EOF)
	{
		list_tail_insert(&phead,&ptail,i);
	}
	list_count_node(phead,&k);

	ptail->pnext=phead;  // 将尾节点和头结点 链接起来 成为一个环 
	list_judge_is_hoop(phead,k);

	//list_print(phead);
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

// 判断单链表是否有环
void list_judge_is_hoop(pstud phead,int k)
{
	int i;
	pstud p1,p2;
	p1=phead;
	p2=phead;
	
	for(i=1;i<k-1;i++)
	{   p2=p2->pnext;
		
		p1=p1->pnext;
		if(p1->pnext == NULL)
			break;
		p1=p1->pnext;
		if(p1->pnext == NULL)
			break;
		p1=p1->pnext;
		if(p1->pnext == NULL)
			break;
	}
	if(p1->pnext==NULL)
	{
		printf("这个单链表不是环");
	}else
	{
		printf("这个单链表是环");
	}
}