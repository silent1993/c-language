#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define MaxValue Int_Max
#define numedges 50
#define numvertices 10
typedef char VertexData;
typedef int EdgeData;

 struct node{
 int adjvex;
 EdgeData cost;
 struct node *next;
 };
 typedef node * EdgeNode;
 struct Node{
 VertexData vertex;
 EdgeNode firstedge;
 };
 typedef Node VertexNode;
 struct NODE{
 VertexNode verlist[numvertices];
 int n,e;
 };
 typedef NODE  AdjGraph;

typedef struct {
VertexData verlist[numvertices];
EdgeData edge[numvertices][numvertices];
int n,e;
 }MTGraph;
//
void CreatMgraph(MTGraph &G);
void transJUtoL(AdjGraph &g);
int main()
{
    int i,j;
   printf("please input the graph\n");
   MTGraph G;
   CreatMgraph(G);

   for(i=0;i<numvertices;i++)
   {
       if(G.verlist[i])
       {
           printf("%c",G.verlist[i]);
       }
       else
        break;
   }
      return 0;
}


void CreatMgraph(MTGraph &G)
{
    int i,j,k,w;
    scanf("%d,%d",&G.n,&G.e);
    for(i=0;i<G.n;i++)
    {
        G.verlist[i]=getchar();

    }
    getchar();
    for(i=1;i<=G.n;i++)
        for(j=0;j<G.n;j++)
        G.edge[i][j]=0;
    for(k=1;k<=G.e;k++)
    {
        scanf("%d %d %d",&i,&j,&w);
        G.edge[i][j]=w;
        G.edge[j][i]=w;
    }
}


void transJUtoL(AdjGraph &g,MTGraph &G)
{
     int tail,head,weight;
    int i,j;
    g.n=G.n;
    g.e=G.e;
    for(i=1;i<=G.n;i++)
    {
        g.verlist[i].vertex=G.verlist[i];
        g.verlist[i].firstedge=NULL;
    }
    for(i=1;i<=G.n;i++)
        for(j=1;j<=G.n;j++)
    {
        if(G.edge[i][j])
        {
            tail=j;
            head=i;
            weight=G.edge[i][j];
           EdgeNode p=new node;
        p->adjvex=tail;
        p->cost=weight;
        p->next=g.verlist[head].firstedge;
        g.verlist[head].firstedge=p;
        }
    }
}
