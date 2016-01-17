#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�жϵ������Ƿ��л�

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

	ptail->pnext=phead;  // ��β�ڵ��ͷ��� �������� ��Ϊһ���� 
	list_judge_is_hoop(phead,k);

	//list_print(phead);
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

// �жϵ������Ƿ��л�
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
		printf("����������ǻ�");
	}else
	{
		printf("����������ǻ�");
	}
}