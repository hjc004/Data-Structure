/*编写算法函数linklist delallx(linklist head,int x)，删除带头结点的单链
表head中所以值为x的结点*/
/*****************************/
/*文件名称：lab3_04.c        */
/*****************************/

#include "slnklist.h"
linklist delallx(linklist head,int x)
{
	linklist p,t;
    while(head->next)
    {
        if(head->next->info==x)
        {
            p=head->next;
            head->next=head->next->next; 
            free(p);
        } 
		else 
		{
            break;
        }
    }
    if(head->next)
    {
        p=head->next;
        while(p->next)
        {
            if(p->next->info==x)
            {
                t=p->next;
                p->next=p->next->next;
                free(t);
            } 
			else 
			{
                p=p->next;
            }
        }        
    }
    return head;
}

int main()
{
	datatype x;
	linklist head;
	head=creatbyqueue();            /*尾插入法建立带头结点的单链表*/ 
	print(head);
	printf("请输入要删除的值：");
	scanf("%d",&x);
	head=delallx(head,x);
	print(head);
	delList(head);
	return 0;
} 
