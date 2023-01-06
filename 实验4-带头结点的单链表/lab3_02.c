/*假设线性表(a1,a2,a3,...an)采用带头结点的单链表存储，请设计算法函数
linklist reverse(linklist head)，将带头结点的单链表head就地倒置，使表
变成(an,an-1,...a3,a2,a1)，并构造测试用例进行测试。*/
/*********************************/
/*文件名称：lab3_02.c            */
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
	head=creatbystack();         /*头插入法建立带头结点的单链表*/ 
	print(head);                 /*输出原链表*/ 
	head=reverse(head);          /*倒置原链表*/ 
	print(head);                 /*输出倒置后的链表*/ 
	delList(head);
	return 0;
} 
