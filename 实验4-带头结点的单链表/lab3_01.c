/*��д����void delx(linklist head,datatype x),ɾ����ͷ��㵥����head�е�һ��
ֵΪx�Ľ�㣬����������������в��ԡ�*/
/**********************************/
/*�ļ����ƣ�lab3_01.c              */
/**********************************/
#include "slnklist.h"
linklist delx(linklist head,datatype x)
{
	linklist p,pre=head; 
    p = head->next;
    while(p->info!=x) 
    {
        pre = p;
        p = p->next;
    }
    if(p)
    {
        pre->next = p->next;
        free(p);
    }
    return head;
}

int main()
{
	datatype x;
	linklist head;
	head=creatbyqueue();     /*β���뷨������ͷ���ĵ�����*/
	print(head);
	printf("������Ҫɾ����ֵ��");
	scanf("%d",&x);
	head=delx(head,x);       /*ɾ��������ĵ�һ��ֵΪx�Ľ��*/ 
	print(head);
	delList(head);           /*�ͷŵ�����ռ�*/ 
	return 0; 
} 
