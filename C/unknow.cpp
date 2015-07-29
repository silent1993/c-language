#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


#define MinNumber INT_MIN

struct node{
int key;
node * next;
};

typedef node * List;
typedef node * position;


//void InsertSort(int n,List &L);
void Insert(int n,position &p);

int main()
{
    List L;
    int i,k;
    int n;
    printf("please in the number\n");
    L=new node;
    position Temp;
    Temp=new node;
    Temp=L;
    for(i=1;i<=n;i++)
    {
        Temp=Temp->next;
        scanf("%d",&k);
        Insert(k,Temp);

    }
        Temp=L;
     for(i=1;i<=n;i++)
       {
            Temp=Temp->next;
           printf("%d ",Temp->key);
       }
   /* InsertSort(n,L);
       for(i=1;i<=n;i++)
       {
           printf("%d ",L->key);
           L=L->next;
       }*/
       return 0;
}
/*void InsertSort(int n,List &L)
{
    int i;
    List temp,Temp,TEMP;
    temp=new node;
    Temp=new node;
    L->key=MinNumber;
    TEMP=L;
   for(i=1;i<=n;i++)
   {
       TEMP=TEMP->next;
       temp=Temp=TEMP;
       if(temp->Front->key<Temp->key)
      {while(temp->Front->key>Temp->key)
      {
          temp=temp->Front;
      }
      Temp->next=temp->next;
      Temp->Front=temp;
      temp->next=Temp;

   }
   else
    continue;
   }
   }*/
void Insert(int n,position &p)
{
    position temp;
    temp=p->next;
    p->next=new node;
    p->next->key=n;
    p->next->next=temp;
}
