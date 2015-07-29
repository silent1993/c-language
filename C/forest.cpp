#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    node *firstchild;
    node *sibling;
};

typedef node * TRee;
int i,j=1;
int le;

TRee CreatBtree()
{
     char DATA;
     TRee ctree;

    scanf("%c",&DATA);
    /*if(DATA==)
    {
        ctree=NULL;
    }*/
    if(DATA=='#')
    {
        return NULL;
    }
    else
    {
    ctree=new node;
    ctree->data=DATA;
    ctree->firstchild=CreatBtree();
    ctree->sibling=CreatBtree();
}
return ctree;

}
bool isEmpty(TRee BT)
{
    if(BT==NULL)
    {
        return true;

    }
    else
    {
        return false;
    }
}
void Preorder(TRee BT)
{
    if(!isEmpty(BT))
    {
        printf("%c",BT->data);
        Preorder(BT->firstchild);
        Preorder(BT->sibling);
    }
}
//qianxudayin
TRee finds(TRee x£¬int i)
{
    int j;
    TRee temp;
    if(i==1)
        return x->firstchild;
    else
    {
        temp=x->firstchild->sibling;
        for(j=2;j<=i;j++)
        {
            temp=temp->sibling;

        }
       return temp;
}
}
    char qianxu(char *bt)
{
    if(bt[n]!=NULL)
    {
        printf("%c",bt[n]);
       qianxu(bt[2*n]);
        qianxu(bt[2*n+1]);
    }
}

}
//zhaodaodiigeerzi

int measure(TRee TT)
{
    if(TT->firstchild)
        {le++;
        measure(TT->firstchild);}
        else if(TT->sibling)
        {
            measure(TT->sibling);

        }
    else
    {
        return le;
    }
}

int  main()
{
    char a;
    TRee BT;
  // BT=new node;
    BT=CreatBtree();
    Preorder(BT);
    int level;
    if(BT)
    {
        le=1;
        level=measure(BT);
    }
    else
        level=0;
        printf("%d",level);
}
