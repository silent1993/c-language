#include<stdlib.h>
#include<stdio.h>

void Sort(int n,List &L)
{
    int lowkey;
    position temp,Temp,TEMP;
    int i,j;
    TEMP=L;
    for(i=1;i<=n;i++)
    {
        TEMP=TEMP->next;
        temp=Temp=TEMP;
        lowkey=Temp->key;
        for(j=i;j<=n;j++)
        {
            if(temp->next->key<lowkey)
            {
                lowkey=temp->next->key;
                Temp=temp->next;
            }

        }
        temp=TEMP;
        Temp->next=temp->next;
        temp->next=Temp;
    }
}
