#include <iostream>
#include <cstdio>
#include<string.h>

using namespace std;
int n,m,w[1001][1001],prev[1001],queue[1001],Time[1001],l=0,r=0,Pos[1001],path[1001];
void init()
{
    int i,a,b,c;
    scanf("%d%d",&n,&m);
    for (i=1; i<=m; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        w[a][b]=c;
        prev[b]++;
    }
}
inline void Newq(int v)
{
    r++;
    queue[r]=v;
}
inline void Del(int v)
{
    int i;
    for (i=1; i<=n; i++)
        if (w[v][i])
        {
            prev[i]--;
            if (!prev[i])
                Newq(i);
        }
}
void topo()
{
    for (int i=1; i<=n; i++)
        if (!prev[i])
            Newq(i);
    while (r<n)
    {
        l++;
        Del(queue[l]);
    }
}
void crucialpath()
{

    int i,j;
    memset(Time,0,sizeof(Time));
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
            if ((w[j][queue[i]]) && (Time[j]+w[j][queue[i]]>Time[queue[i]]))
            {
                Time[queue[i]]=Time[j]+w[j][queue[i]];
                Pos[queue[i]]=j;
            }
}
void print()
{
    printf("%d\n",Time[n]);
    int i=n,k=0;
    while (i!=1)
    {
        k++;
        path[k]=i;
    }
    for (i=k; i>1; i--)
        printf("%d ",path[i]);
    printf("%d\n",path[1]);
}
int main()
{
    init();
    topo();
    crucialpath();
    print();
    return 0;
}
