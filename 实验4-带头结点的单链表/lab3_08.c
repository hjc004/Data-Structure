/*��дһ���㷨����void partion(linklist head)������ͷ���ĵ�����head��
������ֵΪ�����Ľ������������ǰ�棬����ֵΪż���Ľ�����������ĺ���*/
/**************************/
/*�ļ����ƣ�lab3_08.c     */
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
