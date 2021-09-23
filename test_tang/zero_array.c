#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef  struct  zero
{
	int len;
	char a[0];
}zero;

int main()
{
	zero b;
	printf("the len is :%ld\r\n",sizeof(b));
	zero * c = (zero *)malloc(sizeof(zero)+20);
	strcpy(c->a,"nihao!!!\r\n");
	puts(c->a);
	
	return 0;
}