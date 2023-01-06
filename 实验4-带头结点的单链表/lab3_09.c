/*编写一个程序，用尽可能快的方法返回带头结点的单链表中倒数第k个结点的地址，
如果不存在，则返回NULL*/
/***********************/
/*文件名称：lab3_09.c  */
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
	head=creatbyqueue();     /*尾插法建立带头结点的单链表*/ 
	print(head);             /*输出单链表head*/ 
	printf("k=");
	p=search(head,k);
	if (p)
	    printf("%d\n",p->info);
	else
	    printf("Not Found!\n");
	delList(head);
	return 0;
}
