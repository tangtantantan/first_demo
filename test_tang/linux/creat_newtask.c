//用fork函数新建一个进程
//fork会返回两次，一个是子进程的PID，父进程返回的，另外一个返回0，子进程返回的
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
//使用fork创建父进程副本
void fork_task(void)
{
	pid_t i;
	printf("this is a fork funtion test\n");
	i = fork();
	if(0 == i)                                             //父进程
	{
		printf("this is child  process\r\n");
	}
	else if(i > 0)                                     //子进程
	{
		printf("this is father process\r\n");
	}else                                                  //创建失败
	{
		printf("creat process is failed\r\n");
	}
}


/*创建一个与父进程逻辑不一样的进程
*  exec函数有以下几个  
*  l    代表以列表形式传参                                             int  execl(const char * path,const char *arg  ,...)
*  v   代表以矢量数组形式传参                                    int  execlp(const char * path,const char *arg  ,...)
*  p   使用环境变量path 来寻找执行文件                int  execv(const char * path, char *const argv[ ])
*  e   用户提供自定义的环境变量                               int  execve(const char * path, char * const argv[ ]  ,char * const envp[ ])
*/
void  exec_task(void)
{
	pid_t ret;
	ret = fork();
	if(ret > 0 )
	{
		execl("main",0,NULL);
		printf("creat  new task is failed\r\n");
	}else if(ret == 0)
	{
		sleep(1);
		printf("this is parent process\r\n");
	}
	
}

int main(void)
{
        exec_task();
	return 0;
}