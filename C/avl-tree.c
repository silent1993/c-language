#include <stdio.h>
#include <stdlib.h>

int unblanced= 0;
typedef int keytype;
typedef char fields;
typedef struct{
keytype key;
fields others;
}records;

struct node{
records data;
int bf;
node * lchild;
node * rchild;
};
typedef node * BST;


int DeleteAVL(BST &T,int x,int &shorter);
  void Delete(BST q,BST &r,int &shorter);
  void LeftBalance(BST &T,int &shorter);
void RightBalance(BST &T,int &shorter);

void AVLinsert (BST &T,records R,int &unblanced);
void LeftRotation(BST &T,int &unblanced);
void RightRotation (BST &T,int &unblanced);
BST searchBST(keytype k,BST F);
BST CreatBST()
{
    BST T=NULL;
    keytype key;
    scanf("%d",&key);
    records R;
    R.key=key;
    while(key)
    {
         R.key=key;
        AVLinsert(T,R,unblanced);
        scanf("%d",&key);

    }
    return T;
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
void Preorder(BST BT)
{
    if(!isEmpty(BT))
    {
        printf("%d ",BT->data.key);
        Preorder(BT->lchild);
        Preorder(BT->rchild);
    }
}
int main()
{
    printf("please in put the key\n");
    BST F;
    F=new node;
     F=CreatBST();
    Preorder(F);
     printf("which key do you want to search\n");
     keytype k;
     scanf("%d",&k);
     BST temp;
     temp=new node;
     temp=searchBST(k,F);
     if(temp)
     {
         printf("serach successfully\n");
     }
    printf("which key do you want to delete\n");
    scanf("%d",&k);
    int shorter;
    DeleteAVL(F,k,shorter);
    Preorder(F);


}

void AVLinsert (BST &T,records R,int &unblanced)
{
    if(!T)
    {
        unblanced=1;
        T=new node;
        T->data=R;
        T->lchild=T->rchild=NULL;
        T->bf=0;
    }
    else if(R.key<T->data.key)
    {
        AVLinsert(T->lchild,R,unblanced);
        if(unblanced)
            switch(T->bf)
        {
            case -1:T->bf=0;
            unblanced=0;
            break;
            case 0:T->bf=1;
            break;
            case 1:LeftRotation(T,unblanced);
            default:break;
        }

    }
    else if(R.key>T->data.key)
    {
        AVLinsert(T->rchild,R,unblanced);
        if(unblanced)
            switch(T->bf)
        {
            case -1:
            RightRotation(T,unblanced);
            break;
            case 0:T->bf=-1;
            break;
            case 1:
            T->bf=0;
            unblanced=0;
            break;
            default:break;
        }
    }
    else
        unblanced=0;
}
void LeftRotation(BST &T,int &unblanced)
{
    BST gc,lc;
    lc=T->lchild;
    if(lc->lchild)
    {
        T->lchild=lc->rchild;
        lc->rchild=T;
        T->bf=0;
        T=lc;
    }
    else
    {
        gc=lc->rchild;
        lc->rchild=gc->lchild;
        gc->lchild=lc;
        T->lchild=gc->rchild;
        gc->rchild=T;
        switch(gc->bf)
        {
            case 1:T->bf=-1;
            lc->bf=0;
            break;
            case 0:T->bf=lc->bf=0;
            break;
            case -1:T->bf=0;
            lc->bf=1;
        }
        T=gc;
    }
    T->bf=0;
    unblanced=0;
}

void RightRotation (BST &T,int &unblanced)
{
    BST gc,rc;
    rc=T->rchild;
    if(rc->rchild)
    {
        T->rchild=rc->lchild;
        rc->lchild=T;
        T->bf=0;
        T=rc;
    }
    else
    {
        gc=rc->lchild;
        rc->lchild=gc->rchild;
        gc->rchild=rc;
        T->lchild=gc->lchild;
        gc->lchild=T;
    switch(gc->bf)
        {
            case 1:T->bf=-1;
            rc->bf=0;
            break;
            case 0:T->bf=rc->bf=0;
            break;
            case -1:T->bf=0;
            rc->bf=1;
        }
        T=gc;
    }
    T->bf=0;
    unblanced=0;
}


BST searchBST(keytype k,BST F)
{
    BST p=F;
    if(p==NULL||k==p->data.key)
        return p;
    if(k<p->data.key)
        return (searchBST(k,p->lchild));
    else
        return (searchBST(k,p->rchild));
}


void LeftBalance(BST &T,int &shorter)
{
    BST gc,lc;
    lc=T->lchild;
    if(lc->lchild)
    {
        T->lchild=lc->rchild;
        lc->rchild=T;
        T->bf=0;
        T=lc;
    }
    else
    {
        gc=lc->rchild;
        lc->rchild=gc->lchild;
        gc->lchild=lc;
        T->lchild=gc->rchild;
        gc->rchild=T;
        switch(gc->bf)
        {
            case 1:T->bf=-1;
            lc->bf=0;
            break;
            case 0:T->bf=lc->bf=0;
            break;
            case -1:T->bf=0;
            lc->bf=1;
        }
        T=gc;
    }
    T->bf=0;
    shorter=0;
}
void RightBalance(BST &T,int &shorter)
{
     BST gc,rc;
    rc=T->rchild;
    if(rc->rchild)
    {
        T->rchild=rc->lchild;
        rc->lchild=T;
        T->bf=0;
        T=rc;
    }
    else
    {
        gc=rc->lchild;
        rc->lchild=gc->rchild;
        gc->rchild=rc;
        T->lchild=gc->lchild;
        gc->lchild=T;
    switch(gc->bf)
        {
            case 1:T->bf=-1;
            rc->bf=0;
            break;
            case 0:T->bf=rc->bf=0;
            break;
            case -1:T->bf=0;
            rc->bf=1;
        }
        T=gc;
    }
    T->bf=0;
    shorter=0;
}
  void Delete(BST q,BST &r,int &shorter)
  {
      if(r->rchild==NULL)
      {
          q->data=r->data;
          q=r;
          r=r->lchild;
          delete q;
          shorter=1;
      }
      Delete(q,r->rchild,shorter);
      if(shorter==1)
        RightBalance(r,shorter);
  }

int DeleteAVL(BST &T,int x,int &shorter)
{
    int k;
    BST q;
    if(T==NULL)
    {
        printf("there is no tree");
        return 0;
    }
    else if(x<T->data.key)
    {
        k=DeleteAVL(T->lchild,x,shorter);
        if(shorter==1)
            LeftBalance(T,shorter);
        return k;
    }
    else if(x>T->data.key)
    {
        k=DeleteAVL(T->rchild,x,shorter);
        if(shorter==1)
        {
            RightBalance(T,shorter);
        }
        return k;
    }
    else
    {
        q=T;
        if(T->rchild==NULL)
        {
            T=T->lchild;
            delete q;
            shorter=1;
        }
        else if(T->lchild==NULL)
        {
            T=T->rchild;
            delete q;
            shorter=1;
        }
        else
        {
            Delete(q,q->lchild,shorter);
            if(shorter==1)
            {
                LeftBalance(T,shorter);
            }
            T=q;
        }
        return 1;


    }
}



