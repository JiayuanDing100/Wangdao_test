#include "fun.h"

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

//有序插入
void list_order_insert(pstud* phead,pstud* ptail,int num)
{
	pstud pnew,pcur,ppre;
	pnew=(pstud)malloc(sizeof(stud));
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

// 链表精确删除
void list_delete(pstud* phead, pstud* ptail,int num)
{
	pstud pcur,ppre;
	pcur=*phead;
	if(pcur==NULL)  // 空链表
	{
		printf("the list is NULL\n");
		return;  // 直接函数结束
	}
	if(pcur->num = num)  //是第一个节点被删除
	{
		*phead=pcur->pnext;
		free(pcur);
		pcur=NULL;
		if(*phead == NULL)   // 而且这个链表只有一个节点，被删了，就是空链表了 
		{
			*ptail=NULL;
		}
		return;
	}
	while(pcur!= NULL) // 删除中间和尾部
	{
		if(pcur->num == num)
		{
			ppre->pnext = pcur->pnext;  //pcur 就是被删除的，ppre是pcur之前的那个节点
			if(pcur->pnext == NULL)
			{
				*ptail=ppre;
			}
			free(pcur);
			pcur=NULL;
			return;
		}
		ppre = pcur;
		pcur = pcur->pnext;
	}
}

// 链表搜索
void list_search(pstud phead,int num)
{
	pstud pcur; // 定义一个指针 遍历查找
	pcur= phead;
	while(pcur != NULL)
	{
		if(pcur->num == num)
		{
			printf("find value %d\n",pcur->num);
			return; //函数直接返回
		}
		pcur =pcur->pnext;
	}
	if(pcur== NULL)
	{
		printf("this num does not exist\n");
	}
}

// 链表修改
void list_modify(pstud phead,int mpre,int mlate)
{
	pstud pcur; // 定义一个指针 遍历查找
	int flag=0;
	pcur= phead;
	if(pcur== NULL)
	{
		printf("the list NULL\n");
		return;
	}
	while(pcur != NULL)
	{
		if(pcur->num == mpre)
		{
			pcur->num=mlate;
			flag++;
			// return; //注释该句，修改所有的
		}
		pcur =pcur->pnext;
	}
	if(flag>0)
	{
		printf("modify %d count \n",flag);
	}else{
		printf("this value does not exist.\n");
	}
}