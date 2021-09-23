/*
 在单向链表中，链表尾是不能作为栈顶指针的， top一定是链表头
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>



typedef  struct  SNode  *  Stack;
struct  SNode{
	int data;
	struct  SNode  * next;
};


//创建一个栈
Stack  CreateStack(void)
{
	Stack s;
	s = (Stack)malloc(sizeof(struct SNode));
	s->next = NULL;
	return s;
}


//判断是否为空栈
int IsEmpty(Stack  ptr)
{
      int ret = 0;
      if(ptr->next == NULL)
             return -1;
	return ret;
}

//删除一个栈
int  DeleteStack(Stack ptr)
{
	Stack s;
	if(ptr == NULL)
	{
		printf("para is null,please checkout para\n");
		return -1;
	}
while(ptr->next !=NULL)
{
	s = ptr->next->next;
	free(ptr->next);
	ptr->next = s;
}
	free(ptr);
	return 0;
}


//入栈操作
void Push(Stack  ptr, int data)
{
	if(NULL == ptr)
	{
	   printf("the  para is error\n");
	  return ;
	}
	
	Stack  s = malloc(sizeof( struct SNode)); 
	s->data = data;
	s->next = ptr->next;
	ptr->next = s;
}

//出栈操作
int Pop(Stack  ptr)
{
	if(ptr->next == NULL)
	{
		printf("the  stack  is  empty\n");
		return -1;
	}
	int data ;
	Stack  s = ptr->next;
	data  = ptr ->next->data;
	ptr->next = ptr ->next->next;
	free(s);
	return data;
}
int main(void)
{
	int i = 0,data = 0;
       int a[10] = {10,20,30,40,50,60,70,80,90,100};
       Stack s = CreateStack();
       Stack b = CreateStack();
       for( i = 0; i<10;i++)
	  {
		   Push(s,  a[i]);
		   Push(b,  a[i]);
	  }     
	for( i = 0;i<10;i++)
	{
            data =  Pop(s );
	    printf("the element is %d\n",data);
	}
	if( 0 == IsEmpty(s))
	{
		printf("the stack is empty\n");
	}
	DeleteStack( b);
	data =  Pop(b);
	return 0;
}