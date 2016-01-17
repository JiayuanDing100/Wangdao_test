#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 将一个链表逆序过来
//定义结构体
typedef struct student{
	int num;
	struct student* pnext;
}stud,*pstud;

//声明函数
void list_tail_insert(pstud*,pstud*,int);
void list_print(pstud);
void list_count_node(pstud,pstud,int*);
void list_inverse(pstud*,int);
void list_recursive_print(pstud);

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
	//list_count_node(phead,ptail,&k);
	list_recursive_print(phead);
	//list_print(phead);
	//printf("%d",k);

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

//递归打印  不能从最后一个打印，递归却可以
void list_recursive_print(pstud phead)
{
	pstud pcur;
	pcur=phead;
	if(pcur->pnext = NULL)
	{
		printf("%d ",pcur->num);
	}else
	{
		list_recursive_print(pcur->pnext);
		printf("%d",pcur->num);
	}
}