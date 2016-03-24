
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
int bubble(long long a[],long long n)
{
    long long i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>=a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main()
{
    long long *a,n,i,start,end;
    scanf("%lld",&n);
    srand((unsigned)time(NULL));
    a=(long long int *)malloc(n*sizeof(long long int));
    for(i=0;i<n;i++)
    {
        a[i]=rand();
    }
    start=clock();
    bubble(a,n);
    end=clock();
    printf("Time taken= %lld\n", end-start);
}
