/*�����ͷ���ĵ�����head���������еģ�����㷨����linklist insert(linklist
head,datatype x)����ֵΪx�Ľ����뵽����head�У����������������ԡ��ֱ�
���뵽��ͷ�����кͱ�β��������Ĳ����������в��ԡ�*/
/****************************/
/*�ļ����ƣ�lab3_03.c       */
/****************************/

#include "slnklist.h"
linklist insert(linklist head,datatype x)
{
	linklist pre,p,s;
    s = (linklist)malloc(sizeof(node));
    s->info = x;
    p = head->next;
    pre = head;
    while(p&&p->info<x)   
    {
        pre = p;
        p = p->next; 
    } 
    pre->next = s;
    s->next = p;
    return head;
} 

int main()
{
	datatype x;
	linklist head;
	printf("����һ���������е�������\n");
	head=creatbyqueue();               /*β���뷨������ͷ���ĵ�����*/ 
	print(head);
	printf("������Ҫ�����ֵ��");
	scanf("%d",&x);
	head=insert(head,x);           /*�������ֵ���뵽��ͷ���ĵ������ʵ�λ��*/ 
	print(head); 
	delList(head);
	return 0;
}
