#include <stdio.h>
#include <stdlib.h>


#define Numvertices 10

 typedef char VertexData;
 typedef int EdgeData;


 int visit[Numvertices];

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
typedef struct{
VertexData head;
VertexData tail;
}line;
line LineList[10000];
int edgenum;


void CreatGraph (AdjGraph &G);
void DFSpoint(AdjGraph G);
void DFS(AdjGraph G,int i);
void SearchLine(line * L);

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


void DFSpoint(AdjGraph G)
{
    int i;
    edgenum=0;
    for(i=1;i<=G.n;i++)
    {
        visit[i]=0;
    }
    for(i=0;i<=G.n;i++)
    {
        if(!visit[i])
        {
            DFS(G,i);
        }
    }
}

void DFS(AdjGraph G,int i)
{
    EdgeNode p;
    visit[i]=1;
    p=G.verlist[i].firstedge;
    while(p)
    {
        if(!visit[p->adjvex])
        {
            LineList[++edgenum].head=G.verlist[i].vertex;
            LineList[++edgenum].tail=G.verlist[p->adjvex].vertex;
            DFS(G,p->adjvex);
        }
        p=p->next;
    }
}

void SearchLine()
{
    int i;
    VertexData v1,v2;
   printf("please the line you want to search");
   scanf("(%c,%c)",&v1,&v2);
   for(i=1;i<=edgenum;i++)
   {
       if((LineList[i].head==v1)&&(LineList[i].tail==v2))
       {
           printf("they have a line");
       }
       else
       {
           printf("they are not");
       }
   }
}


