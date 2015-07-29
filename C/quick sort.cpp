int FindPivot(int i,int j)


{
    int firstkey;
    int k;
    firstkey=A[i];
    for(k=i+1;k<=j;k++)
    {
        if(A[k]>firstkey)
            return k;
        else if(A[k]<firstkey)
            return i;

    }
    return 0;
}
int Partition(int i,int j,int pivot)
{
    int l,r;
    l=i;
    r=j;
    do{

        while(A[l]<pivot)
            l=l+1;
        while(A[r]>=pivot)
            r=r-1;
     Swap(A[l],A[r]);
    }while(l<=r);
    return 1;
}

void QuickSortb(int i,int j)
{
    int pivot;
    int pivotindex;
    int k;
    pivotindex=FindPivot(i,j);
    if(pivotindex)
    {
        pivot=A[pivotindex];
        k=Partition(i,j,pivot);
        QuickSortb(i,k-1);
    }
}
void QuickSortf(int i,int j)
{
    int pivot;
    int pivotindex;
    int k;
    pivotindex=FindPivot(i,j);
    if(pivotindex)
    {
        pivot=A[pivotindex];
        k=Partition(i,j,pivot);
        QuickSortf(k,j);
    }
}
int main()
{
    Partition(1,n,A[j]);
    if((n-j)>(j-1))
        QuickSortf(1,j);
    else
        QuickSortb(j,n);
    printf("%d",A[j]);
}
