#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

char  file[] = "this is the test file io exaple,TangYiwen vs tsinghua .";

char buf[128] = {"0"};
int main(void)
{
	int  fd1,ret;
	char * file_name = "tang.txt";
	fd1 = open(file_name,O_WRONLY | O_CREAT ,0x777);

	if(fd1 <0)
	{
		printf("open %s is failed,error is %s\n",file_name, strerror(errno));
		return -1;
	}
	ret = write(fd1,file,sizeof(file));
	if(ret <0)
	{
		printf("write file is failed \r\n");
		return -1;
	}

	printf("write the contain is :%s\r\n",file);

	fsync(fd1);
	close(fd1);

	fd1 = open(file_name,O_RDONLY);
	if(fd1 <0)
	{
		printf("open is failed\r\n");
		return -1;
	}
	ret = read(fd1,buf,sizeof(file)-2);
	if(ret <0)
	{
		printf("read is failed\r\n");
		return -1;
	}
	printf("buf is %s\r\n",buf);
	close(fd1);
	return 0;
}



