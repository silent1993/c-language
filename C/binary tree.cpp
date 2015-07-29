#include<stdio.h>
#include<stdlib.h>

int sh;
struct  node
{
	char data;
	node *lchild;
	node *rchild;
};

typedef node *Btree;

typedef node bitnode;

Btree CreatBtree()
{
     char DATA;
     Btree ctree;

    scanf("%c",&DATA);
    if(DATA=='#')
    {
        return NULL;
    }
    else
    {
    ctree=new node;
    ctree->data=DATA;
    ctree->lchild=CreatBtree();
    ctree->rchild=CreatBtree();
}
return ctree;

}
Btree findb(Btree BT,Btree m)
{
    if(BT==m)
        return NULL;
    else
    {if(BT->lchild==m)
        return BT;
    else if(BT->rchild==m)
        return BT;
    else
        {findb(BT->lchild,m);
        findb(BT->rchild,m);}

    }
    printf("no find!");
    return NULL;
}
//number 3
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
void Preorder(Btree BT)
{
    if(!isEmpty(BT))
    {
        printf("%c",BT->data);
        Preorder(BT->lchild);
        Preorder(BT->rchild);
    }
}
//前序打印

void Post(Btree BT)
{
     if(!isEmpty(BT))
    {

       Post(BT->lchild);
        Post(BT->rchild);
         printf("%c",BT->data);
    }
}
//后序打印
void constPost(Btree BT)
{
     if(!isEmpty(BT))
    {
         printf("%c",BT->data);
        constPost(BT->rchild);
        constPost(BT->lchild);

    }

}
//后序逆转
Btree Delete(char a,Btree &BT)
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
//number 4
void ifcomp(Btree BT)
{
     if(!isEmpty(BT))
   {if(isEmpty(BT->lchild)&&(!isEmpty(BT->rchild)))
      sh=0;
    else
    {
         {ifcomp(BT->lchild);
          ifcomp(BT->rchild);}

    }

}}
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

