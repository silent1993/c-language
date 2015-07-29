#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxlength 100
typedef char datatype;

struct node
{
    datatype val;
    node * next;
};

typedef node *STACK;
void MakeNull();
void Push(datatype x, STACK &S);
void Pop(STACK &S,char &op);
char Top(STACK S);
int Empty(STACK S);
int isop(char c);
int  isHigh(char Stack_op,char now_op);
void IFOP(char now_op,  STACK &S);




int main()
{
    int strl;
    int i;
    int j=0;
    STACK S;
    S=new node;
    S->next = NULL;
    char ch[maxlength];
    char secondch[maxlength];
    printf("please input the string,for example'(2+3)/2+3*4'\n");
    scanf("%s",&ch);
    strl=strlen(ch);
    for(i=0; i<strl; i++)
    {
        if(!isop(ch[i]))
        {
            secondch[j]=ch[i];
            j++;
        }
        else
        {
            if(ch[i]!=')')
            {
                if(isHigh(Top(S), ch[i]))
                {
                    Pop(S,secondch[j]);
                    j++;
                    Push(ch[i],S);
                }
                else
                {
                    Push(ch[i],S);
                }
            }
            else
            {
                while(Top(S) != '(')
                {
                    Pop(S,secondch[j]);
                    j++;
                }
                char ccc;
                Pop(S,ccc);
            }
        }
    }
    while(!Empty(S))
    {
        Pop(S,secondch[j]);
        j++;
    }
    for(i=0; i<j; i++)
    {
        if(secondch[i]>= '0'&&secondch[i]<= '9')
            Push(secondch[i],S);
        else
            IFOP(secondch[i],S);

    }
    char Fresult;
    Pop(S,Fresult);
    printf("The final result is %d \n",Fresult-'0');
    return 0;
}



void MakeNull()
{
    STACK S;
    S=new node;
    S->next=NULL;

}

void Push(datatype x, STACK &S)
{
    STACK stk;
    stk=new node;
    stk->val=x;
    stk->next=S->next;
    S->next=stk;
}



void Pop(STACK &S,char &op)
{
    STACK stk;
    stk=new node;
    if(S->next)
    {
        op=S->next->val;
        stk=S->next;
        S->next=stk->next;
        delete stk;
    }
}




char Top(STACK S)
{
    if(S->next)
    {
        return S->next->val;

    }

}

int Empty(STACK S)
{
    if(S->next)
        return  0;
    else
        return 1;
}

int isop(char c)
{
    if((c=='+')||(c=='-')||(c=='*')||(c=='/')||(c=='(')||(c==')'))
        return 1;
    else
        return 0;
}


int  isHigh(char Stack_op,char now_op)
{
    if (((Stack_op== '+')&&(now_op== '+'))||((Stack_op== '+')&&(now_op== '-')) ||((Stack_op== '-')&&(now_op== '+'))||((Stack_op== '-')&&(now_op== '-'))||((Stack_op== '*')&&(now_op== '+'))|| ((Stack_op== '*')&&(now_op== '-')) ||((Stack_op== '*')&&(now_op== '*')) || ((Stack_op== '*')&&(now_op== '/')) ||  ((Stack_op== '/')&&(now_op== '+'))|| ((Stack_op== '/')&&(now_op== '-'))||((Stack_op== '/')&&(now_op== '*'))||((Stack_op== '/')&&(now_op== '/')))
        return 1;
    else
        return 0;
}


void IFOP(char now_op,  STACK &S)
{

    char a,b;
    int re;
    char rechar;
    switch(now_op)
    {
    case '*':
        Pop( S, a);
        Pop(S,b);
        re=(a-'0')*(b-'0');
        rechar=re + '0';
        Push(rechar, S);
        break;
    case '/':
        Pop( S, a);
        Pop(S,b);
        re=(b-'0')/(a-'0');
        rechar=re + '0';
        Push(rechar, S);
        break;
    case '+':
        Pop( S, a);
        Pop(S,b);
        re=a- '0'+b- '0';
        rechar=re + '0';
        Push(rechar, S);
        break;
    case '-':
        Pop( S, a);
        Pop(S,b);
        re=(b- '0')-(a- '0');
        rechar=re + '0';
        Push(rechar, S);
        break;
    default:
        break;
    }
}
