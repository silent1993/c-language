#include <stdio.h>
#include <stdlib.h>

#define maxsize 10000
typedef int elementtype ;

struct spacestr
{
    elementtype element;
    int next;
};

typedef int position,cursor;
cursor L,M,av;
spacestr SPACE[maxsize];

void Initialize(spacestr *SPACE,int *av);
cursor Malloc_SL(spacestr *SPACE,int *av);
void Free_SL(cursor q,int *av);
void INSERT(elementtype x,position p,spacestr *SPACE);
void DELETE(position p,spacestr *SPACE);

int main()
{
    return 0;
}
void Initialize(spacestr *SPACE,int *av)
{
    int j;
    for(j=0;j<maxsize-1;j++)
    {
        SPACE[j].next=j+1;

    }
    SPACE[j].next=-1;
    *av=0;
}
cursor Malloc_SL(spacestr *SPACE,int *av)
{
    cursor q;
    if(SPACE[*av].next==-1)
        q=-1;
    else
    {
        q=SPACE[*av].next;
        SPACE[*av].next=SPACE[q].next;
    }
    return q;

}
void Free_SL(cursor q,int *av)
{
    SPACE[q].next=SPACE[*av].next;
    SPACE[*av].next=q;
}
void INSERT(elementtype x,position p,spacestr *SPACE)
{
    position q;
    SPACE[q].element=x;
    SPACE[q].next=SPACE[p].next;
    SPACE[p].next=q;
}
void DELETE(position p,spacestr *SPACE)
{
    position q;
    if(SPACE[p].next!=-1)
    {
        q=SPACE[p].next;
        SPACE[p].next=SPACE[q].next;
    }
}

