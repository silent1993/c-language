#include <stdio.h>
#include <stdlib.h>

typedef int elementtype;
struct celltype
{
    elementtype element;
    celltype *next;
};

struct QUEUE
{
    celltype *Front;
    celltype *Rear;
};

void MakeNull(QUEUE &Q);
int Empty(QUEUE Q);
void EnQueue(int x,QUEUE &Q);
void DeQueue(QUEUE &Q);

int main()
{
    return 0;
}



void MakeNull(QUEUE &Q)
{
    Q.Front=new celltype;
    Q.Front->next=NULL;
    Q.Rear=Q.Front;
}
//置空队列
int Empty(QUEUE Q)
{
    if(Q.Front == Q.Rear)
        return 1;
    else
        return 0;
}
//判断队列是否为空
void EnQueue(int x,QUEUE &Q)
{
    Q.Rear->next=new celltype;
    Q.Rear=Q.Rear->next;
    Q.Rear->element=x;
    Q.Rear->next=NULL;
}
//入队
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
//出队
