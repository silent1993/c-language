#include <stdlib.h>
#include <stdio.h>

typedef int elementtype;

struct node{
    elementtype n;
    node *next;
    };

typedef node * LIST;
typedef node * position;
typedef node mylist;

void Creat(LIST &L);
void Prin(LIST L);
int Empty(LIST L);
void Insert(int x,position p);
void Delete(position p);
position Locate(int x,LIST L);
int Retrieve(position p,LIST L);
position Previous(position p,LIST L);
position Next(position p, LIST L);
position MakeNull(LIST &L);
position first(LIST &L);
position END(LIST &L);


int main()
{

}




void Creat(LIST &L)
{
    int i;
     position temp;
    position p;
    p=new mylist;
    temp=new mylist;
    p=L;
    for(i=1;i<=15;i++)
    {

    temp=p;
    p->n=i*i;
    p=temp->next;

    }
    delete p;
    delete temp;
}
//��������
void Prin(LIST L)
{
    while(Empty(L))
    {
        printf("the element is %d",L->n);
        L=L->next;

    }
}
//��ӡ����
int Empty(LIST L)
{
    if(L==NULL)
        return 0;
    else
        return 1;
}
//�ж��Ƿ�Ϊ��
void Insert(int x,position p)
 { position temp;

    temp=p->next;
    p->next=new mylist;
    p->next->n=x;
    p->next->next=temp;
}
//��������
void Delete(position p)
{
    position q;
    if(p->next != NULL)
    {
        q=p->next;
        p->next=q->next;
        delete q;
    }
}

//ɾ��ָ��λ��Ԫ��
position Locate(int x,LIST L)
{
    position p;
    p=L;
    while(p->next!=NULL)
        {if(p->next->n==x)
        return p;
    else
        p=p->next;}
    return NULL;
}
//����ָ��Ԫ��λ��
int Retrieve(position p,LIST L)
{
    return p->next->n;
}
//����ָ��λ��Ԫ��
position Previous(position p,LIST L)
{
    position q;
    q=L;
    if(p==L)
    {
        printf("it has no previous position!");

    }
    else
    {
        while(q->next!=p)
         q=q->next;
        return q;
    }
}
//����ָ��λ��ǰ��λ��
position Next(position p, LIST L)
{
    if(p->next==NULL)
    {
        printf("it has no next position!");
    }
    else{return p->next;}
}
//����ָ��λ�ú�һλ��
position MakeNull(LIST &L)
{
    L=new mylist;
    L->next=NULL;
    return L;
}
//�������
position first(LIST &L)
{
    return L;
}
//���ص�һ��λ��
position END(LIST &L)
{
    position q;
    q=L;
    while (q->next!=NULL)
    {
        q=q->next;
    }
    return q;
}
//�������һ��λ��
