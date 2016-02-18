#include "head.h"
//进程池
int main(int argc,char* argv[])
{
	if(argc!=4)
	{
		printf("error args\n");
		return -1;
	}
	pchild cptr;
	int num=atoi(argv[3]);//传入的是字符5 不是数字5，所以这里需要转换
	cptr=(pchild)calloc(num,sizeof(child));   //cptr points to init address,there are num childs
	make_child(cptr,num);
	
	//socket
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
	listen(sfd,num);

	//epoll
	int epfd;
	epfd=epoll_create(1);
	if(-1==epfd)
	{
		perror("epoll_create");
		return -1;
	}
	struct epoll_event ev,*evs;
	evs=(struct epoll_event*)calloc(num+1,sizeof(struct epoll_event));  // evs points to init address,there are num+1 evs.
	ev.events=EPOLLIN;
	ev.data.fd=sfd;
	ret=epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&ev);  //监视socket描述符sfd
	if(-1==ret)
	{	
		perror("epoll_ctl");
		return -1;
	}
	int i;
	for(i=0;i<num;i++)
	{
		ev.events=EPOLLIN;  
		ev.data.fd=cptr[i].fds;  // fds[0],fds[1] are defined in cptr,
		ret=epoll_ctl(epfd,EPOLL_CTL_ADD,cptr[i].fds,&ev);
		if(-1==ret)
		{
			perror("epoll_ctl");
			return -1;
		}
	}
	int size;
	int flag;
	int j;
	int new_fd;
	while(1)
	{
		ret=epoll_wait(epfd,evs,num+1,-1);
		if(ret>0)
		{
			for(i=0;i<ret;i++)
			{
				if(evs[i].data.fd==sfd && evs[i].events==EPOLLIN)
				{
					new_fd=accept(sfd,NULL,NULL);
					if(-1==new_fd)
					{
						perror("accept");
						return -1;
					}
					printf("one client connect,new_fd is %d\n",new_fd);
					for(j=0;j<num;j++)
					{
						if(cptr[j].busy==0)
						{
							break;
						}
					}
					if(j!=num)
					{
						send_fd(cptr[j].fds,new_fd);
						cptr[j].busy=1;
						printf("child %d is busy\n",j);
					}
				}
				for(j=0;j<num;j++)
				{
					if(evs[i].data.fd==cptr[j].fds && evs[i].events==EPOLLIN)
					{
						size=read(cptr[j].fds,&flag,4);
						printf("the size is %d\n",size);
						cptr[j].busy=0;
						printf("child %d is not busy\n",j);
					}
				}
			}
		}
	}
	return 0;

}
