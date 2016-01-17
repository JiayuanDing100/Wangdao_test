#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
	int num;
	struct student* pnext;
}stud,*pstud;

void list_tail_insert(pstud*,pstud*,int);
void list_order_insert(pstud*,pstud*,int);
void list_delete(pstud*,pstud*,int);
void list_search(pstud,int);
void list_modify(pstud,int,int);
void list_print(pstud);
