/********************************/
/*�ļ����ƣ�lab1-02.c          */
/******************************/

/*��дһ���㷨����void sprit(sequence_list *L1,sequence_list *L2,sequence_list *L3),
��˳���L1�е����ݽ��з��࣬������ŵ�˳���L2�У�ż���浽˳���L3�У���дmain()���в��ԡ�
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
	squence_list L1,L2,L3;         /*��������˳���*/
	input(&L1);                    /*����L1*/
	sprit(&L1,&L2,&L3);            /*��L1���з���*/
	print(&L1);
	print(&L2);
	print(&L3);
}
