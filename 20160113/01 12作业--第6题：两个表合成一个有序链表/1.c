#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//将两个有序的链表 合成一个有序的链表

// 定义结构体
typedef struct student{
	int num;
	struct student* pnext;
}stud,*pstud;

// 声明函数
void list_order_insert(pstud*,pstud*,int);
void list_print(pstud);
void list_joint(pstud*,pstud*,pstud*,pstud*);
void list_order(pstud*,pstud*);

void main(int argc,char* argv[])
{
	pstud phead1,ptail1,phead2,ptail2;
	int i;
	phead1=NULL;
	ptail1=NULL;
	phead2=NULL;
	ptail2=NULL;
	//获得第一个链表
	while(scanf("%d",&i) != EOF)
	{
		list_order_insert(&phead1,&ptail1,i); 
	}
	printf("the first list:\n");
	list_print(phead1);
	// 获得第二个链表
	while(scanf("%d",&i) != EOF)
	{
		list_order_insert(&phead2,&ptail2,i); 
	}
	printf("the second list:\n");
	list_print(phead2);
	list_joint(&phead1,&ptail1,&phead2,&ptail2);
	list_order(&phead1,&ptail1);
	list_print(phead1);
}

//有序插入
void list_order_insert(pstud* phead,pstud* ptail,int num)
{
	pstud pnew,pcur,ppre;
	pnew=(pstud)malloc(sizeof(stud));  // pnew 需要存东西
	pnew->num = num;
	pnew->pnext = NULL;
	ppre = NULL;
	pcur = *phead;

	if(pcur == NULL)  //链表为空
	{
		*phead = pnew;
		*ptail = pnew;
	}else if(pcur->num > num)  //插入头部
	{
		pnew->pnext = pcur;
		*phead = pnew;
	}else{  
		while( pcur != NULL) //插入中间
		{
			if( pcur->num > num)
			{
				ppre->pnext = pnew;
				pnew->pnext = pcur;
				break;
			}
			ppre = pcur;
			pcur = pcur->pnext;
		}
		if(pcur == NULL)  //插入链表尾部
		{
			(*ptail)->pnext = pnew;
			*ptail = pnew;  //改变尾节点
		}
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

//将两个链表链接起来
void list_joint(pstud* phead1,pstud* ptail1,pstud* phead2,pstud* ptail2)
{
	(*ptail1)->pnext=*phead2;
	*ptail1=*ptail2;
}

// 将一个链表按照某一个变量排序 ************这个排序只是把一个变量的值交换了，其他的都没改变**************************
void list_order(pstud* phead1,pstud* ptail1)
{
	pstud pcur,pfront;
	int tmp;
	pcur=*phead1;
	while(pcur !=	NULL	)
	{
		pfront = pcur->pnext;
		while(pfront != NULL)
		{
			if((pcur->num) > (pfront->num))
			{
				tmp=pcur->num;
				pcur->num=pfront->num;
				pfront->num=tmp;
			}
			pfront=pfront->pnext;
		}
		pcur=pcur->pnext;
	}
}