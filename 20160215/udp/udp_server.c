#include "func.h"

int main(int argc, char* argv[])
{
	int sfd=socket(AF_INET,SOCK_DGRAM,0);//socket初始化 ，udp通信
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}

	struct sockaddr_in server;  // 结构体赋值
	bzero(&server,sizeof(server));
	server.sin_family=AF_INET;
	server.sin_port=htons(atoi(argv[2]));
	server.sin_addr.s_addr=inet_addr(argv[1]);
	int ret;

	ret=bind(sfd,(struct sockaddr *)&server,sizeof(struct sockaddr));  // bind
	if(-1==ret)
	{
		perror("bind");
		return -1;
	}
	printf("bind ok\n");
	char buf[128];
	bzero(buf,sizeof(buf));
	struct sockaddr_in client;
	bzero(&client,sizeof(client));
	int clen=sizeof(struct sockaddr);
	ret=recvfrom(sfd,buf,sizeof(buf),0,(struct sockaddr *)&client,&clen);//如果没有客户端，这里会卡住，记录client的信息
	if(-1==ret)
	{
		perror("recvfrom");
		return -1;
	}
	printf("i am server i recvfrom %s\n",buf);
	printf("IP=%s,PORT=%d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));// 打印的是之前记录的client的信息
	ret=sendto(sfd,"i am server",11,0,(struct sockaddr *)&client,sizeof(struct sockaddr));// 再发送，向client发送"i am server"
	if(-1==ret)
	{
		perror("sendto");
		return -1;	
	}
	close(sfd);
	return 0;
}
