/*���һ���㷨linklist interSection(linklist L1,linklist L2)���������������ʾ��
����L1��L2�Ľ��������������һ���µĴ�ͷ���ĵ������沢���ر�ͷ��ַ��*/
/*************************/
/*�ļ����ƣ�lab3_07.c    */
/*************************/

#include "slnklist.h"
linklist interSection(linklist L1,linklist L2)
{
	linklist head,p,s,x,y;
    head=(linklist)malloc(sizeof(node));
    head->next=NULL;
    p = head;
    x = L1->next;
    y = L2->next;
    while(x) 
    {
        while(y)
        {
            if(x->info==y->info)
            {
                s = (linklist)malloc(sizeof(node));
                s->info = x->info;
                p->next = s;
                p = s;
                break; 
            }
            y = y->next;    
        }
        x = x->next;
    }
    p->next = NULL;
    return head;
} 

int main()
{
	linklist h1,h2,h3;
	h1=creatbyqueue();
	h2=creatbyqueue();
	print(h1);
	print(h2);
	h3=interSection(h1,h2);
	print(h3);
	delList(h1);
	delList(h2);
	delList(h3);
	return 0;
}
