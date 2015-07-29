#include<stdio.h>
#include<stdlib.h>

typedef char datatype;
struct node
{
    struct node *lchild;
    struct node *rchild;
    datatype data;
};


typedef  node *Btree;


Btree Delete(datatype a,Btree &BT)
{


    if(BT==NULL)
    {
        return NULL;
    }
    else if(BT->data==a)

    {
        BT=NULL;
        return BT;
    }
    else
    {
        Delete(a,BT->lchild);
        Delete(a,BT->rchild);
    }
}
Btree CreatBtree()
{
    char DATA;
    Btree root;

    scanf("%c",&DATA);
    if(DATA=='#')
    {
        return NULL;
    }
    else
    {
        root=new node;
        root->data=DATA;
        root->lchild=CreatBtree();
        root->rchild=CreatBtree();
    }
    return root;

}

Btree  Empty(Btree BT)
{
    BT->lchild=NULL;
    BT->rchild=NULL;
    BT->data=NULL;
}


bool isEmpty(Btree BT)
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

Btree Lchild(Btree BT)
{
    if(BT->lchild==NULL)
        return NULL;
    return BT->lchild;
}


Btree Rchild(Btree BT)
{
    if(BT->rchild==NULL)
        return NULL;
    return BT->rchild;
}

datatype Data(Btree BT)
{
    return BT->data;
}


void Preorder(Btree BT)
{
    if(!isEmpty(BT))
    {
        printf("%c",BT->data);
        Preorder(BT->lchild);
        Preorder(BT->rchild);
    }
}
void Post(Btree BT)
{
    if(!isEmpty(BT))
    {

        Post(BT->lchild);
        Post(BT->rchild);
        printf("%c",BT->data);
    }
}
void middle(Btree BT)
{
    if(!isEmpty(BT))
    {

        Post(BT->lchild);
        printf("%c",BT->data);
        Post(BT->rchild);

    }
}
int  main()
{
    char a;
    Btree BT,head;
    head=BT;
    BT=CreatBtree();
    Preorder(BT);
    printf("\n");


    /* constPost(BT);
      printf("\n");
      Post(BT);
       printf("\n");

      printf("dsf");
     Preorder(head);*/
    getchar();
    scanf("%c",&a);
    Delete(a,BT);
    Preorder(BT);
    return 0;
}
