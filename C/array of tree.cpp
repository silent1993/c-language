#include<stdio.h>
#include<stdlib.h>

#define max 100
char BTree[max];

int i;
int n;
char  CreatBtree()
{
    char tree[max];
char a;
scanf("%c",&a);
if(a=='*')
{
   tree[i]=NULL;
   i++;
}

else
{

    tree[i]=a;
    i++;
}

return *tree;
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

int main()
{
    i=0;
    int l;
    printf("in put the number of leaves");
    scanf("%d",&l);
    getchar();
    while(i!=l)
        *BTree=CreatBtree();

        printf("is full");
    while(i)
    {
        printf("%c",BTree[i]);
        i--;
    }
    return 0;


}


