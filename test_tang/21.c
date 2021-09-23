//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

#include<stdio.h>


  struct ListNode {
      int val;
      struct ListNode *next;
  };



struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{

   struct ListNode   prehead;
   struct ListNode  * pre =& prehead;

  if(l1 == NULL)
       return l2;
  if(l2 == NULL)
       return l1;

    while(l1 !=NULL  && l2 != NULL)
    {
        if(l1->val >= l2->val)
        {
            pre->next = l2;
            l2 = l2->next;
        }else
        {
            pre->next = l1;
            l1 = l1->next;
        }
        pre = pre->next;
    }

   if(l1 == NULL)
	{
	pre->next = l2;
	}

      if(l2 == NULL)
	{
	pre->next = l1;
	}
    return (&prehead)->next;
}