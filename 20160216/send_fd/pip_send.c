#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("error args\n");
		return -1;
	}
	int fds[2]; //fds 2个文件描述符
	pipe(fds); // create two pipes
	if(!fork())  // fork is 0,child; 1 ,parent
	{
		close(fds[1]); //child: close write 
		int fd;
		read(fds[0],&fd,4); // 从读文件描述符中读取parent中fd的地址赋给fd，那么获得fd的值，但是这里仅仅传递的是fd的值
		printf("i am child, fd is %d\n",fd);
		char buf[10]={0};
		int ret;
		ret=read(fd,buf,sizeof(buf));
		if(-1==ret)
		{
			perror("read");
			return -1;
		}
		printf("buf is %s\n",buf); // 从child读取buf内容，读不了，但是可以在parent中读
		exit(0);
	}else{
		close(fds[0]); // parent:close read
		int fd=open(argv[1],O_RDWR); // open返回新的文件描述符
		if(-1==fd)
		{
			perror("open");
			return -1;
		}
		printf("i am parent,fd is %d\n",fd);
		write(fds[1],&fd,4); // 把fd是int型，把fd的地址（ 4个字节）写到文件描述符fds中
		wait(NULL);
		exit(0);
	}
}
