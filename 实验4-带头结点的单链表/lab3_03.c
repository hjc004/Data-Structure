/*假设带头结点的单链表head是升序排列的，设计算法函数linklist insert(linklist
head,datatype x)，将值为x的结点插入到链表head中，并保持链表有序性。分别
插入到表头、表中和表尾三种情况的测试用例进行测试。*/
/****************************/
/*文件名称：lab3_03.c       */
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
	printf("输入一组升序排列的整数：\n");
	head=creatbyqueue();               /*尾插入法建立带头结点的单链表*/ 
	print(head);
	printf("请输入要插入的值：");
	scanf("%d",&x);
	head=insert(head,x);           /*将输入的值插入到带头结点的单链表适当位置*/ 
	print(head); 
	delList(head);
	return 0;
}
