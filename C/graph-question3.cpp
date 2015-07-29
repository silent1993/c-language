#include<stdio.h>
#include<stdlib.h>

#include <limits.h>


#define MaxValue Int_Max
#define numedges 50

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

typedef char VertexData;
typedef int EdgeData;


typedef struct {
VertexData verlist[Numvertices];
EdgeData edge[Numvertices][Numvertices];
int n,e;
}MTGraph;
 int main()
 {

 }

 void CreatGraph (AdjGraph &G)
 {
    int i,j,k;
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
 void CreatInverse(AdjGraph G,AdjGraph &g)
 {

      int i;
     g.n=G.n;
     g.e=G.e;
     for(i=1;i<=G.n;i++)
     {
        g.verlist[i].vertex=G.verlist[i].vertex;
         g.verlist[i].firstedge=NULL;
     }
     for(i=1;i<=G.n;i++)
    {
        if(G.verlist[i].firstedge)
        {
            g.verlist[G.verlist[i].firstedge->adjvex].vertex=i;
            g.verlist[G.verlist[i].firstedge->adjvex].firstedge=G.verlist[i].firstedge->next;
        }
        else
            continue;
    }

 }
int measure(AdjGraph G)
{
    int i,n=0;
    for(i=1;i<=G.n;i++)
    {
        if(!G.verlist[i].firstedge)
        {
            n++;
        }
        else
            continue;
    }
    return n;
}

int measureJU(MTGraph G)
{
    int i,j,nI=0,nO=0,ni,no;
    for(i=1;i<=G.n;i++)
    {
        ni=0;
        no=0;
        for(j=1;j<=G.n;j++)
    {
        if(!(G.edge[i][j]))
        {
            ni++;
        }
        if(!G.edge[j][i])
            no++;
    }
    if(ni==G.n)
    {
        nI++;
    }
    else if(no==G.n)
        nO++;
    else
        continue;
}
}
