/**********************************/
/*�ļ����ƣ�lab1-01.c            */
/********************************/
/*����sequlist.h�ж����˳�����д�㷨����reverse(sequence_list *L)��ʵ��˳���ľ͵ص��á�*/

#include "squlist.h"
void reverse(sequence_list *L)
{
	int i,j,temp;
	j = L->size-1;            /* Ϊʲô */ 
	for(i = 0;i < j;i++,j--)
	{
		temp = L->a[i];
		L->a[i] = L->a[j];
		L->a[j] = temp;
	}
} 
int main()
{
	sequence_list L;         /*����˳���*/
	input(&L);               /*�����������*/
	print(&L);               /*���ԭ��*/
	reverse(&L);             /*˳�����*/
	print(&L);               /*����±�*/ 
}
