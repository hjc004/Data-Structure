/********************************/
/*文件名称：lab1-02.c          */
/******************************/

/*编写一个算法函数void sprit(sequence_list *L1,sequence_list *L2,sequence_list *L3),
将顺序表L1中的数据进行分类，奇数存放到顺序表L2中，偶数存到顺序表L3中，编写main()进行测试。
*/

#include "sequlist.h"
void sprit(sequence_list *L1,sequence_list *L2,sequence_list *L3)
{
	int i,x,y;
	x = 0;
	y = 0;
	for(i = 0;i < L1->size;i++)
	{
		if(L1->a[i]%2 == 0)
		{
			L3->a[x] = L1->a[i];
			x++;
			L3->size = x;
		}
		else
		{
			L2->a[y] = L1->a[i];
			y++;
			L2->size = y;
		}
	}
} 
int main()
{
	squence_list L1,L2,L3;         /*定义三个顺序表*/
	input(&L1);                    /*输入L1*/
	sprit(&L1,&L2,&L3);            /*对L1进行分类*/
	print(&L1);
	print(&L2);
	print(&L3);
}
