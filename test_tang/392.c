#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
//判断s是否为t的子序列
bool isSubsequence(char * s, char * t){
	int _s = 0;
	int _t = 0;
	if(s == NULL || t == NULL)
	{
		printf("input is wrong\r\n");
		return false;
	}

     while(s[_s] != '\0')
     {
	   if( t[_t] != s[_s]) 
	   {
		   _t ++;
		   if( t[_t] == '\0')
		        return false;
	   }else
	   {
		   _t++;
		   _s++;
	   }
     }
    return true;
}

int main()
{
	char s[] = "dskjsd";
	char t[] = "djsd";

	bool ret  = isSubsequence(s,t);

	printf("ret is %d",ret );
	return 0;
}