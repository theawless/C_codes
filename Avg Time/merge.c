#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int print(long long a[],long long n)
{
    long long i;
    for(i=0;i<n;i++)
    {
        printf("%lld\n",a[i]);
    }printf("\n");
}
int combine(long long a[],long long p,long long q,long long r)
{
    long long *left,*right,i,j,k;
    left=(long long int *)malloc((q-p+2)*sizeof(long long int));
    right=(long long int *)malloc((r-q+2)*sizeof(long long int));
    for(i=p;i<=q;i++)
    {
        left[i-p]=a[i];
    }
    for(j=q+1;j<=r;j++)
    {
        right[j-q-1]=a[j];
    }
    i=0;j=0;k=p;
    while(i<=q-p && j<=r-q-1)
    {
        if(left[i]>right[j])
        {
            a[k]=right[j];
            j++;k++;
        }
        if(left[i]<=right[j])
        {
            a[k]=left[i];
            i++;k++;
        }
    }
    while(i<=q-p)
    {
        a[k]=left[i];
        i++;k++;
    }
    while(j<=r-q-1)
    {
        a[k]=right[j];
        j++;k++;
    }
    free(left);
    free(right);
}
int divide(long long a[],long long low,long long high)
{
    if(low<high)
    {
        long long mid;
        mid=(low+high)/2;
        divide(a,low,mid);
        divide(a,mid+1,high);
        combine(a,low,mid,high);
    }
}
int main()
{
    long long *a,n,i,start,end;
    scanf("%lld",&n);
    a=(long long int *)malloc(n*sizeof(long long int));
    printf("\n");
    srand((unsigned)time(NULL));
    for(i=0;i<n;i++)
    {
        a[i]=rand();
    }
    start=clock();
    divide(a,0,n-1);
    end=clock();
    printf("Time taken= %lld\n", end-start);
}

