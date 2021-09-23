/*进程在运行过程中，可以通过三种方式来获取运行环境的环境变量

1.通过main()函数的第三个参数获取，main()函数原型有三种：

int main();                                                                       // 原型 1 
int main(int argc, char *argv[]);                            //原型 2 
int main(int argc, char *argv[], char *env[]);   //原型 3 


2.通过 environ 全局变量来获取

3. 通过 getenv() 函数来获取
*/

/*
(1)通过 main()函数的第 3 个参数 env 获取。main()的原型的第三个参数为环境变量
字符串的指针数组,数组最后一个元素为 NULL。程序清单 12.1 通过 env 参数获取进程的
所有环境变量。

#include <stdio.h>

int main(int argc, char * argv[], char *env[]) {
	int i = 0;
	while (env[i])
	puts(env[i++]);
	return 0;
}



(2)通过 environ 全局变量获取。在加载进程的时候,系统会为每一个进程复制一份
系统环境变量副本,并保存在全局变量 environ 中。如程序清单 12.2 所示代码是通过 environ
参数获取进程所有环境变量的范例。

#include <stdio.h>

extern char ** environ;

int main(int argc, char * argv[]) {
	int i = 0;
	while (environ[i])
	puts(environ[i++]);
	return 0;
}


(3)通过 getenv()函数获取。 Linux 系统提供 getenv()、 setenv()等函数来操作环境变量,
getenv()函数的原型如下:

#include <stdlib.h>
char *getenv(const char *name);

char* env;
env = getenv("HOME");
*/