#include<stdio.h>
#include<stdlib.h>


#define maxlength 100


typedef struct{

int Front ;
int Rear;
int elements[maxlength];
}QUEUE ;


int addone(int i)
{
    return ((i+1)%maxlength);

}

void MakeNull(QUEUE &Q)
{
    Q.Front=0;
    Q.Rear=maxlength-1;
}

int Empty(QUEUE Q)
{
    if(addone(Q.Rear)==Q.Front)
        return 1;
    else
        return 0;
}

int Front(QUEUE Q)
{
    if(Empty(Q))
        return NULL;
    else
    {
        return (Q.elements[Q.Front]);
    }

}

void EnQueue(int x,QUEUE &Q)
{
    if(addone(addone(Q.Rear))==Q.Front)
        printf("queue is full");
    else
    {

        Q.Rear=addone (Q.Rear);
        Q.elements[Q.Rear]=x;
    }
}

void DeQueue(QUEUE &Q)
{
    if (Empty (Q))
        printf("queue is empty");
    else
        Q.Front=addone(Q.Front);
}
