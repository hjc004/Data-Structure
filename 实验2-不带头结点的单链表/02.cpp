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
	head=creatbystack();    /*ͷ���뷨����������*/ 
	print(head);           /*���ԭ����*/ 
	head=reverse1(head);    /*����ԭ����*/ 
	print(head);           /*������ú������*/ 
}
