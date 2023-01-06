/*编写函数void delx(linklist head,datatype x),删除带头结点单链表head中第一个
值为x的结点，并构造测试用例进行测试。*/
/**********************************/
/*文件名称：lab3_01.c              */
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
	head=creatbyqueue();     /*尾插入法建立带头结点的单链表*/
	print(head);
	printf("请输入要删除的值：");
	scanf("%d",&x);
	head=delx(head,x);       /*删除单链表的第一个值为x的结点*/ 
	print(head);
	delList(head);           /*释放单链表空间*/ 
	return 0; 
} 
