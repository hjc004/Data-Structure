/*设计一个算法linklist interSection(linklist L1,linklist L2)，求两个单链表表示的
集合L1和L2的交集，并将结果用一个新的带头结点的单链表保存并返回表头地址。*/
/*************************/
/*文件名称：lab3_07.c    */
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
