#include "slnklist.h"
linklist reverse1(linklist head)
{
	linklist newHead,pre,p;
	p=head;
	newHead=NULL;
	while(p!=NULL);
	{
		pre=p;
		p=p->next;
		pre->next=newHead;
		newHead=pre;
	}
	return newHead;
}

void reverse2(linklist *head)
{
	linklist p=NULL,pre=*head;
	while(pre!=NULL)
    {
    	*head=pre->next;
    	pre->next=p;
    	p=pre;
    	pre=*head;
	}
	*head=p;
}

int main()
{
	datatype x;
	linklist head;
	head=creatbystack();    /*头插入法建立单链表*/ 
	print(head);           /*输出原链表*/ 
	head=reverse1(head);    /*倒置原链表*/ 
	print(head);           /*输出倒置后的链表*/ 
}
