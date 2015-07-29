#include <stdio.h>
#include <stdlib.h>

typedef int keytype;
typedef char fields;

typedef struct
{
    keytype key;
    fields other;
}records;

struct node
{
    records data;
    node *lchild,*rchild;
};

typedef node * BST;


int depth(BST B)
{
    int depl,depr,dep;
    if(B)
    {
        depl=depth(B->lchild);
        depr=depth(B->rchild);
        dep=depl>depr?depl:depr;
        return dep;
    }
    else
        return 0;
}

int isBlance(BST B)
{
    if(B)
    {
        if(((depth(B->lchild))-(depth(B->rchild))*(depth(B->lchild))-(depth(B->rchild)))<=1)
            {return isBlance((B->lchild))&(isBlance(B->rchild));
        else
            return 0;

    }
    else
        return 1;
}
