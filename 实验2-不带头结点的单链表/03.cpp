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
    printf("����һ���������е�������\n");
    head=creatbyqueue();				/*β���뷨����������*/
    print(head);
    printf("������Ҫ�����ֵ��");
    scanf("%d",&x);
    head=insert(head,x);				/*�������ֵ���뵽�������ʵ�λ��*/
    print(head);
    delist(head);
    return 0;
}
