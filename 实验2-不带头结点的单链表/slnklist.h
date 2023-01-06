#include <stdio.h>
#include <stdlib.h>
/**************************************/
/* ����ʵ�ֵ�ͷ�ļ����ļ���slnklist.h */
/**************************************/
typedef int datatype;
typedef struct link_node
{
	datatype info;
	struct link_node *next;
}node;
typedef node *linklist;

/***********************************/
/*�������ƣ�creatbystack()    */
/*�������ܣ�ͷ�巨����������       */
/***********************************/
linklist creatbystack()
{
	linklist head,s;
	datatype x;
	head=NULL;
	printf("������������������:\n");
	scanf("%d",&x);
	while (x!=0)
	{
		s=(linklist)malloc(sizeof(node));
		s->info=x;
		s->next=head;
		head=s;
		scanf("%d",&x);
	}
	return head;
} 

/*********************************/
/*�������ƣ�creatbyqueue()    */
/*�������ܣ�β�巨����������       */
/*********************************/
linklist creatbyqueue()
{
	linklist head,r,s;
	datatype x;
	head=r=NULL;
	printf("������������������:\n");
	scanf("%d",&x);
	while (x!=0) 
	{
		s=(linklist)malloc(sizeof(node));
		s->info=x;
		if (head=NULL)
		    head=s;
		else 
		    r->next=s;
		r=s;
		scanf("%d",&x);
	}
	if (r)  r->next=NULL;
	return head;
}
/************************************/
/*�������ƣ�print()                 */
/*�������ƣ��������ͷ���ĵ�����  */
/************************************/ 
void print(linklist head)
{
	linklist p;
	int i=0;
	p=head;
	printf("List is:\n");
	while(p)
	{
		printf("%5d",p->info);
		p=p->next;
		i++;
		if (i%10==0)
		    printf("\n");
	}
	printf("\n");
}
/***********************************/
/*�������ƣ�delist()               */
/*�������ܣ��ͷŲ���ͷ���ĵ����� */
/***********************************/
void delist(linklist head)
{
	linklist p=head;
	while (p)
	{
		head=p->next;
		free(p);
		p=head;
	}
} 
