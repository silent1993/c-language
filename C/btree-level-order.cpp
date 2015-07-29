#include<stdio.h>
#include<stdlib.h>
#define  m 100
int no=0;
int high;
typedef char etype;
typedef struct bitnode
{
etype data;
struct bitnode *lch,*rch;
}bitnode,*bitree;
bitree que[m];
int front=0,rear=0;
bitnode *creat_bt1();
bitnode *creat_bt2();
void preorder(bitnode *p);
void inorder(bitnode *p);
void postorder(bitnode *p);
void enqueue(bitree);
bitree delqueue();
void levorder(bitree);
int treedepth(bitree);
void prtbtree(bitree,int);
void exchange(bitree);
int leafcount(bitree);
void paintleaf(bitree);
int  iscomplete(bitree P);
int count=0;
int  main()
{
char ch;int k;
do{
	printf("\n\n\n");
printf("\n==========���˵�==============");
printf("\n  1.�������������� 1");
printf("\n  2.�������������� 2");
printf("\n  3.����ݹ����������");
printf("\n  4.����ݹ����������");
printf("\n  5.����ݹ����������");
printf("\n  6.��α���������");
printf("\n  7.����������ĸ߶�");
printf("\n  8.�����������Ҷ������");
printf("\n  9.��������������������");
printf("\n  10.��ӡ������");
printf("\n  0.������������");
printf("\n===============================");
printf("\n  ����������ѡ��(0,1,2,3,4,5,6,7,8,9,10)");
scanf("%d",&k);

	   {printf("��α�����������");
	   levorder(t);
	printf("\n");
	   }
	else printf("������Ϊ��!\n");
	break;

}



void enqueue(bitree T)
{
if(front!=(rear+1)%m)
{rear=(rear+1)%m;
que[rear]=T;}
}
bitree delqueue()
{
if(front==rear)return NULL;
front=(front+1)%m;
return(que[front]);
}
void levorder(bitree T)
{
	bitree p;
	if(T)
	{
	enqueue(T);
	while(front!=rear)
	{
	p=delqueue();
    no=iscomplete(p);
    if(!no)
	{if(p->lch!=NULL)enqueue(p->lch);
	if(p->rch!=NULL)enqueue(p->rch);}
	else
        printf("it is not complete tree");
	}
    }
}
high=0;

int  iscomplete(bitree P)
{
    bitree P;
    if(!high)
    {
        if(P->lch&&P->rch)
        {
            return 0;
        }
        else if((P->lch==NULL)&&(P->rch==NULL))
        {
            return 0;
        }
        else if((P->lch==NULL)&&(P->rch))
        {

            return 1;
        }
        else if((P->lch)&&(P->rch==NULL))
        {
            high=1;
            return 0;
        }

    }
    else
    {
        if(P->lch||P->rch)
            return 1;
        else
            return 0;
    }
}


