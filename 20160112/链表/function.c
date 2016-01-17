#include "fun.h"

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

//�������
void list_order_insert(pstud* phead,pstud* ptail,int num)
{
	pstud pnew,pcur,ppre;
	pnew=(pstud)malloc(sizeof(stud));
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

// ����ȷɾ��
void list_delete(pstud* phead, pstud* ptail,int num)
{
	pstud pcur,ppre;
	pcur=*phead;
	if(pcur==NULL)  // ������
	{
		printf("the list is NULL\n");
		return;  // ֱ�Ӻ�������
	}
	if(pcur->num = num)  //�ǵ�һ���ڵ㱻ɾ��
	{
		*phead=pcur->pnext;
		free(pcur);
		pcur=NULL;
		if(*phead == NULL)   // �����������ֻ��һ���ڵ㣬��ɾ�ˣ����ǿ������� 
		{
			*ptail=NULL;
		}
		return;
	}
	while(pcur!= NULL) // ɾ���м��β��
	{
		if(pcur->num == num)
		{
			ppre->pnext = pcur->pnext;  //pcur ���Ǳ�ɾ���ģ�ppre��pcur֮ǰ���Ǹ��ڵ�
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

// ��������
void list_search(pstud phead,int num)
{
	pstud pcur; // ����һ��ָ�� ��������
	pcur= phead;
	while(pcur != NULL)
	{
		if(pcur->num == num)
		{
			printf("find value %d\n",pcur->num);
			return; //����ֱ�ӷ���
		}
		pcur =pcur->pnext;
	}
	if(pcur== NULL)
	{
		printf("this num does not exist\n");
	}
}

// �����޸�
void list_modify(pstud phead,int mpre,int mlate)
{
	pstud pcur; // ����һ��ָ�� ��������
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
			// return; //ע�͸þ䣬�޸����е�
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