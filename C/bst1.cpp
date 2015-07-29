#include <stdio.h>
#include <stdlib.h>

typedef int keytype;
typedef char fields;

typedef struct
{
    keytype key;
    fields other;
}records;
int Find;
struct node
{
    records data;
    node *lchild,*rchild;
};

typedef node * BST;
int compare(BST F);
void Preorder(BST BT);
bool isEmpty(BST BT);



int main()
{

}

int compare(BST F)
{
    BST p;

    p=F;
    keytype k;
    k=p->data.key;
    if(k<=p->lchild->data.key||k>=p->rchild->data.key)
        return 0;
    else
        return 1;


}

bool isEmpty(BST BT)
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
void test(BST BT)
{
    int t;
    if(!isEmpty(BT))
    {
       t=compare(BT);
       if(t==0)
       {
           printf("no");
           return ;
       }
        test(BT->lchild);
        test(BT->rchild);
    }
}

BST searchBST(keytype k,BST F)
{
    BST p=F;
    if(p==NULL)
    {
        Find=0;
            return p;
    }
    if(k<p->data.key)
        return(searchBST(k,p->lchild));
    if(k>p->data.key)
        return (searchBST(k,p->rchild));
    else
    {
        Find=1;
        return p;
    }
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
