#include<stdio.h>
#include<stdlib.h>

struct celltype
{
    int element;
    celltype*next;
};

struct QUEUE
{
    celltype *Front;
    celltype *Rear;
};

void MakeNull(QUEUE &Q)
{
    Q.Front=new celltype;
    Q.Front->next=NULL;
    Q.Rear=Q.Front;
}

int Empty(QUEUE Q)
{
    if(Q.Front == Q.Rear)
        return 1;
    else
        return 0;
}

void EnQueue(int x,QUEUE &Q)
{
    Q.Rear->next=new celltype;
    Q.Rear=Q.Rear->next;
    Q.Rear->element=x;
    Q.Rear->next=NULL;
}

void DeQueue(QUEUE &Q)
{
    celltype *tmp;
    if(Empty (Q))
    {
        printf("queue is empty");

    }
    else
    {
        tmp=Q.Front->next;
        Q.Front->next=tmp->next;
        delete tmp;
        if(Q.Front ->next==NULL)
            Q.Rear=Q.Front;
    }
}



