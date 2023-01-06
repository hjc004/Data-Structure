#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(LNode)
int seat;
typedef struct LNode   //ͨѶ¼���
{
  int number;
  char name[20];    /////
  double telenum;
  struct LNode *next;
}LNode,*LinkList;

void printList(LinkList L)
{    // ��ӡͷ����ַΪL��ͨѶ¼
   LinkList p=L;////
   int n=1;
   printf("\n          ---------------------------------------\n");
   printf("               ѧ��       ����     �绰����\n");
   printf("          ----------------------------------------\n");   
   if(L==NULL || L->next==NULL) 
	     printf("��ͨѶ¼��û��Ԫ��\n");
   else 
       while(p->next !=NULL)
	   {
         printf("          %2d   %-9d",n,p->next->number);
         printf("    %-5s  %.0f\n",p->next->name,p->next->telenum);
         p=p->next;
         n++;
	   }
   printf("          ----------------------------------------\n");
   return ;
}

LinkList prior(LinkList L,LinkList p)
{  // ����λ�ڵ�ǰ��ַԪ�ص�ǰһԪ�صĵ�ַ
   LinkList p_prior=L;
   if(L->next==NULL) 
	  return(L);
   while(p_prior->next != p)
   {
      p_prior=p_prior->next;
   }
   return (p_prior);
}  

void insertYouXu(LinkList L,LinkList Elem) 
{              //����һ��Ԫ�أ�ʹԭ�������Ϊ����
	LinkList p=L->next;
	while(p!=NULL && Elem->number>=p->number)
	{
		if(p->number==Elem->number)
		{
			printf("�ظ����룡��\n");return;
		}
		p=p->next;
	}         //ȷ��Elem�����λ��
	if(p==NULL) 
	{
		p=prior(L,p); Elem->next=NULL;p->next=Elem;
	} 
	else       //��Ϊ�ձ��嵽ͷ���֮��
	{ 
		p=prior(L,p); Elem->next=p->next; p->next=Elem; 
	}
}

LinkList creatIncreLink() 
{//����һ�����ͨѶ¼��Ա�ķǵݼ����������ͷ����ַ
   
   int num=1,number;
   double telenum;
   char name[20],temp;
   LinkList L,p;
   L=(LinkList)malloc(LEN);    //ͷ���
   L->next=NULL;
   printf("������ѧ��ѧ�š������͵绰���룬����ͨѶ¼����'-1'Ϊ���������־\n");
   printf("������ѧ�� %d��",num);
      scanf("%d",&number);
   printf("���������� %d: ",num);
      temp=getchar(); gets(name);
   printf("������绰���� %d��",num);
      scanf("%lf",&telenum);
   while(number>=0)
   {
      p=(LinkList)malloc(LEN); //�½��
      p->number=number;
      p->telenum=telenum;
      strcpy(p->name,name);
      insertYouXu(L,p);       //����Ĳ����½��
      num++;
      printf("������ѧ�� %d��",num);
         scanf("%d",&number);
      printf("���������� %d: ",num);
         temp=getchar();  gets(name);
      printf("������绰���� %d��",num);
         scanf("%lf",&telenum);
   }
   return(L);
}

void deleteElem(LinkList L,int i)       
{ //��ͨѶ¼��ɾ����i��Ԫ��
    LinkList p=L,q;//////
    int j=0;
    while (p->next && j<i-1)
	{
       p = p->next;j++;
	} 
    if(!(p->next)) //�ж�i�Ƿ�Ϸ���i�Ȳ��ܴ���Ԫ�صĸ�����Ҳ����С�ڵ���0
	{
		printf("��%d��Ԫ��ɾ��ʧ��\n",i);
		return ;
	}
    q = p->next;
    p->next = q->next;
    free(q);  //�ͷ�ɾ���Ľ�� 
}

int searchNum(LinkList L,int n)
{    // ��ѧ�Ų���ͨѶ��
 int flag=0;
 LinkList p=L->next;
 seat=1;
 if(L->next==NULL) printf("��������û��Ԫ��,����ʧ��\n");
 else 
 {
  while(p !=NULL)
  {
   if(p->number<=n)
    if(p->number==n)
	{
       flag=1;
       printf("Ҫ���ҵ��ǵ�%dλͨѶ�ߣ�\n",seat);
       printf("                        ѧ��: %d   ����: %s   �绰����.:%.0f\n",p->number,p->name,p->telenum);
    }
   p=p->next;seat++;//!!!!
  }
 }
 return flag;
}

int searchName(LinkList L,char n[])
{    // ����������ͨѶ��
 int flag=0;
 LinkList p=L->next;
 seat=1;
 if(L->next==NULL||L==NULL) 
 printf("��ͨѶ¼��û��Ԫ��,����ʧ��\n");
 else 
 {
  while(p !=NULL)
  {
   if(!strcmp(p->name,n))
   {
    flag=1;
    printf("Ҫ���ҵ��ǵ�%dλͨѶ�ߣ�\n",seat);
    printf("                        Number: %d   Name: %s   TeleNo.:%.0f\n",p->number,p->name,p->telenum);
   }
   p=p->next;seat++;//!!!!!
  }
 }
 return flag;
}

int delNum(LinkList L,int n)
{    // ��ѧ��ɾ��ͨѶ��
 int flag=0;
 LinkList p=L->next;
 seat=1;
 if(L->next==NULL)
 printf("��������û��Ԫ��,ɾ��ʧ��\n");
 else 
 {
  while(p !=NULL)
  {
   if(p->number<=n)
   {
    if(p->number==n)
	{
       flag=1;
       printf("%d ",p->number);
       p=p->next;
       deleteElem(L,seat);
      
    }
   }
   else {p=p->next;seat++;}
  }
  printf("��ɾ��\n");
 }
 return flag;
}


int delName(LinkList L,char n[])
{    // ������ɾ��ͨѶ��	
 int flag=0;
 LinkList p=L->next;
 seat=1;
 if(L->next==NULL)
 printf("��������û��Ԫ��,����ʧ��\n");
 else
 {
  while(p !=NULL)
  {
   if(!strcmp(p->name,n))
   {
    flag=1;
    printf("%s ",p->name);
    p=p->next;
    deleteElem(L,seat);
   }
   else {p=p->next;seat++;}
  }
  if(flag)printf("��ɾ��\n");
 }
 return flag;
}

void main()
{
   LinkList L=NULL,p;
   int flag=0,menu;
   char temp;
   system("color 1f");   
   printf("\n           ***************** ^@^��ӭʹ��ͨѶ¼ϵͳ***********\n");
   printf("           *               1 ͨѶ¼�Ľ���                   *\n");       
   printf("           *               2 ����ͨѶ��¼                   *\n");
   printf("           *               3 ��ѯͨѶ��¼                   *\n");
   printf("           *               4 ɾ��ͨѶ��¼                   *\n");
   printf("           *               5 ��ʾͨѶ¼��Ϣ                 *\n");
   printf("           *               0 �˳�����ϵͳ                   *\n");
   printf("           **************** ^@^��ӭʹ��ͨѶ¼ϵͳ************\n");
   printf("��ѡ��0-5��");
      scanf("%d",&menu);
   while(menu!=0)
   {
     switch(menu)
	 {
       case 1:
			 { 
                L=creatIncreLink();
                printf("����ͨѶ¼��");
                printList(L);
                flag=1;
                break;
			 }
       case 2:
			 {
		        if(flag==1)
				{
					int number,telenum;
                    char name[20];
                    printf("������ͨѶ�ߵ�ѧ�ź�������\n");
                    printf("������ѧ��: ");
                       scanf("%d",&number);
                    printf("����������: ");
                       temp=getchar(); gets(name);
                    printf("������绰����: ");
                       scanf("%d",&telenum);
                    p=(LinkList)malloc(LEN); //�½��
                    p->number=number;
                    strcpy(p->name,name);
                    p->telenum=telenum;
                    insertYouXu(L,p);       //����Ĳ����½��
                    printf("�����");
                    printList(L);
				}//endif
                else printf("\nERROR: ͨѶ¼��û�н��������Ƚ���ͨѶ¼\n");
                     break;
			 }//endcase2
       case 3:
			{ 
		        int way,n;
                char na[20],temp;
                int s;
                if(L!=NULL)
				{
			        if(flag)
					{
				        printf("ѡ����ҷ�ʽ��\n");
                        printf("               1.��ѧ��   2.������\n");
                           scanf("%d",&way);
                        if(way==1)
						{
					       printf("\n������ѧ��:");
                             scanf("%d",&n);
                           s=searchNum(L,n);
                           if(s==0) printf("�޴�ͨѶ�ߣ�����ʧ�ܣ�\n");
						}
				        else if(way==2)
						{
					       printf("\n����������:");
					       temp=getchar(); gets(na);
					       s=searchName(L,na);
					       if(s==0) printf("�޴�ͨѶ�ߣ�����ʧ�ܣ�\n");
						}
				        else printf("ͨѶ¼���޼�¼��\n");
					}
			        break;
				}
		        else printf("ͨѶ¼���޼�¼��\n");break;
			}//endcase3
       case 4:
		   {
		       int way;
			   char temp; ////
		       printf("ѡ��ɾ����ʽ��1.�����  2. ��ѧ��  3.������ \n");
		          scanf("%d",&way);
		       if(way==1)
			   {
			      int n;
			      printf("������ͨѶ¼���: ");
			         scanf("%d",&n);
			      printf("ɾ����\n");
			      deleteElem(L,n);
			      printList(L);
			   }
		       else if(way==2)
			   {
			      int n,f;
			      printf("������ѧ��: ");
			      scanf("%d",&n);
			      f=delNum(L,n);
			      if(f!=0)
				  {
				      printf("ɾ����\n");
				      printList(L);
				  }
			      else printf("�޸�ѧ�ţ�ɾ��ʧ��!\n");
			   }
		       else if(way==3)
			   {
			      char na[20],temp;
			      int f;
			      printf("\n����������:");
			        temp=getchar();  gets(na);
			      f=delName(L,na);
			      if(f!=0)
				  {
				     printf("ɾ����\n");
				     printList(L);
				  }
			      else printf("�޸�������ɾ��ʧ��!\n");
			   }
		       else printf("ERROR!!\n");
		       break;
		   }//endcase4
       case 5:
		   {
		       printf("��ǰͨѶ¼�������£�\n");
		       printList(L);
		       break;
		   }
       case 0: exit(0);
       default:  printf("\nû�д˹��ܣ���������\n");
     }//endswitch
     printf("ѡ���ܣ�");
         scanf("%d",&menu);
   }//endwhile
}//end
