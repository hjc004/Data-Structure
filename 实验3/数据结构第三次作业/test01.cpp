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
	    printf("\n���ǿյģ�\n");
	else
	    printf("\n���ǿյģ�\n");
	append(&mytable,22);
	append(&mytable,33);
	append(&mytable,44);
	append(&mytable,55);
	append(&mytable,66);
	printf("\n\n��������5������Ϊ��\n");
	display(mytable);
	printf("\n������ɾ���ڼ���λ��Ԫ�ؽڵ㣺\n");
	printf("%d",&k);
    dele(&mytable,k);
    printf("\n����ɾ����%dλ�õĽ���˳���Ϊ��\n");
    display(mytable);
	getch();
	return 0;
}
