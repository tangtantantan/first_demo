/*本例是一个二分查找
#include<stdio.h>
#include<strings.h>
#include<stdlib.h>

int  bin(int x)
{
	int index = -1,l = 0,r = x;
	while(l<=r)
	{
		int mid =l + ((r- l)>>1);
		if(mid *mid <= x)             //查找的条件
		{
			index = mid;
			l = mid + 1;
		}else{
			r = mid -1;
		}
	}
	return index; 
}

int main(int argc, char **argv)
{
	int input ,num;
	if(argc != 2)
	{
		printf("the para is error\r\n");
		return -1;
	}

	 input = atoi(argv[1]);

        num = bin(input);
	printf("the input is %d,output is %d\r\n",input,num);
	return 0;
}


*/







/*
牛顿迭代法
具体想法，对于求x的根值，如12的根值

1 × 12 
2 × 6
3 ×4
4 ×3
6 ×2

   x/n = n   一般(x/n + n)/2  会更接近  根号12    ,求出的值 k = (x/n + n)/2  可能不是很好的结果，那就将 k 带入上面式子，继续计算
   m = (k + x/k)/2    直到   k = x/k
*/

#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
float  newton(int num)
{
	float k ,nums =(float) num;
	k = (nums+1)/2;

	while(k -(nums/k)  >0.001)
	{
		k = (nums/k + k)/2;
	}

	return k;
}


int main(int argc, char **argv)
{
	int input;
        float num;
	if(argc != 2)
	{
		printf("the para is error\r\n");
		return -1;
	}

	 input = atoi(argv[1]);

        num = newton(input);
	printf("the input is %d,output is %f\r\n",input,num);
	return 0;
}








/*

gdb调试

编译时要添加 -g选项

输入   cgdb                                             编出的可执行文件

输入： b   main                                    在main函数上打断点

输入 ： n                                                 将程序执行下一步

输入 ： p  变量名                                 可以打印变量名

输入 ： s                                                 进入函数内部

输入  ： p   p                                         查看函数输入参数

*/