#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//��������������� �ϳ�һ�����������

// ����ṹ��
typedef struct student{
	int num;
	struct student* pnext;
}stud,*pstud;

// ��������
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
	//��õ�һ������
	while(scanf("%d",&i) != EOF)
	{
		list_order_insert(&phead1,&ptail1,i); 
	}
	printf("the first list:\n");
	list_print(phead1);
	// ��õڶ�������
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

//�������
void list_order_insert(pstud* phead,pstud* ptail,int num)
{
	pstud pnew,pcur,ppre;
	pnew=(pstud)malloc(sizeof(stud));  // pnew ��Ҫ�涫��
	pnew->num = num;
	pnew->pnext = NULL;
	ppre = NULL;
	pcur = *phead;

	if(pcur == NULL)  //����Ϊ��
	{
		*phead = pnew;
		*ptail = pnew;
	}else if(pcur->num > num)  //����ͷ��
	{
		pnew->pnext = pcur;
		*phead = pnew;
	}else{  
		while( pcur != NULL) //�����м�
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
		if(pcur == NULL)  //��������β��
		{
			(*ptail)->pnext = pnew;
			*ptail = pnew;  //�ı�β�ڵ�
		}
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

//������������������
void list_joint(pstud* phead1,pstud* ptail1,pstud* phead2,pstud* ptail2)
{
	(*ptail1)->pnext=*phead2;
	*ptail1=*ptail2;
}

// ��һ��������ĳһ���������� ************�������ֻ�ǰ�һ��������ֵ�����ˣ������Ķ�û�ı�**************************
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