#include<stdio.h>
#include<stdlib.h>

struct node{
int val;
node * next;};

typedef node * STACK;

void MakeNull()
{
    STACK S;
    S=new node;
    S->next=NULL;

}

void Push(int x, STACK S)
{
    STACK stk;
    stk=new node;
    stk->val=x;
    stk->next=S->next;
    S->next=stk;
}

void Pop(STACK S)
{
    STACK stk;
    if(S->next)
    {
        stk=S->next;
        S->next=stk->next;
        delete stk;
    }
}

int Top(STACK S)
{
    if(S->next)
    {
        return S->next->val;

    }
    else
        return NULL;
}

int Empty(STACK S)
{
    if(S->next)
        return  0;
    else
        return 1;
}

