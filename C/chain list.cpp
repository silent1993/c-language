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
//制造链表
void Prin(LIST L)
{
    while(Empty(L))
    {
        printf("the element is %d",L->n);
        L=L->next;

    }
}
//打印链表
int Empty(LIST L)
{
    if(L==NULL)
        return 0;
    else
        return 1;
}
//判断是否为空
void Insert(int x,position p)
 { position temp;

    temp=p->next;
    p->next=new mylist;
    p->next->n=x;
    p->next->next=temp;
}
//插入链表
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

//删除指定位置元素
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
//返回指定元素位置
int Retrieve(position p,LIST L)
{
    return p->next->n;
}
//返回指定位置元素
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
//返回指定位置前个位置
position Next(position p, LIST L)
{
    if(p->next==NULL)
    {
        printf("it has no next position!");
    }
    else{return p->next;}
}
//返回指定位置后一位置
position MakeNull(LIST &L)
{
    L=new mylist;
    L->next=NULL;
    return L;
}
//清空链表
position first(LIST &L)
{
    return L;
}
//返回第一个位置
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
//返回最后一个位置
