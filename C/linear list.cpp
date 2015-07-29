#include <stdio.h>
#include <stdlib.h>

#define maxlength 100
typedef int elementtype;
typedef int position;

struct node
{
    elementtype elements[maxlength];
    int last;

};
typedef node LIST;
position END(LIST L);
void Insert (int x,position p,LIST &L);
void Delete (position p,LIST &L);
position Locate(int x,LIST L);
position First(LIST L);
position Next(position p,LIST L);
position Previous(position p,LIST L);
position MakeNull(LIST &L);
position Retrieve(position p,LIST L);
void Creat(LIST &L);
void Print(LIST L);

int main()
{
    LIST L;
    int n;
    printf("If you want to make a list ,please enter 1\n");
    scanf("%d",&n);
    if(n==1)
    {
        Creat(L);
    }

    printf("the first is %d\n",L.elements[First(L)]);
    printf("the end is %d\n",L.elements[END(L)]);
    Print(L);
    printf("\n");
    Insert(8,8,L);
    Print(L);
    printf("\n");
    Delete(9,L);
    Print(L);
    printf("\n");


    return 0;

}
position END(LIST L)
{
    return (L.last);
}
//返回末尾
void Insert(int x,position  p, LIST &L)
{
    int q;
    if (L.last >= maxlength - 1)
    {
        printf("the chain is full\n");

    }
    else if ((p>L.last + 1) || (p<1))
    {
        printf("erro,the position doesn't exist\n");

    }
    else
    {
        for (q = L.last; q >= p; q--)
            L.elements[q + 1] = L.elements[q];
        L.last = L.last + 1;
        L.elements[p] = x;
    }
}
//插入
void  Delete(position  p , LIST &L)
{
    position q;
    if ((p>L.last) || (p<1))
        printf("position doesn'teist\n");
    else
    {
        L.last = L.last - 1;
        for (q = p; q <= L.last; q++)
        {
            L.elements[q] = L.elements[q + 1];
        }
    }
}
//删除指定位置元素

position Locate(int x, LIST L)
{
    position q;
    for (q = 1; q <= L.last; q++)
        if (L.elements[q] == x)
            return q;
    return L.last + 1;
}
//返回指定元素的位置
position First(LIST L)
{
    return 1;
}

//返回初始元素位置

position Next(position p, LIST L)
{
    if (p == L.last)
        printf("no next position\n");
    else
        return (p + 1);

}
//返回指定位置的下一个位置
position Previous(position p, LIST L)
{
    if (p == 1)
        printf("no previous position\n");
    else
        return(p - 1);
}
//返回指定位置的前一个位置

position MakeNull(LIST &L)
{
    L.last = 0;
}
//将线性表置空
position Retrieve(position p, LIST L)
{
    if ((p>L.last) || (p<1))
        printf("position doesn'teist\n");
    else
        return L.elements[p];
}
//返回指定位置元素
void Creat(LIST &L)
{
    int i;

    for (i = 1; i <= 15; i++)
    {
        L.elements[i] = i*i;
        L.last = i;
    }
}
//制造线性表
void Print(LIST L)
{
    int i;
    for (i = 1; i <= L.last; i++)
        printf("%d ", L.elements[i]);

}
//打印线性表
