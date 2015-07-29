#include <stdio.h>
#include <stdlib.h>

struct mylist {
    int n;
     mylist *next;
};
typedef struct mylist *LIST;
typedef struct mylist *position;
void Insert(int x,position p);
void Delete(position p);
position Locate(int x,LIST L);
int Retrieve(position p,LIST L);
position Previous(position p,LIST L);
position Next(position p, LIST L);
position MakeNull(LIST &L);
position first(LIST &L);
position END(LIST &L);
void Creat(LIST &L);
void Prin(LIST L);
int Empty(LIST L);
int main()
{
    int i,j;
    position p;
    LIST L;
    L=new mylist;
    p=new mylist;
    printf("what do you want,1-creat,2-insert,3-deleat,4-next,5-retrieve,6-makenull,7-printf,8-locate,0-exit\n");
    while(scanf("%d",&j))
    {
        if(j==1)
        Creat(L);
    if(j==2)
    {printf("which position do you want to in,and what number\n");
    scanf("%d %d",&p,&i);
    Insert(i,p);
    }
    if(j==3)
    {
     printf("which position do you want to deleat\n");
    scanf("%d %d",&p,&i);
    Delete(p);
    }
    if(j==4)
    {
        printf("which next\n");
        scanf("%d",&p);
        p=Next(p,L);
        printf("the next is %d\n",p->n);
    }
    if(j==5)
    {
        printf("which do you retrieve\n");
        scanf("%d",&p);
        printf("the element is %d\n",Retrieve(p,L));
    }
    if(j==6)
    {
        MakeNull(L);
    }
    if(j==7)
    {
        Prin(L);
    }
    if(j==8)
    {
        printf("which do you locate\n");
        scanf("%d",&i);
        p=Locate(i,L);
       if(p)
       {
           printf("%d",p->next->n);

       }
       else
        printf("no find");

    }
    if(j==0)
        return 0;
    }

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
}
void Prin(LIST L)
{
    while(Empty(L))
    {
        printf("the element is %d",L->n);
        L=L->next;

    }
}
int Empty(LIST L)
{
    if(L==NULL)
        return 0;
    else
        return 1;
}
void Insert(int x,position p)
 { position temp;

    temp=p->next;
    p->next=new mylist;
    p->next->n=x;
    p->next->next=temp;
}
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

int Retrieve(position p,LIST L)
{
    return p->next->n;
}

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

position Next(position p, LIST L)
{
    if(p->next==NULL)
    {
        printf("it has no next position!");
    }
    else{return p->next;}
}

position MakeNull(LIST &L)
{
    L=new mylist;
    L->next=NULL;
    return L;
}

position first(LIST &L)
{
    return L;
}
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

