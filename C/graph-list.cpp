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
void NewNode(AdjGraph &G,VertexData v);
void DelNode(AdjGraph &G,VertexData v);
void SetSuce(AdjGraph G,VertexData v1,VertexData v2);
void Succ(AdjGraph G,VertexData v);
void pre(AdjGraph G,VertexData v);
bool IsEdge(AdjGraph G,VertexData v1,VertexData v2);
void CreatInverse(AdjGraph G,AdjGraph &g);
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
     p->adjvex=tail;
     p->cost=weight;
     p->next=G.verlist[head].firstedge;
     G.verlist[head].firstedge=p;
 }
 }
void NewNode(AdjGraph &G,VertexData v)
{
    G.n++;
    G.verlist[G.n].vertex=v;
    G.verlist[G.n].firstedge=NULL;
}
void DelNode(AdjGraph &G,VertexData v)
{
    int i;
    for(i=1;i<=G.n;i++)
    {
        if(G.verlist[i].vertex==v)
        {
            G.verlist[i].firstedge=NULL;
            G.verlist[i].vertex=0;
        }
    }

}


void SetSuce(AdjGraph G,VertexData v1,VertexData v2,int weight)
{
    int i,j;
    for(i=1;i<=G.n;i++)
    {
        if(G.verlist[i].vertex==v1)
        {
            for(j=1;j<=G.n;j++)
            {
                if(G.verlist[j].vertex==v2)
                {EdgeNode p=new node;
                p->adjvex=j;
                p->cost=weight;
                p->next=G.verlist[i].firstedge;
                G.verlist[i].firstedge=p;
                G.e++;
                break;}


            }
            break;
        }
    }
}
void Succ(AdjGraph G,VertexData v)
{
   int i;
   for(i=1;i<=G.n;i++)
   {
       if(G.verlist[i].vertex==v)
       {
           EdgeNode p=new node;
           p=G.verlist[i].firstedge;
           while(p->next)
           {
               printf("%d",p->adjvex);
               p=p->next;
           }
       }
   }
}
void CreatInverse(AdjGraph G,AdjGraph &g)
 {

      int i;
     g.n=G.n;
     g.e=G.e;
     EdgeNode p=new node;
     for(i=1;i<=G.n;i++)
     {
        g.verlist[i].vertex=G.verlist[i].vertex;
         g.verlist[i].firstedge=NULL;
     }
//首先初始化，将所有顶点存入顶点表
     for(i=1;i<=G.n;i++)
    {
        while(G.verlist[i].firstedge)//如果存在边表
        {
             EdgeNode p=new node;
             p->cost=G.verlist[i].firstedge->cost;
             p->adjvex=i;
             p->next=g.verlist[G.verlist[i].firstedge->adjvex].firstedge;
             g.verlist[G.verlist[i].firstedge->adjvex].firstedge=p;
        }
    }
 }
void pre(AdjGraph G,VertexData v)
{
    AdjGraph g;
    CreatInverse( G,g);
    int i;
   for(i=1;i<=G.n;i++)
   {
       if(g.verlist[i].vertex==v)
       {
           EdgeNode p=new node;
           p=g.verlist[i].firstedge;
           while(p->next)
           {
               printf("%d",p->adjvex);
               p=p->next;
           }
       }
   }
}


bool IsEdge(AdjGraph G,VertexData v1,VertexData v2)
{
    int i,j;
    for(i=1;i<=G.n;i++)
    {
        if(G.verlist[i].vertex==v1)
        {
            for(j=1;j<=G.n;j++)
            {
                if(G.verlist[j].vertex==v2)
                {EdgeNode p=new node;
                p=G.verlist[i].firstedge;
                while(p)
                {
                    if(p->adjvex==j)
                        return true;
                    else
                        p=p->next;
                }
                return false;
                }


            }
            break;
        }
    }
}
