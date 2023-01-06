#include "slnklist.h"
linklist delallx(linklist head,int x)
{
	linklist pre=NULL,p;
	if(!head)
	{
		printf("单链表是空的");
		return head;
    }
    p=head;
	do
	{
        while(p&&p->info!=x)
		{ 
            pre=p;p=p->next;
		}
        if(p)
		{
            if(!pre) head=head->next,pre=NULL;  
            else pre->next=p->next;
        }
        p=p->next;  
	}while(p);
	return head;
}
int main()
{   datatype x;
    linklist head;
    head=creatbyqueue();				/*尾插入法建立单链表*/
    print(head);
    printf("请输入要删除的值：");
    scanf("%d",&x);
    head=delallx(head,x);
    print(head);
    delist(head);
    return 0;
}
