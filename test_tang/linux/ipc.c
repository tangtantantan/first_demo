/*system -V 消息队列

特点：1.独立于进程
	      2.没有文件名和文件描述符
	      3.IPC对象具有key和ID
*/

/*
消息队列用法
1.定义一个唯一的key，对IPC对象进行标示
调用ftok函数获得一个key，
key_t  ftok(const char * path,int  proj_id)   
          path :      一个合法的路径  
	  proj_id：一个整数
返回值：合法键值

注：发送进程和接受进程都要调用  ftok  函数，那么为了保持产生的key一致，就需要函数的参数是一样的


2.构造消息对象
msgget函数获取一个消息队列
int msgget(key_t  key,int msgflg);
key:          消息队列的键值
msgflg：IPC_CREAT  如果消息队列不存在，则创建
mode：访问权限，在创建一个新的消息队列时，需要指定他的访问权限

返回值：该消息队列的id

3.发送特定类型的消息
msgsnd(int msqid ,
                 const void * msgp,
		 size_t msgsz,
		 int msgflg)

msqid  :消息队列的ID
msgp：指向消息缓存区的指针
struct msgbuf{

	long  mtype;  //消息标识
	char  ntext[1];
}

msgsz :	  消息队列正文的字节数
msgflg ：IPC_NOWAIT   非阻塞发送             就算消息队列满了，马上返回，不阻塞当前线程
		    0                           阻塞发送                 当发送队列满了，就阻塞当前线程

成功：返回0，失败返回-1



4.从消息队列读取数据
ssize_t  msgrcv(int msgid,
				void * msgp,
				size_t msgsz,
				long msgtyp,
				int msgflg)


msgid :      消息队列ID
msgp ：    消息缓存区
msgsz ：   消息正文的字节数
msgtyp ： 要接受消息的标识
msgflg ：   IPC_NOWAIT           非阻塞获取
		      MSG_NOERROR    截断消息
		       0  ： 阻塞获取

返回值 ：0  成功
		   -1 失败



5.删除消息队列  或者设置消息队列的相关属性
msgctl(int msgid,
		int  cmd，
		struct  maqid_ds * buf)


msgid :      消息队列的id
cmd    ：   

*/



#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

//  #define  send
#define  buf_size   512

typedef struct  msg{
	int msg_type;
	char  msg_text[buf_size];
}msg ;

msg  send_msg;

#ifdef   send
int main(void)
{
	int qid;
	key_t    key = ftok("/home/tangyiwen/test_tang/linux/temp",100);

	qid  =  msgget( key,IPC_CREAT|0666);

	if(qid <0)
	{
		printf("creat msg id is failed\r\n");
		return -1;
	}

	printf("the ipc msg id is %d\r\n",qid);

	while(1)
	{
		if ((fgets(send_msg.msg_text, buf_size, stdin)) == NULL)
		{
			puts("no message");
			exit(-3);
		}

		send_msg.msg_type = getpid();
		
		/* send data*/
		if(msgsnd(qid , &send_msg,sizeof(send_msg.msg_text),0)<0)
		{
			printf("add msg is failed\r\n");
			return -2;
		}

		if(strncmp(send_msg.msg_text,"quit",4) == 0)
		{
			printf("exit\r\n");
			break;
		}
	}
	return 0;
}
#else


int main(void)
{
	int qid;
	key_t    key = ftok("/home/tangyiwen/test_tang/linux/temp",100);

	qid  =  msgget( key,IPC_CREAT|0666);

	if(qid <0)
	{
		printf("creat msg id is failed\r\n");
		return -1;
	}

	printf("the ipc msg id is %d\r\n",qid);

	do{

		memset(send_msg.msg_text,0,buf_size);
		
		/* read data*/
		if(msgrcv(qid , (void *)&send_msg,buf_size,0,0) < 0)
		{
			printf("receive msg is failed\r\n");
			return -2;
		}
		printf("the receive is :%s\r\n",send_msg.msg_text);

	}while(strncmp(send_msg.msg_text,"quit",4) != 0);
	

	if(msgctl(qid,IPC_RMID,NULL)<0)
	{
		perror("msgrcv\r\n");
		exit(-3);
	}
	return 0;
}

#endif
