#include "slnklist.h"
linklist delallx(linklist head,int x)
{
	linklist pre=NULL,p;
	if(!head)
	{
		printf("�������ǿյ�");
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
    head=creatbyqueue();				/*β���뷨����������*/
    print(head);
    printf("������Ҫɾ����ֵ��");
    scanf("%d",&x);
    head=delallx(head,x);
    print(head);
    delist(head);
    return 0;
}
