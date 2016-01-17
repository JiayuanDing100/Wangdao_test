#include "fun.h"
// 前面的尾部插入，有序插入
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
//		list_tail_insert(&phead,&ptail,i); // 尾部插入
//	}
//	list_print(phead);
//	// 有序插入
//	i=10;
//	list_order_insert(&phead,&ptail,i);  // 如果要顺序输出来，就把这行放在尾部插入那行
//	list_print(phead);
//	system("pause");
//
//}
//

// 删除节点
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