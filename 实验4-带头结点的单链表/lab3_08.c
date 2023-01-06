/*编写一个算法函数void partion(linklist head)，将带头结点的单链表head中
的所有值为奇数的结点调整到链表的前面，所有值为偶数的结点调整到链表的后面*/
/**************************/
/*文件名称：lab3_08.c     */
/**************************/

#include "slnklist.h"
void partion(linklist head)
{
	linklist p,s,pre;
    pre=head;
    p=head->next;
    while(p)
    {
        if(p->info%2==0)
        {
            pre=p;
            p=p->next;
        }
        else
        {
            s=p;
            pre->next=p->next;
            p=pre->next;
            s->next=NULL;
            s->next=head->next;
            head->next=s;
        }
    }
} 

int main()
{
	linklist head;
	head=creatbyqueue();
	print(head);
	partion(head);
	print(head);
	delList(head);
	return 0;
}
