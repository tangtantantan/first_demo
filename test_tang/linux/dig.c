#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>
/*
信号被屏蔽，则记录在未处理信号集中，
信号（1-31）：非实时信号，不排队，只保留一个
信号（34-64）：实时信号，排队，保留全部
*/

void  my_fun(int sifno)
{
	printf("hello\n");
	sleep(3);
	printf("world\n");
}



int main(void)
{
	// signal(SIGINT,my_fun);  
	 //使用小于31的信号，只保留一次  使用 Ctrl+c  触发软中断
        //执行现象：无论触发几次软中断，只执行1次my_fun函数
	//退出方式  ： ctrl + 反斜杠     



	signal(35,my_fun);               //触发方式，在另一个终端中输入 ：   kill  -35    本进程的pid    
	//退出方式  ： ctrl + 反斜杠     
	//执行现象：出发几次软中断，执行几次my_fun函数
	printf("my name is tang yiwen\n");  //会被执行，上面的signal函数只是注册一下软中断，注册完之后照原来程序的顺序继续执行
	while(1);
	return 0;
}