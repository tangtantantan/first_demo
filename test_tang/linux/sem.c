#include <sys/sem.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/sem.h>
/*
int semget(key_t key, int nsems, int semflg);

key  :健值
nsems： 信号量的初始值，就是想要产生信号的数量
semflg：
		IPC_CREAT   信号量不存在则
		mode               信号量的读写权限
成功：返回信号量的id
失败：-1


//初始化信号量、或者设置信号量的属性
int semctl(int semid, int semnum, int cmd, ...);

semid ：信号量id
semnum ：信号量的编号
cmd      ：
                IPC_RMID:从系统中删除该信号量集合。
		IPC_STAT:获取此信号量集合的 semid_ds 结构,存放在第四个参数的 buf 中
		IPC_SET:通过第四个参数的 buf 来设定信号量集相关联的 semid_ds 中信号量集合权限为 sem_perm 中的 uid,gid,mode
		SETVAL:设置第 semnum 个信号量的值,该值由第四个参数中的 val 指定



int semop(int semid, struct sembuf *sops, size_t nsops)

semid: 信号量id
sops ：信号量操作结构提数组
nsops ： 信号量的数量

struct sembuf
{
	unsigned short int sem_num;     // 信号量的序号从 0 ~ nsems-1 
	short int sem_op;                             //对信号量的操作,>0, 0, <0 
	short int sem_flg;                             //操作标识:0, IPC_WAIT, SEM_UNDO 
};

*/






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




union semun {
	int   val;
	/* Value for SETVAL */
	struct semid_ds *buf; /* Buffer for IPC_STAT, IPC_SET */
	unsigned short *array; /* Array for GETALL, SETALL */
	struct seminfo *__buf; /* Buffer for IPC_INFO
	(Linux-specific) */
};
/* 信号量初始化(赋值)函数 */
int sem_init(int sem_id, int init_value)
{
	union semun sem_union;
	sem_union.val = init_value; /* init_value 为初始值 */

	if (semctl(sem_id, 0, SETVAL, sem_union) == -1)
	{
		perror("Initialize semaphore");
		return -1;
	}
	return 0;
}

/* 从系统中删除信号量的函数 */
int sem_del(int sem_id)
{
	union semun sem_union;
	if (semctl(sem_id, 0, IPC_RMID, sem_union) == -1)
	{
		perror("Delete semaphore");
		return -1;
	}
}

/* P 操作函数 */
int sem_p(int sem_id)
{
	struct sembuf sops;
	sops.sem_num = 0; /* 单个信号量的编号应该为 0 */
	sops.sem_op = -1; /* 表示 P 操作 */
	sops.sem_flg = SEM_UNDO; /* 系统自动释放将会在系统中残留的信号量 */

	if (semop(sem_id, &sops, 1) == -1)
	{
		perror("P operation");
		return -1;
	}

	return 0;
}


/* V 操作函数 */
int sem_v(int sem_id)
{
	struct sembuf sops;
	sops.sem_num = 0; /* 单个信号量的编号应该为 0 */
	sops.sem_op = 1; /* 表示 V 操作 */
	sops.sem_flg = SEM_UNDO; /* 在进程退出时，系统自动释放将会在系统中残留的信号量 */

	if (semop(sem_id, &sops, 1) == -1)
	{
		perror("V operation");
		return -1;
	}
	return 0;
}


int main(void)
{
	int qid;
	key_t    key = ftok("/home/tangyiwen/test_tang/linux/temp",100);

	qid  =  semget( key,IPC_CREAT|0666);



	return 0;
}

#endif
