#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ��һ�������������
//����ṹ��
typedef struct student{
	int num;
	struct student* pnext;
}stud,*pstud;

//��������
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

// β�巨��������
void list_tail_insert(pstud* phead,pstud* ptail,int num)
{
	pstud pcur;
	pcur=(pstud)malloc(sizeof(stud));
	pcur->num= num;
	pcur->pnext=NULL;
	if(*ptail==NULL)  //˵��ԭ�����ǿսڵ㣬����Ľڵ��ǵ�һ���ڵ� 
	{
		*phead=pcur;
		*ptail=pcur;
	}else{
		(*ptail)->pnext=pcur; // ��ԭ���������β���ڵ��pnextָ�����ڵĲ���Ľ�ڵ�
		(*ptail)=pcur;// ��ǰ�ڵ���β��
	}
}

// ��ӡ����
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


// ���������ж��ٸ��ڵ�
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

//�ݹ��ӡ  ���ܴ����һ����ӡ���ݹ�ȴ����
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