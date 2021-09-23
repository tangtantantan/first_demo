#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>


#define maxfile  3

int main()
{
	pid_t pid;
	int fd,len,i,num,times = 100;
	char *buf = "this is dameon\n";

	len = strlen(buf) + 1;
	/*1.创建子进程，销毁父进程*/
	pid = fork();
	if(pid < 0)
	{
		printf("fork is failed\n");
		exit(1);
	}

	if(pid > 0)
	{
		exit(0);
	}
       /*2.创建新会话，摆脱终端的影响 */
	setsid();

	/*3.改变当前工作目录*/
	chdir("/");

	/*4.重设文件权限掩码*/
	umask(0);

	/*5.关闭默认文件描述符*/
	for(i = 0; i<maxfile;i++)
	{
		close(i);
	}
	/*6.实现守护进程的功能*/

	while(times)
	{
		fd = open("/tang.txt",O_CREAT| O_WRONLY |O_APPEND ,0666);
		write(fd,buf,len);
		close(fd);
		sleep(10);
		times = times -10;
	}
}

