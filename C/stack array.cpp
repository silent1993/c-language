#include<stdio.h>
#include<stdlib.h>


#define maxlength 100

struct STACK
{
    int top;
    int elements[maxlength];
};



void MakeNull(STACK &S)
{
    S.top=maxlength;
}

int Empty(STACK S)
{
    if(S.top>maxlength-1)
        return 1;
    else
        return 0;
}

int Top(STACK S)
{
    if(Empty(S))
    {
        return NULL;

    }

    else
        return (S.elements[S.top]);
}


void Pop(STACK S)
{
    if(Empty (S))
    {
        printf("stack is full");
    }
    else
    {
        S.top=S.top+1;
    }
}

void Push(int x,STACK &S)
{
    if(S.top==0)
    {
        printf("sack is full");

    }

    else
    {
        S.top=S.top-1;
        S.elements[S.top]=x;
    }

}
