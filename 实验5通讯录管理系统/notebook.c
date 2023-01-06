#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(LNode)
int seat;
typedef struct LNode
{
	int number;
	char name[20];
	double telenum;
	struct LNode *next;
}LNode,*LinkList;
void printList(LinkList L)	//��ӡͷ����ַΪL��ͨѶ¼ 
{
	printf("\n-----------------------------------------\n");
	printf(" ��� 	ѧ��	����	�绰����	");
	printf("\n-----------------------------------------\n");
	LinkList p=L;
	int n=1; 
	if(L==NULL||L->next==NULL) 
		printf("��ͨѶ¼��û��Ԫ��\n");
	else
		while(p->next !=NULL){
			printf("  #%d",n);
			printf(" %5d",p->next->number);
			printf(" %9s",p->next->name);
			printf(" %12.0f\n",p->next->telenum);
			p=p->next;
			n++;
		}
	printf(" ----------------------------------------\n");
}
LinkList prior(LinkList L,LinkList p)//����λ�ڵ�ǰ��ַԪ�ص�ǰһԪ�صĵ�ַ 
{
	if(L->next==NULL) 
	return(L);
	LinkList p_prior=L;
	while(p_prior->next != p){
		p_prior=p_prior->next;
	}
	return (p_prior);
}
void insertYouXu(LinkList L,LinkList Elem)//����һ��Ԫ�أ�ʹԭ�������Ϊ���� 
{
	LinkList p=L->next;
	while(p!=NULL && Elem->number>=p->number){
		if(p->number==Elem->number){
			printf("�������ظ����룡��\n");
			return;
		} 
		p=p->next;	
	}
	if(p==NULL){
		p=prior(L,p); 
		Elem->next=NULL;
		p->next=Elem;
	}
	else{ //��Ϊ�ձ��嵽ͷ���֮��
		p=prior(L,p); 
		Elem->next=p->next; 
		p->next=Elem;
	}
}
LinkList creatlncreLink()//����һ�����ͨѶ¼��Ա�ķǵݼ����������ͷ����ַ 
{
	LinkList L=(LinkList)malloc(LEN); //ͷ���
	L->next=NULL;
	LinkList p;
	int num=1;//��� 
	int number;//ѧ��
	char name[20];//����
	double telenum;//�绰����
	printf("������ѧ��ѧ�š������͵绰���룬����ͨѶ¼��������־Ϊ'-1'\n");
	printf("ѧ�� #%d:",num);
	scanf("%d",&number);
	printf("���� #%d: ",num);
	char temp=getchar();
	gets(name);
	printf("�绰���� #%d��",num);
	scanf("%lf",&telenum);
	while (number>=0){
		p=(LinkList)malloc(LEN); //�½��
		p->number=number;
		p->telenum=telenum;
		strcpy(p->name,name);
		insertYouXu(L,p); //����Ĳ����½��
		num++;
		printf("ѧ�� #%d��",num);
		scanf("%d",&number);
		printf("���� #%d: ",num);
		temp=getchar();
		gets(name);
		printf("�绰���� #%d��",num);
		scanf("%lf",&telenum);
	}
	return(L);
}
void deleteElem(LinkList L,int i)//��ͨѶ¼��ɾ����i��Ԫ�� 
{
	LinkList p=L;
	int j=0;
	while (p->next&&j<i-1){
		p=p->next;
		j++;
	}
	if(!(p->next)){
		printf("��%d��Ԫ��ɾ��ʧ��\n",i);
		return;
	}//�ж�i�Ƿ�Ϸ���i�Ȳ��ܴ���Ԫ�صĸ�����Ҳ����С�ڵ���0
	LinkList q=p->next;
	p->next=q->next;
	free(q);
}
int searchNum(LinkList L,int n)//��ѧ�Ų���ͨѶ�� 
{
	int flag=0;
	LinkList p=L->next;
	seat=1;
	if(L->next==NULL) 
		printf("��������û��Ԫ��,����ʧ��\n");
	else
	{
		while(p !=NULL)
		{
			if(p->number==n)
			{			
				flag=1;
				printf("Ҫ���ҵ��ǵ�%dλͨѶ�ߣ�\n",seat);
				printf(" ѧ��: %d ����: %s �绰����:%.0f\n",p->number,p->name,p->telenum);
			}
			p=p->next;
			seat++;
		}
	}
	return flag;
}

int searchName(LinkList L,char n[])//����������ͨѶ�� 
{
	int flag=0;
	LinkList p=L->next;
	seat=1;
	if(L->next==NULL||L==NULL)
		printf("��ͨѶ¼��û��Ԫ��,����ʧ��\n");
	else
	{
		while(p !=NULL){		
			if(!strcmp(p->name,n)){
				flag=1;
				printf("Ҫ���ҵ��ǵ�%dλͨѶ�ߣ�\n",seat);
				printf(" ѧ��: %d ����: %s �绰����:%.0f\n",p->number,p->name,p->telenum);
			}
			p=p->next;
			seat++;
		}
	}
	return flag;
}

int delNum(LinkList L,int n)//��ѧ��ɾ��ͨѶ�� 
{
	int flag=0;
	LinkList p=L->next;
	seat=1;
	if(L->next==NULL)
		printf("��ͨѶ¼��û�г�Ա��¼,ɾ��ʧ��\n");
	else{
		while(p!=NULL){			
			if(p->number<=n){
				if(p->number==n){
					flag=1;
					printf("%d ",p->number);
					p=p->next;
					deleteElem(L,seat);
				}
			}			
			else {
				p=p->next;
				seat++;
			}
		}
		printf("��ɾ��\n");
	}
	return flag;
}

int delName(LinkList L,char n[])//������ɾ��ͨѶ�� 
{
	int flag=0;
	LinkList p=L->next;
	seat=1;
	if(L->next==NULL)
		printf("��ͨѶ¼��û�г�Ա��¼,ɾ��ʧ��\n");
	else
	{
		while(p !=NULL){
			if(!strcmp(p->name,n)){
			flag=1;
			printf("%s ",p->name);
			p=p->next;
			deleteElem(L,seat);
			}
			else {
			p=p->next;
			seat++;
			}
		}
		if(flag)
			printf("��ɾ��\n");
	}
	return flag;
}

void main()
{
	LinkList L=NULL,p;
	int flag=0,menu;
	char temp;
	system("color 1f");
	printf("\n			**************^@^��ӭʹ��ͨѶ¼ϵͳ*************\n");
	printf("			*		1 ͨѶ¼�Ľ���		  	*\n") ;
	printf("			*		2 ����ͨѶ��¼			*\n") ;
	printf("			*		3 ��ѯͨѶ��¼		  	*\n") ;
	printf("			*		4 ɾ��ͨѶ��¼		  	*\n") ;
	printf("			*		5 ��ʾͨѶ¼��Ϣ	  	*\n") ;
	printf("			*		0 �˳�����ϵͳ		  	*\n") ;
	printf("\n			**************^@^��ӭʹ��ͨѶ¼ϵͳ*************\n");
	printf("��ѡ��0-5��");
		scanf("%d",&menu);
	while(menu!=0){
		switch(menu){
			case 1:
				{
					L=creatlncreLink();
					printf("\n����ͨѶ¼��");
					printList(L);
					flag=1;
					break;
				}
			case 2:
				{
					if(flag==1){
						int number,telenum;
						char name[20];
						printf("������ͨѶ�ߵ�ѧ�š������͵绰���룺\n");
						printf("ѧ��: ");
						scanf("%d",&number);
						printf("����: ");
						char temp=getchar();
						gets(name);
						printf("�绰����: ");
						scanf("%d",&telenum);
						LinkList p=(LinkList)malloc(LEN);
						p->number=number;
						strcpy(p->name,name);
						p->telenum=telenum;
						insertYouXu(L,p);
						printf("������ͨѶ¼Ϊ��");
						printList(L);
					}
					else printf("\nERROR:ͨѶ¼��û�н��������Ƚ���ͨѶ¼\n");
						break;
				}
			case 3:
				{
					int way,n;
					char na[20],temp;
					int s;
					if(L!=NULL)
					{
						if(flag)
						{
							printf("��ѡ����ҷ�ʽ:\n");
							printf("1.��ѧ��	2.������\n");
								scanf("%d",&way);
							if(way==1)
							{
								printf("\n������ѧ��:");
								scanf("%d",&n);
								s=searchNum(L,n);
								if(s==0) printf("�޴˳�Ա������ʧ��!\n");
							} 
							else if(way==2)
							{
								printf("\n ����������:");
								temp=getchar();
								gets(na);
								s=searchName(L,na);
								if(s==0)	printf("�޴˳�Ա������ʧ��!\n");
							}
							else printf("ͨѶ¼���޼�¼!\n");
						}
						break; 
					}
					else printf("ͨѶ¼���޼�¼!\n");
					break; 
			 	} 
			case 4:
				{
					int way;
					char temp;
					printf("��ѡ��ɾ����ʽ:\n ");
					printf("1.����� 2.��ѧ�� 3.������ \n");
						scanf("%d",&way);
					if(way==1){
						int n;
						printf("������ͨѶ¼���:");
							scanf("%d",&n);
						printf("ɾ����:\n");
						deleteElem(L,n);
						printList(L); 
					}
					else if(way==2){
						int n,f;
						printf("������ѧ��:");
						scanf("%d",&n);
						f=delNum(L,n);
						if(f!=0)
						{
							printf("ɾ����:\n");
							printList(L); 
						}
						else printf("�޸�ѧ�ţ�ɾ��ʧ��!\n"); 
					}
					else if(way==3){
						char na[20],temp;
						int f;
						printf("����������:");
							temp=getchar();	gets(na);
						f=delName(L,na);
						if(f!=0)
						{
							printf("ɾ����:\n");
							printList(L); 
						}
						else printf("�޸�ѧ�ţ�ɾ��ʧ��!\n");
					}
					else printf("ERROR!\n"); 
					break;
				}
			case 5:
				{
					printf("��ǰͨѶ¼��������:\n");
					printList(L);
					break;
				}
			case 0:exit(0);
			default: printf("\nû�д˹��ܣ�����������\n"); 
	} 
	printf("ѡ����:");
		scanf("%d",&menu);
	}
}



