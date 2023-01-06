#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "sequlist.h"
#include "sequlist.c"

int main()
{
	int k;
	sequence_list mytable;
	init(&mytable);
	display(mytable);
	if(empty(mytable))
	    printf("\n表是空的！\n");
	else
	    printf("\n表不是空的！\n");
	append(&mytable,22);
	append(&mytable,33);
	append(&mytable,44);
	append(&mytable,55);
	append(&mytable,66);
	printf("\n\n插入上述5个结点后为：\n");
	display(mytable);
	printf("\n请输入删除第几个位置元素节点：\n");
	printf("%d",&k);
    dele(&mytable,k);
    printf("\n表中删除第%d位置的结点后，顺序表为：\n");
    display(mytable);
	getch();
	return 0;
}
