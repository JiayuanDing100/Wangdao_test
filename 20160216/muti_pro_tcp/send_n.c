#include "head.h"

void send_n(int sfd,char* p,int len)
{
	int total=0;
	int size=0;
	while(total<len) // 为什么要反复的发送？因为对方的缓冲区可能就只有100，发送太快，来不及接收
	{
		size=send(sfd,p+total,len-total,0);
		total=total+size;
	}
}
