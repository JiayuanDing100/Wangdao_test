#include "fun.h"
// ǰ���β�����룬�������
//
//void main(int argc,char* argv[])
//{
//	/*printf("the argc is %d\n",argc);
//	printf("the argv[0] is %s\n",argv[0]);
//	printf("the argv[1] is %s\n",argv[1]);
//*/
//	pstud phead, ptail;
//	int i;
//	phead =NULL;
//	ptail=NULL;
//	while(fflush(stdin),scanf("%d",&i)!=EOF)
//	{
//		list_tail_insert(&phead,&ptail,i); // β������
//	}
//	list_print(phead);
//	// �������
//	i=10;
//	list_order_insert(&phead,&ptail,i);  // ���Ҫ˳����������Ͱ����з���β����������
//	list_print(phead);
//	system("pause");
//
//}
//

// ɾ���ڵ�
void main(int argc,char* argv[])
{

	pstud phead, ptail;
	int i;
	phead =NULL;
	ptail=NULL;
	while(scanf("%d",&i)!=EOF)
	{
		list_order_insert(&phead,&ptail,i); 
	}
	list_print(phead);
	
	//list_delete(&phead,&ptail,10);
	//list_search(phead,10);
	list_modify(phead,5,10);

	list_print(phead);
	system("pause");

}