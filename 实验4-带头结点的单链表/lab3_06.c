/*��֪������ͷ���ĵ�����L1��L2�еĽ��ֵ���Ѱ���������
����㷨����linklist mergeAscend(linklist L1,linklist L2)��L1��L2�ϲ���һ��
����Ĵ�ͷ���ĵ�������Ϊ�����ķ��ؽ����
����㷨����linklist mergeDescend(linklist L1,linklist L2)��L1��L2�ϲ���һ��
����Ĵ�ͷ���ĵ�������Ϊ�����ķ��ؽ����
�����main()�������в��ԡ�*/
/**************************/
/*�ļ����ƣ�lab3_06.c     */
/**************************/

#include "slnklist.h"
linklist mergeAscend(linklist L1,linklist L2)
{
	linklist head,x,y,p;
    head=(linklist)malloc(sizeof(node));
    head->next=NULL;
    p=head;
    x=L1->next;
    y=L2->next;
    while(x&&y)
    {
        if(x->info<=y->info)
        {
            p->next=x;
            p=x;
            x=x->next;
        }
        else
        {
            p->next=y;
            p=y; 
            y=y->next;
        }
    }
    p->next=x?x:y; 
    return head;
} 

int main()
{
	linklist h1,h2,h3;
	h1=creatbyqueue();      /*β�巨������������������������*/ 
	h2=creatbyqueue();
	print(h1);
	print(h2);
	h3=mergeAscend(h1,h2);  /*����ϲ���h3*/ 
	   /*����ϲ������h3=mergeDescend(h1,h2);*/
	print(h3);
	delList(h3);
	return 0;
}
