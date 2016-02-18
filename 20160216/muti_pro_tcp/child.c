#include "head.h"

void make_child(pchild cptr,int n)
{
	int i;
	int fds[2];
	int ret;
	int pid;
	for(i=0;i<n;i++)
	{
		ret=socketpair(AF_LOCAL,SOCK_STREAM,0,fds);
		if(-1==ret)
		{
			perror("socketpair");
			return;
		}
		pid=fork();
		if(0==pid)
		{
			close(fds[1]);
			child_handle(fds[0]);
		}
		close(fds[0]);
		cptr[i].pid=pid;
		cptr[i].fds=fds[1]; 
		cptr[i].busy=0;
		/*
		cptr[i].pid=pid;
		cptr[i].fds[0]=fds[0];
		cptr[i].fds[1]=fds[1];
		cptr[i].busy=0;
		*/
	}
}


void child_handle(int fdr)
{
	int fd;
	int flag=1;
	while(1)
	{
		recv_fd(fdr,&fd); // 如果父进程没有发过来，就在这里睡觉
		send_file(fd);  // 发送完文件内容
		write(fdr,&flag,4); //发送1给主进程
	}	
}

void send_file(int sfd)
{
	int ret;
	data_t buf; // 要发送的结构体名字叫buf,buf包含成员长度len，buf[1000]
	buf.len=strlen(DOWN_FILE); // "file" 这个名字的长度就是4 ，“wangdao”就是7,这里的buf.len 就是buf.buf的长度
	strcpy(buf.buf,DOWN_FILE);  //copy the name of the file
                                  	
	ret=send(sfd,&buf,buf.len+4,0);  //发送文件名（4代表的是结构体的int len，为什么不包含char数组，因为可以从前面开始数，后面都是0，就不要了，所以不用传）
	if(-1==ret)
	{
		perror("send1");
		return;
	}
	int fd=open(DOWN_FILE,O_RDONLY);
	if(-1==fd)
	{
		perror("open");
		return;	
	}
	while(bzero(&buf,sizeof(buf)),(buf.len=read(fd,buf.buf,sizeof(buf.buf)))>0)
	{
		send_n(sfd,(char*)&buf,buf.len+4);		
	}
	bzero(&buf,sizeof(buf));
	int flag=0;
	buf.len=sizeof(int);
	memcpy(buf.buf,&flag,4);  // 把flag的地址发给buf.buf ？？？？
	send(sfd,&buf,buf.len+4,0); // 发送结束符
	close(sfd);
	return;
}
