#include <stdio.h>
#include <stdlib.h>

#define maxlength 100000
typedef int elementtype;

typedef struct
{
    elementtype elements[maxlength];
    int top;
}STACK;

void MakeNull(STACK &S);
int Empty(STACK S);
int Top(STACK S);
void Pop(STACK &S);
void Push(int x,STACK &S);
int main()
{
    return 0;
}

void MakeNull(STACK &S)
{
    S.top=maxlength;
}
//Çå¿ÕÕ»
int Empty(STACK S)
{
    if(S.top>maxlength-1)
        return 1;
    else
        return 0;
}
//ÅÐ¶ÏÊÇ·ñÎª¿Õ
int Top(STACK S)
{
    if(Empty(S))
    {
        return NULL;

    }

    else
        return (S.elements[S.top]);
}

//·µ»ØÕ»¶¥
void Pop(STACK &S)
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
//³öÕ»
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
//Ñ¹Õ»
