#include "slnklist.h"
linklist delx(linklist head,datatype x)
{
	linklist pre=NULL,p;
	if(!head)
	{
		printf("�������ǿյģ�");
		return head;
	}
	p=head;
	while (p&&p->info!=x)
	{
		pre=p;
		p=p->next;
	}
	if (p)
	{
		if (!pre)
		    head=head->next;
		else
		pre->next=p->next;
		free(p);
	}
	return head;
}
int main()
{
	datatype x;
	linklist head;
	head=creatbyqueue();       /*β���뷨����������*/ 
    print(head);
    printf("������Ҫɾ����ֵ��");
    scanf("%d",&x);
    head=delx(head,x);       /*ɾ��������ĵ�һ��ֵΪx�Ľ��*/ 
    print(head);
    delist(head);          /*�ͷŵ�����ռ�*/ 
    return 0;
}
