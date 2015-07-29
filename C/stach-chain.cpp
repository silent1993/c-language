#include <stdio.h>
#include <stdlib.h>
typedef int elementtype;

struct node
{
    elementtype val;
    node *next;
};

typedef node *STACK;

void MakeNull(STACK &S);
void Push(int x, STACK &S);
void Pop(STACK &S);
elementtype Top(STACK S);
int Empty(STACK S);
int main()
{
    return 0;
}
void MakeNull(STACK &S)
{
    S->next=NULL;

}
//ʹջ��
void Push(int x, STACK &S)
{
    STACK stk;
    stk=new node;
    stk->val=x;
    stk->next=S->next;
    S->next=stk;
}
//ѹջ
void Pop(STACK &S)
{
    STACK stk;
    if(S->next)
    {
        stk=S->next;
        S->next=stk->next;
        delete stk;
    }
}
//��ջ
int Top(STACK S)
{
    if(S->next)
    {
        return S->next->val;

    }
    else
        return NULL;
}
//����ջ��
int Empty(STACK S)
{
    if(S->next)
        return  0;
    else
        return 1;
}
//�ж��Ƿ�Ϊ��
