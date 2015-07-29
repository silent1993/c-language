#include<stdio.h>
#include<stdlib.h>


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

 void CreatGraph (AdjGraph &G);
struct celltype
{
    int element;
    celltype*next;
};

struct QUEUE
{
    celltype *Front;
    celltype *Rear;
};

void MakeNull(QUEUE &Q)
{
    Q.Front=new celltype;
    Q.Front->next=NULL;
    Q.Rear=Q.Front;
}

int Empty(QUEUE Q)
{
    if(Q.Front == Q.Rear)
        return 1;
    else
        return 0;
}

void EnQueue(int x,QUEUE &Q)
{
    Q.Rear->next=new celltype;
    Q.Rear=Q.Rear->next;
    Q.Rear->element=x;
    Q.Rear->next=NULL;
}

int  DeQueue(QUEUE &Q)
{
    int i;
    celltype *tmp;
    if(Empty (Q))
    {
        printf("queue is empty");

    }
    else
    {
        tmp=Q.Front->next;
        Q.Front->next=tmp->next;
        i=Q.Front->element;
        delete tmp;
        if(Q.Front ->next==NULL)
            Q.Rear=Q.Front;
    }
    return i;
}

typedef struct{
VertexData head;
VertexData tail;
}line;
line LineList[10000];
int edgenum;
void BFSpoint(AdjGraph G);
void BFS(AdjGraph G,int i);
void SearchLine();
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

void BFSpoint(AdjGraph G)
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
            BFS(G,i);
        }
    }
}

void BFS(AdjGraph G,int i)
{
    int k;
    EdgeNode p;
    QUEUE Q;
    MakeNull(Q);
    EnQueue(k,Q);
    while(!Empty(Q));
    {
        i=DeQueue(Q);
        p=G.verlist[i].firstedge;
        while(p)
        {
            if(!visit[p->adjvex])
            {
                 LineList[++edgenum].head=G.verlist[i].vertex;
                 LineList[++edgenum].tail=G.verlist[p->adjvex].vertex;
                visit[p->adjvex]=1;
                EnQueue(p->adjvex,Q);
            }
            p=p->next;
        }
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


