/*��֪���Ա�洢�ڴ�ͷ���ĵ�����head�У�������㷨����void sort(liniklist
head)����head�еĽ�㰴���ֵ�������С�*/
/***************************/
/*�ļ����ƣ�lab3_05.c      */
/***************************/

#include "slnklist.h"
void sort(linklist head)
{
	int temp;  
    linklist p,pre;
    pre=p=head->next;
    while(pre)
    {
        p=pre;
        while(p)
        {

            if(pre->info>p->info)
            {
                temp=p->info;
                p->info=pre->info;
                pre->info=temp;
            }    
            p=p->next;
        }
        pre=pre->next;
    }
    //return head;
} 

int main()
{
	linklist head;
	head=creatbyqueue();      /*β�巨������ͷ���ĵ�����*/ 
	print(head);              /*���������head*/ 
	sort(head);               /*����*/ 
	print(head);
	delList(head);
	return 0;
}
