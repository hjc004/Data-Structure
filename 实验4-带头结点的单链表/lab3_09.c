/*��дһ�������þ����ܿ�ķ������ش�ͷ���ĵ������е�����k�����ĵ�ַ��
��������ڣ��򷵻�NULL*/
/***********************/
/*�ļ����ƣ�lab3_09.c  */
/***********************/

#include "slnklist.h"
linklist search(linklist head,int k)
{
	linklist p = head->next,x;
    int count = 0,i;
    x = p;
    while(x) 
    {
        count++;
        x=x->next;
    } 
    for(i=0;i<count-k;i++)
    {
        p = p->next;
    }
    return p;
} 

int main()
{
	int k;
	linklist head,p;
	head=creatbyqueue();     /*β�巨������ͷ���ĵ�����*/ 
	print(head);             /*���������head*/ 
	printf("k=");
	p=search(head,k);
	if (p)
	    printf("%d\n",p->info);
	else
	    printf("Not Found!\n");
	delList(head);
	return 0;
}
