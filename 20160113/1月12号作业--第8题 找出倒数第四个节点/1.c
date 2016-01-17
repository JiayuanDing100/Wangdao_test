#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �������ĵ��ĸ��ڵ�

// ����ṹ��
typedef struct student{
	int num;
	struct student* pnext;
}stud,*pstud;

//��������
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
	// ���ж�node �ĸ���
	list_count_node(phead,ptail,&k);// kΪ�ڵ�ĸ���
	if(k<4)
	{
		printf("the number of nodes is less than 4!\n");
	}else
	{
		t=list_locate_node(phead,ptail,4);
	}

	printf("������4���ڵ�Ϊ%d\n",t);

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

//��λ�����ڼ���node
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
