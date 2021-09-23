#ifdef Exit
/*
进程的退出有三种方式
从mian函数的return           遇到main中的return  系统帮我们调用exit()
调用exit()函数终止
调用_exit()函数终止
*/

/*
exit()函数           会先看看当前进程有没有IO缓存区，有的话就先处理IO缓存区的数据，然后才退出
_exit()函数         不管当前进程有没有IO缓存区，就直接退出
*/


#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>


int main(void)
{
	pid_t ret;
	ret = fork();
	if(ret == -1)
	{
		printf("the process creat is failed\n");
	}else if(ret == 0)
	{
		printf("this is parent process");   //按照上面的分析，这一句不会打印出来
		_exit(0);
	}else
	{
		printf("this is a child process");//按照上面的分析，这一句会打印出来
		exit(0);
	}
}

#endif


#ifdef   WAIT
/*
子进程要将自己的退出状态报告给父进程，父进程是如何获取子进程的退出状态呢
wait函数
*/

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

int  main()
{
	pid_t ret;
	int status;
	ret = fork();
	if(-1 == ret)
	{
		printf("error\r\n");
	}else if (ret == 0)
	{
		printf("son\r\n");
		exit(123);
	}else
	{
		wait(&status);
		if(WIFEXITED(status) == 1)       //如果子进程正常退出，则该宏为真
		 	printf("exit value :%d\r\n",WEXITSTATUS(status));    //如果子程序正常退出，该宏获取子进程的退出值
		return 0;
	}
}

#endif