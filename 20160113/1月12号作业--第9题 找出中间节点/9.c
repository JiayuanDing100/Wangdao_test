#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���������м�ڵ�

// ����ṹ��
typedef struct student{
	int num;
	struct student* pnext;
}stud,*pstud;

//��������
void list_tail_insert(pstud*,pstud*,int);
void list_print(pstud);
void list_count_node(pstud,pstud,int*);
int list_locate_node(pstud,pstud,int,int);


void main(int argc, char* argv[])
{
	pstud phead,ptail;
	int i,t,k;
	int a[2]={0};
	phead=NULL;
	ptail=NULL;
	while(scanf("%d",&i) != EOF)
	{
		list_tail_insert(&phead,&ptail,i);
	}
	
	list_count_node(phead,ptail,&k);// kΪ�ڵ�ĸ���
	t=list_locate_node(phead,ptail,k,a);
	if(k%2 != 0)
	{
		printf("�м����Ϊ��%d\n",a[0]);
	}else
	{
		printf("�м����Ϊ��%d��%d\n",a[0],a[1]);
	}
}


// β�巨����ڵ�
void list_tail_insert(pstud* phead,pstud* ptail,int i) //ptail�� phead���Ƕ���ָ��   
{
	pstud pcur;
	pcur=(pstud)malloc(sizeof(stud));  // ΪʲôҪ��pcur��̬�����ڴ棬phead��ptail����
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

// ��ӡ����
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

// ����������k�ڵ�
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

//��λ�м��node
int list_locate_node(pstud phead,pstud ptail,int k,int a[])
{
	int i;
	pstud pcur,pfront;
	pfront=phead;
	if((k%2)!=0)
	{
		for(i=1;i<=(k/2)+1;i++)
		{
			pfront=pfront->pnext;
		}
	}else
	{
		for(i=1;i<=(k/2)+1;i++)
		{
			pfront=pfront->pnext;
		}
	}
	pcur=phead;
	while(pfront != NULL)
	{
		pfront=pfront->pnext;
		pcur=pcur->pnext;
	}
	if(k%2 != 0)
	{
		a[0]=pcur->num;
	}else
	{
		a[0]=pcur->num;
		a[1]=(pcur->pnext)->num;
	}
}
