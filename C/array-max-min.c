#include <stdio.h>
#include <stdlib.h>
int Array[100][100];
int n;
int Min[100];
int Max[100];
int column[100];



int getsaddle(int *A,int *B)
{
    int i,j,s;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(Array[i][j]==A[i]&&Array[i][j]==B[j])
            {
                s=Array[i][j];
                return s;
            }
        }
    }
    return 0;
}

int printfsaddle(int s)
{
   int i,j,num=0;
   for(i=0;i<n;i++)
   {
      if(Min[i]==s)
      {
          if(Max[column[i]]==s)
          {
               num++;
              printf("found %d saddle\n",num);

          }

      }

   }
   return 0;
}
int main()
{
    int i,j,s;
    printf("please input the n\n");
    scanf("%d",&n);
    printf("input the array\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&Array[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
         Min[i]=Array[i][0];
        for(j=0;j<n;j++)
        {
           if(Array[i][j]<Min[i])
           {
               Min[i]=Array[i];
               column[i]=j;
           }

        }
    }
    for(j=0;j<n;j++)
    {
        Max[j]=Array[0][j];
        for(i=0;i<n;i++)
        {
            if(Array[i][j]>Max[j])
            {
                Max[j]=Array[i][j];
            }

        }
    }

     s=getsaddle(Min,Max);
     if(s)
     {
         printf("found saddle , it is %d\n",s);
         printfsaddle(s);
     }
     else
     {
         printf("no saddle\n");
     }



    return 0;
}





