#include <stdio.h>
#include <stdlib.h>
#define maxlength 10000

struct QUEUE
{
int  elements[maxlength];
int Front;
int Rear;
};
int addone(int i);
void MakeNull(QUEUE &Q);
int Empty(QUEUE Q);
int Front(QUEUE Q);
void EnQueue(int x,QUEUE &Q);
void DeQueue(QUEUE &Q);
int main()
{
    return 0;
}

int addone(int i)
{
    return ((i+1)%maxlength);

}
//用于返回当前位置的下一个位置，如超出最长长度，则返回到队列头
void MakeNull(QUEUE &Q)
{
    Q.Front=0;
    Q.Rear=maxlength-1;
}
//置空队列
int Empty(QUEUE Q)
{
    if(addone(Q.Rear)==Q.Front)
        return 1;
    else
        return 0;
}
//判断是否为空
int Front(QUEUE Q)
{
    if(Empty(Q))
        return NULL;
    else
    {
        return Q.elements[Q.Front];
    }

}
//返回队列头元素
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
//入队
void DeQueue(QUEUE &Q)
{
    if (Empty (Q))
        printf("queue is empty");
    else
        Q.Front=addone(Q.Front);
}
//出队
