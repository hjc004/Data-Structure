#include "slnklist.h"
linklist delx(linklist head,datatype x)
{
	linklist pre=NULL,p;
	if(!head)
	{
		printf("单链表是空的！");
		return head;
	}
	p=head;
	while (p&&p->info!=x)
	{
		pre=p;
		p=p->next;
	}
	if (p)
	{
		if (!pre)
		    head=head->next;
		else
		pre->next=p->next;
		free(p);
	}
	return head;
}
int main()
{
	datatype x;
	linklist head;
	head=creatbyqueue();       /*尾插入法建立单链表*/ 
    print(head);
    printf("请输入要删除的值：");
    scanf("%d",&x);
    head=delx(head,x);       /*删除单链表的第一个值为x的结点*/ 
    print(head);
    delist(head);          /*释放单链表空间*/ 
    return 0;
}
