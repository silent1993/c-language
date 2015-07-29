#include<stdio.h>
#include<stdlib.h>


#define Numvertices 10

 typedef char VertexData;
 typedef int EdgeData;

 struct node{
 int adjvex;
 EdgeData cost;
 struct node *next;
 };
 typedef node * EdgeNode;
 typedef struct{
 VertexData vertex;
 EdgeNode firstedge;
 }VertexNode;
 typedef struct {
 VertexNode verlist[Numvertices];
 int n,e;
 }AdjGraph;

 void CreatGraph (AdjGraph &G);

 int main()
 {

 }

 void CreatGraph (AdjGraph &G)
 {
    int i;
     scanf("%d,%d",&G.n,&G.e);

     for(i=1;i<=G.n;i++)
     {
         scanf("%c",&G.verlist[i].vertex);
         G.verlist[i].firstedge=NULL;
     }

 for(i=1;i<=G.e;i++)
 {
     int tail,head,weight;
     scanf("%d %d %d",&tail,&head,&weight);
     EdgeNode p=new node;
     p->adjvex=head;
     p->cost=weight;
     p->next=G.verlist[tail].firstedge;
     G.verlist[tail].firstedge=p;
     p=new node;
     p->adjvex=tail;
     p->cost=weight;
     p->next=G.verlist[head].firstedge;
     G.verlist[head].firstedge=p;
 }
 }
