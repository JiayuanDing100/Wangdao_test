#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 输出链表的第四个节点

// 定义结构体
typedef struct student{
	int num;
	struct student* pnext;
}stud,*pstud;

//声明函数
void list_tail_insert(pstud*,pstud*,int);
void list_print(pstud);
void list_count_node(pstud,pstud,int*);
int list_locate_node(pstud,pstud,int);


void main(int argc, char* argv[])
{
	pstud phead,ptail;
	int i,t,k;
	phead=NULL;
	ptail=NULL;
	while(scanf("%d",&i) != EOF)
	{
		list_tail_insert(&phead,&ptail,i);
	}
	// 先判断node 的个数
	list_count_node(phead,ptail,&k);// k为节点的个数
	if(k<4)
	{
		printf("the number of nodes is less than 4!\n");
	}else
	{
		t=list_locate_node(phead,ptail,4);
	}

	printf("倒数第4个节点为%d\n",t);

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

//定位倒数第几个node
int list_locate_node(pstud phead,pstud ptail,int k)
{
	int i;
	pstud pcur,pfront;
	pfront=phead;
	for(i=1;i<=k;i++)
	{
		pfront=pfront->pnext;
	}
	pcur=phead;
	while(pfront != NULL)
	{
		pfront=pfront->pnext;
		pcur=pcur->pnext;
	}
	return (pcur->num);
}
