#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


#define MinNumber INT_MIN

struct node{
int key;
node * next;
node * Front;
};

typedef node * List;
void InsertSort(int n,List &L);


int main()
{
    List L;
    int i;
    int n;
    printf("please in the number\n");
    L=new node;
    for(i=1;i<=n;i++)
    {
        L->Front=L;
        L=L->next;
        scanf("%d"&(L.key));

    }
    InsertSort(n,L);
       for(i=1;i<=n;i++)
       {
           printf("%d ",L.key);
           L=L->next;
       }
       return 0;
}
void InsertSort(int n,List &L)
{
    int i;
    List temp,Temp;
    temp=new node;
    Temp=new node;
    L.key=MinNumber;
    Temp=L;
   for(i=1;i<=n;i++)
   {
       Temp=Temp->next;
       temp=Temp;
      while(temp->Front.key<Temp.key)
      {
          temp=temp->Front;
      }

      Temp->next=temp->next;
      Temp->Front=temp;
      temp->next=Temp;

   }
   }
