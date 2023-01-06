/*已知两个带头结点的单链表L1和L2中的结点值均已按升序排序。
设计算法函数linklist mergeAscend(linklist L1,linklist L2)将L1和L2合并成一个
升序的带头结点的单链表作为函数的返回结果；
设计算法函数linklist mergeDescend(linklist L1,linklist L2)将L1和L2合并成一个
降序的带头结点的单链表作为函数的返回结果；
并设计main()函数进行测试。*/
/**************************/
/*文件名称：lab3_06.c     */
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
	h1=creatbyqueue();      /*尾插法建立单链表，请输入升序序列*/ 
	h2=creatbyqueue();
	print(h1);
	print(h2);
	h3=mergeAscend(h1,h2);  /*升序合并到h3*/ 
	   /*降序合并请调用h3=mergeDescend(h1,h2);*/
	print(h3);
	delList(h3);
	return 0;
}
