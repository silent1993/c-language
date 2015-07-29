#include<stdio.h>
#include<stdlib.h>


 #define n 100
 #define m 2*(reaf)-1


 struct  haffmantree
 {
     double weight;
     int lchild;
     int rchild;
     int parent;
 };


 typedef haffmantree HT[root];


 void SelectMin(HT T,int n,in &p1,int &p2)
 {
     int i,j;
     for(i=1;i<=n;i++)
     {
         if(T[i].parent == -1)
         {
             p1=i;
             break;
         }
     }
     for(j=i+1;j<=n;j++)
        if(T[j].parent == -1)
     {
         p2=j;
         break;
     }
     for(i=1;i<=n;i++)
        if((T[p1].weight>T[i].wight)&&(T[i].parent == -1)&&(p1 != i))
        p1=i;
     for (j=1;j<=n;j++)
        if((T[p2].weight>T[j].wight)&&(T[i].parent == -1)&&(p2 != j))
        p2=j;
 }


 void CreatHT(HT &T)
 {
     int i,p1,p2;
     INsert(T);
     for(i=n;i<=m;i++)
     {
         SelectMin(T,i-1,p1,p2);
         T[p1].parent=T[p2].parent=i;
         T[i].lchild=p1;
         T[i].rchild=p2;
         T[i].weight=T[p1].weight +T[p2].weight;
     }
 }


