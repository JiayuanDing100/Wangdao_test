#include "func.h"

void recv_n(int sfd,char*p,int len)
{
	int total;
	int size=0;
	while(total<len)
	{
		size=send(sfd,p+total,len-total,0);
		total=total+size;
	}
}
