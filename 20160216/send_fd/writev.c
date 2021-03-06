#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("error args\n");
		return -1;
	}
	int fd=open(argv[1],O_RDWR);
	char buf1[10]="hello ";
	char buf2[10]="world";
	struct iovec iov[2];
	iov[0].iov_base=buf1;
	iov[0].iov_len=5;
	iov[1].iov_base=buf2;
	iov[1].iov_len=5;
	int ret=writev(fd,iov,2); // 一次能够同时向fd文件描述符写两个字符串
	if(-1==ret)
	{
		perror("writev");
		return -1;
	}
	close(fd);
	return 0;
	
}
