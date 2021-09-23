#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t sem1,sem2 ;
sem_t  * sem_read = &sem1;
sem_t  * sem_write = &sem2;
char com[20] = {0};
pthread_t thread_read ,thread_write;




void *fun(void *arg)
{    
	  pthread_t tid;
	while(1)    
	 {
		  tid = pthread_self();	
		  printf("tid is %ld\r\n",tid);
		sem_wait(sem_write);
		memset(com,0,20);
		fgets(com,19,stdin);
		if(strncmp("quit",com,4) == 0)
		{
			printf("quit the process\r\n");
			exit(0);
		}
		sem_post(sem_read);
		printf("read is ok\r\n");
	}

}

int main()
{
	//要先创建无名信号量
        int  ret = sem_init(sem_read,0,0);                   //信号量结构体指针   进程内的线程通信    初始值为0
	if(ret !=0)
	{
		perror("error:");
		exit(-1);
	}

	   ret = sem_init(sem_write,0,1);                   //信号量结构体指针   进程内的线程通信    初始值为1
	if(ret !=0)
	{
		perror("error:");
		exit(-1);
	}
	//再创建一个文件


	//再创建线程
	 ret = pthread_create(&thread_read,NULL,fun,NULL);//创建线程。成功返回0，失败返回错误码   
	/*线程对象，线程id
	    制定线程属性，一般为null使用默认属性
	    线程函数
	    线程函数的输入参数
         */

	if(ret <0)
	{
		perror("creat thread is failed");
		exit(-3);
	}
        pthread_t tid;
         char buf[20] = {0};
	while(1)
	{	 tid = pthread_self();	
	         printf("tid is %ld\r\n",tid);
		sem_wait(sem_read);
		strncpy(buf,com,19);
		printf("read is: %s\r\n",buf);
		sem_post(sem_write);
		printf("111 id ok\r\n");
	}
	return 0;
}