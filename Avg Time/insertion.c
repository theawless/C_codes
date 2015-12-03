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
int insertion(long long a[],long long n)
{
    long long i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(a[j]>temp && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
int main()
{
    long long *a,n,i,start,end;
    scanf("%lld",&n);
    a=(long long int *)malloc(n*sizeof(long long int));
    srand((unsigned)time(NULL));
    for(i=0;i<n;i++)
    {
        a[i]=rand();
    }
    start=clock();
    insertion(a,n);
    end=clock();
    printf("Time taken= %lld\n", end-start);
}
