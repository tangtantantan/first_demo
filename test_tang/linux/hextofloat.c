#include<stdio.h>
//要注意字节序的问题，这个都是网站

int  main(void)
{
	unsigned char a[4] = {0x40,0x20,0x00,0x00};
	unsigned char b[4] = {0x00,0x00,0x20,0x40};
	unsigned char c[4] = {0x50,0x83,0xc8,0x42};

	printf("float is %f",*(float * )a);
	printf("float is %f",*(float * )b);
	printf("float is %f",*(float * )c);
	return 0;
}