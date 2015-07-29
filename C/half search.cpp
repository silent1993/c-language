#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


#define MinNumber INT_MIN
#define Maxsize 100
void InsertSort(int n);
int A[Maxsize];
int HalfSearch(int k,int last);
void BehindMove(int j,int low);
//从小到大排列
int main()
{
    int i;
    int n;
    printf("please input the n\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&A[i]);
    InsertSort(n);
    for(i=1;i<=n;i++)
        printf("%d ",A[i]);
        return 0;
}


void InsertSort(int n)
{
    int i,j,k;
    A[0]=MinNumber;
   for(i=1;i<=n;i++)
   {
       if(A[i]>A[i-1])
        continue;
       else if(A[i]<=A[1])
       {
           int temp;
           temp=A[i];
        for(k=i-1;k>=1;k--)
       {
           A[k+1]=A[k];
       }
       A[1]=temp;
       }
       else
       {j=HalfSearch(A[i],i-1);
       BehindMove(i,j+1);

   }
   }
}
int HalfSearch(int k,int last)
{
    int low,up,mid;
    low=1;
    up=last;
    while(low<up)
    {
        mid=(low+up)/2;
        if(A[mid]==k)
            return mid;
        else if(A[mid]<k)
            low=mid+1;
        else
            up=mid-1;
    }
    return low;
}

void BehindMove(int j,int low)
{
    int k;
    int temp;
           temp=A[j];
        for(k=j-1;k>=low;k--)
       {
           A[k+1]=A[k];
       }
       A[low]=temp;
}
