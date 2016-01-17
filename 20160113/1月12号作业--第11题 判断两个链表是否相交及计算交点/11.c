#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// �ж����������Ƿ��ཻ���Լ����㽻��: list1:1 2 3 4 5 6 7 8 9, list2:12 13�ӵ�list1��һ����
// ����������1. һ��while��һ��for�������Ⱦ����ཻ
//2.������������ĳ��ȣ�d=L1-L2, ��������d�����ȣ�Ȼ��ͬʱ�����ֵ��ͬ����¼��λ�ã�˵���ཻ

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
	// ��һ���������ӵ���һ����
	pcur1=phead1;
	pcur1=pcur1->pnext->pnext;
	ptail2->pnext=pcur1;
	ptail2=ptail1;

	printf("the second list is:\n");
	list_print(phead2);

	list_judge_intersect(phead1,phead2);
	
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

//�ж������Ƿ��ཻ������ཻ������ڵ�
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