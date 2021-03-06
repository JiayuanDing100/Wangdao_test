#include "func.h"
#define NUM 10

void change_nonblock(int* fd)
{
	int status;
	status=fcntl(*fd,F_GETFL);
	status=status|O_NONBLOCK;
	int ret;
	ret=fcntl(*fd,F_SETFL,status);
	if(0!= ret)
	{
		perror("fcntl");
		return;
	}
}

int main(int argc,char* argv[])
{
	if(argc != 3)
	{
		printf("error args\n");
		return -1;
	}

	int sfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in ser;
	bzero(&ser,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(atoi(argv[2]));
	ser.sin_addr.s_addr=inet_addr(argv[1]);
	int ret;
	ret=bind(sfd,(struct sockaddr *)&ser,sizeof(struct sockaddr));
	if(-1==ret)
	{	
		perror("bind");
		return -1;
	}	
	listen(sfd,NUM);
	int epfd;
	epfd=epoll_create(1);
	if(-1==epfd)
	{	
		perror("epoll_create");
		return -1;
	}
	
	struct epoll_event ev,evs[3];
	ev.events=EPOLLIN;
	ev.data.fd=sfd;
	ret=epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&ev);//把sfd加入注册列表
	if(-1==ret)
	{
		perror("epoll_ctl1");
		return -1;
	}

	ev.events=EPOLLIN;
	ev.data.fd=0;
	ret=epoll_ctl(epfd,EPOLL_CTL_ADD,0,&ev);
	if(-1==ret)
	{
		perror("epoll_ctl2");
		return -1;
	}

	int i;
	int new_fd=0;
	char buf[128];
	int size;
	while(1)
	{
		bzero(evs,sizeof(evs));
		ret=epoll_wait(epfd,evs,3,-1);
		if(ret>0)
		{
			for(i=0;i<ret;i++)
			{
				if(evs[i].data.fd == sfd && evs[i].events == EPOLLIN)
				{
					new_fd=accept(sfd,NULL,NULL);
					if(-1==new_fd)
					{
						perror("accept");
						return -1;
					}
					change_nonblock(&new_fd);
					ev.events=EPOLLIN|EPOLLET;
					ev.data.fd=new_fd;
					epoll_ctl(epfd,EPOLL_CTL_ADD,new_fd,&ev);
				}
				if(new_fd>0)
				{
					if(evs[i].data.fd == 0 && evs[i].events==EPOLLIN)
					{
						bzero(buf,sizeof(buf));
						read(0,buf,sizeof(buf));
						size=send(new_fd,buf,strlen(buf)-1,0);
						if(-1==size)
						{	
							perror("send");
							return -1;
						}
					}
					if(evs[i].data.fd == new_fd && evs[i].events==EPOLLIN)
					{
						while(1)
						{
							bzero(buf,sizeof(buf));
							size=recv(new_fd,buf,5,0);
							if(size>0)
							{
								printf("%s",buf);
							}else if(size==-1){
								break;
								
							}else{
								ev.events=EPOLLIN;
								ev.data.fd=new_fd;
								epoll_ctl(epfd,EPOLL_CTL_DEL,new_fd,&ev);
								new_fd=0;
							}
						}
						printf("\n");
					}	
				}
			}
		}
	
	}
	close(sfd);
	return 0;
}
