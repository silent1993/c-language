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
BST searchBST(keytype k,BST F);
void InsertBST(records R,BST &F);
int main()
{

}
BST searchBST(keytype k,BST F)
{
    BST p=F;
    if(p==NULL||k==p->data.key)
        return p;
    if(k<p->data.key)
        return(searchBST(k,p->lchild));
    else
        return (searchBST(k,p->rchild));

}

void InsertBST(records R,BST &F)
{
    if(F==NULL)
    {
        F=new node;
        F->data=R;
        F->lchild=NULL;
        F->rchild=NULL;
    }
    else if(R.key<(F->data.key))
        InsertBST(R,F->lchild);
    else if(R.key>F->data.key)
        InsertBST(R,F->rchild);
}
