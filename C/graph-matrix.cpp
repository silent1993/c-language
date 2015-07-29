#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define MaxValue Int_Max
#define numedges 50
#define Numvertices 10
typedef char VertexData;
typedef int EdgeData;


typedef struct node{
VertexData verlist[Numvertices];
EdgeData edge[Numvertices][Numvertices];
int n,e;
}MTGraph;

//
void CreatMgraph(MTGraph &G);
void NewNode(MTGraph &G,VertexData v);
void DelNode(MTGraph &G,VertexData v);
void SetSuce(MTGraph G,VertexData v1,VertexData v2);
void Succ(MTGraph G,VertexData v);
void pre(MTGraph G,VertexData v);
bool IsEdge(MTGraph G,VertexData v1,VertexData v2);
int main()
{
    int i,j;
   printf("please input the graph\n");
   MTGraph G;
  // G=new node;
   CreatMgraph(G);

   for(i=0;i<=Numvertices;i++)
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
    for(i=1;i<=G.n;i++)
    {
        G.verlist[i]=getchar();

    }
    getchar();
    for(i=1;i<=G.n;i++)
        for(j=1;j<=G.n;j++)
        G.edge[i][j]=0;
    for(k=1;k<=G.e;k++)
    {
        scanf("%d %d %d",&i,&j,&w);
        G.edge[i][j]=w;
        G.edge[j][i]=w;
    }
}
void NewNode(MTGraph &G,VertexData v)
{
    G.n++;
    G.verlist[G.n]=v;

}
void DelNode(MTGraph &G,VertexData v)
{
    int i;
    for(i=1;i<=G.n;i++)
    {
        if(G.verlist[i]==v)
        {
            for(int j=1;j<=G.n;j++)
            {
               if(j!=i)
                {G.edge[i][j]=0;
            G.edge[j][i]=0;}

        }
    }

}
void SetSuce(MTGraph &G,VertexData v1,VertexData v2)
{
    int i,j;
    i=j=1;
    while(G.verlist[i]!=v1)
        i++;
    while(G.verlist[j]!=v2)
        j++;
    G.edge[i][j]=1;

}
void Succ(MTGraph G,VertexData v)
{
    int i,j,k=1;
     while(G.verlist[i]!=v)
        k++;
    for(i=1;i<=G.n;i++)
    {
        if(G.edge[k][i])
            printf("%c "G.verlist[i]);
    }

}
void pre(MTGraph G,VertexData v)
 {int i,j,k=1;
     while(G.verlist[i]!=v)
        k++;
    for(i=1;i<=G.n;i++)
    {
        if(G.edge[i][k])
            printf("%c "G.verlist[i]);
    }

}
bool IsEdge(MTGraph G,VertexData v1,VertexData v2);
{
    int i=1,j=1;
     while(G.verlist[i]!=v1)
        i++;
    while(G.verlist[j]!=v2)
        j++;
        if(G.edge[i][j])
            return true;
        else
            return false;
}
