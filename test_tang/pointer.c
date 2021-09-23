#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>


 char * a[3] = {
	"nihaohahahh",
	"dfdjhfjdhfjksdhfkjsd",
	"ddddddddddddddd"
};

int main(void)
{
	printf("the a[0] is %s\r\n",a[0]);
	printf("a[0] lenth is %d\r\n",strlen(a[0]));
	sleep(2);

	printf("the a[1] is %s\r\n",a[1]);
	sleep(2);

	printf("the a[2] is %s\r\n",a[2]);
	sleep(2);
	return 0; 
}