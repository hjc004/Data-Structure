/*��д�㷨����linklist delallx(linklist head,int x)��ɾ����ͷ���ĵ���
��head������ֵΪx�Ľ��*/
/*****************************/
/*�ļ����ƣ�lab3_04.c        */
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
	head=creatbyqueue();            /*β���뷨������ͷ���ĵ�����*/ 
	print(head);
	printf("������Ҫɾ����ֵ��");
	scanf("%d",&x);
	head=delallx(head,x);
	print(head);
	delList(head);
	return 0;
} 
