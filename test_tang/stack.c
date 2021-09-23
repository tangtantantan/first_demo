#include <stdio.h>
#include<string.h>

#define  MaxSize    20
typedef  struct SNode * Stack;
struct SNode{
	int Data[MaxSize];
	unsigned int  top;
};



//入栈操作
void  Push(Stack  ptr,int item)
{
	if(NULL == ptr || ptr->top >= MaxSize)
	{
		printf("the stack is full\n");
		return ;
	}
	 ptr->Data[ptr->top] = item;
	 ptr->top++;
}

//出栈操作
int  Pop(Stack  ptr)
{
	int ret = 0;
	if(NULL == ptr || ptr->top == 0)
	{
		printf("the stack is Empty\n");
		return  0;
	}
	ptr->top--;
	ret = ptr->Data[ptr->top];
	return ret;
}


int  main(void)
{
	int a= 15,b = 13,c =12, d =20;
	int ret =0;
	Stack  ptr = malloc(sizeof(struct SNode));
	memset(ptr,0,sizeof(struct SNode));

	Push(ptr,a);
	Push(ptr,b);
	Push(ptr,c);
	Push(ptr,d);
	for(int i=0;i<4;i++)
	{
		ret = Pop(ptr);
		printf("pop is %d\n",ret);
	}
	return 0;
}