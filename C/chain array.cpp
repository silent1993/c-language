#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define maxl 100

typedef struct {
int elements[maxl];
int last;
}LIST;

typedef int position;
position END(LIST L);
void Creat(LIST &L);
void Insert (int x,position p,LIST &L);
void Delete (position p,LIST &L);
void Print(LIST L);
position Locate(int x,LIST L);
position First(LIST L);
position Next(position p,LIST L);
position Previous(position p,LIST L);
position MakeNull(LIST &L);
position Retrieve(position p,LIST L);

int main()
{
    int i,j;
    position p;
    LIST L;
    printf("what do you want,1-creat,2-insert,3-deleat,4-next,5-retrieve,6-makenull,7-printf,8-locate,0-exit\n");
    while(scanf("%d",&j))
    {
        if(j==1)
        {Creat(L);
    printf("the first element %d\n",L.elements[First(L)]);
    printf("the last element %d\n",L.elements[END(L)]);}
    if(j==2)
    {printf("which position do you want to in,and what number\n");
    scanf("%d %d",&p,&i);
    Insert(i,p,L);
    }
    if(j==3)
    {
     printf("which position do you want to deleat\n");
    scanf("%d %d",&p,&i);
    Delete(p,L);
    }
    if(j==4)
    {
        printf("which next\n");
        scanf("%d",&p);
        printf("the next is %d\n",L.elements[Next(p,L)]);
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
        Print(L);
    }
    if(j==8)
    {
        printf("which do you locate\n");
        scanf("%d",&i);
        p=Locate(i,L);
        if(p>L.last)
            printf("no find\n");
        else
            printf("the position is %d",p);

    }
    if(j==0)
        return 0;
    }

}
position END(LIST L)
{
    return (L.last);
}

void Insert (int x,position p,LIST &L)
{
    position q;
    if(L.last>=maxl-1)
    {
        printf("the chain is full\n");

    }
    else if((p>L.last+1)||(p<1))
    {
        printf("erro,the position doesn't exist\n");

    }
    else
    {
        for(q=L.last;q>=p;q--)
            L.elements[q+1]=L.elements[q];
        L.last=L.last+1;
        L.elements[p]=x;
    }
}

void Delete (position p,LIST &L)
{
    position q;
    if((p>L.last)||(p<1))
        printf("position doesn'teist\n");
    else
    {
        L.last=L.last-1;
        for(q=p;q<=L.last;q++)
        {
            L.elements[q]=L.elements[q+1];
        }
    }
}


position Locate(int x,LIST L)
{
    position q;
    for(q=1;q<=L.last;q++)
        if(L.elements[q]==x)
        return q;
   return L.last+1;
}

position First(LIST L)
{
    return 1;
}


position Next(position p,LIST L)
{
    if(p==L.last)
        printf("no next position\n");
    else
        return (p+1);

}

position Previous(position p,LIST L)
{
    if(p==1)
        printf("no previous position\n");
    else
        return(p-1);
}


position MakeNull(LIST &L)
{
    L.last=0;
}

position Retrieve(position p,LIST L)
{
    if((p>L.last)||(p<1))
        printf("position doesn'teist\n");
    else
        return L.elements[p];
}
void Creat(LIST &L)
{
    int i;

    for(i=1;i<=15;i++)
    {
        L.elements[i]=i*i;
        L.last=i;
    }
}
void Print(LIST L)
{
    int i;
    for(i=1;i<=L.last;i++)
        printf("%d ",L.elements[i]);

}
