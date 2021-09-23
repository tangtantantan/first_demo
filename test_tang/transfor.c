#include<stdio.h>
unsigned char  a[4]={0x00,0x00,0x80,0x40};

int main(void)
{
	
	printf("the float is %f\n", *(float *)a);
	return 0;
}