/*�������Ա�(a1,a2,a3,...an)���ô�ͷ���ĵ�����洢��������㷨����
linklist reverse(linklist head)������ͷ���ĵ�����head�͵ص��ã�ʹ��
���(an,an-1,...a3,a2,a1)������������������в��ԡ�*/
/*********************************/
/*�ļ����ƣ�lab3_02.c            */
/*********************************/

#include "slnklist.h"
linklist reverse(linklist head)
{
	linklist p,q;
    p = head->next;
    head->next = NULL;
    while(p)  
    {
        q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }
    return head;
}

int main()
{
	datatype x;
	linklist head;
	head=creatbystack();         /*ͷ���뷨������ͷ���ĵ�����*/ 
	print(head);                 /*���ԭ����*/ 
	head=reverse(head);          /*����ԭ����*/ 
	print(head);                 /*������ú������*/ 
	delList(head);
	return 0;
} 
