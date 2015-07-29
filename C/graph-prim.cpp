#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define MaxValue INT_MAX
#define numedges 50
#define Numvertices 10
typedef char VertexData;
typedef int EdgeData;

typedef struct node{
VertexData verlist[Numvertices];
EdgeData edge[Numvertices][Numvertices];
int n,e;
}MTGraph;




void CreatMgraph(MTGraph &G);
void Prim(MTGraph G);
int main()
{
    int i,j;
   printf("please input the graph¡®n£¬e eg:3,3\n");
   MTGraph G;
  // G=new node;
   CreatMgraph(G);

   Prim(G);
      return 0;
}


void CreatMgraph(MTGraph &G)
{
    int i,j,k,w;
    scanf("%d,%d",&G.n,&G.e);
    printf("the points name eg:abcde\n");
        getchar();
    for(i=1;i<=G.n;i++)
    {
        G.verlist[i]=getchar();

    }
    getchar();
    for(i=1;i<=G.n;i++)
        for(j=1;j<=G.n;j++)
        G.edge[i][j]=INT_MAX;
        printf("please input the edge eg:1 3 1(the first 1 means a,the 3 means c,the second 1 means the weight)\n");
    for(k=1;k<=G.e;k++)
    {
        scanf("%d %d %d",&i,&j,&w);
        G.edge[i][j]=w;
    }
}

void Prim(MTGraph G)
{
    int closset[Numvertices];
    int lowcost[numedges];
    int i,j,k;
    int Min;
    for(i=2;i<=G.n;i++)
    {
        lowcost[i]=G.edge[1][i];
        closset[i]=1;
    }
    for(i=2;i<=G.n;i++)
    {
        Min=lowcost[i];
        k=i;
        for(j=2;j<=G.n;j++)
        {
            if((lowcost[j]<Min))
            {
                Min=lowcost[j];
                k=j;
            }
        }
        printf("(%c,%c)",G.verlist[closset[k]],G.verlist[k]);
        lowcost[k]=INT_MAX;
        for(j=2;j<=G.n;j++)
        {
            if(G.edge[k][j]<lowcost[j]&&(lowcost[j]!=INT_MAX))
                {lowcost[j]=G.edge[k][j];
                closset[j]=k;
            }
        }
    }
}
