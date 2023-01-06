#include "slnklist.h"
linklist insert(linklist head ,datatype x)
{
    linklist pre=NULL,h=head,p;
    while(h&&h->info<x)
	{
        pre=h;
        h=h->next;
    }
    p=(node*)malloc(sizeof(node));
    p->info=x;
    if(pre==NULL)
	{ 
        p->next=head;
        head=p;
    }else if(h)
	{    
        p->next=pre->next;
        pre->next=p;
    }else if(!h)
	{    
        p->next=NULL;
        pre->next=p;
    }
    return head;
}
int main()
{   datatype x;
    linklist head;
    printf("输入一组升序排列的整数：\n");
    head=creatbyqueue();				/*尾插入法建立单链表*/
    print(head);
    printf("请输入要插入的值：");
    scanf("%d",&x);
    head=insert(head,x);				/*将输入的值插入到单链表适当位置*/
    print(head);
    delist(head);
    return 0;
}
