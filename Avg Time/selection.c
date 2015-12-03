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
int selection(long long a[],long long n)
{
    long long i,j,min,minpos,temp;
    for(i=0;i<n;i++)
    {
        min=a[i];
        for(j=i;j<n;j++)
        {
            if(min>=a[j])
            {
                min=a[j];
                minpos=j;
            }
        }
        temp=a[i];
        a[i]=min;
        a[minpos]=temp;
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
    }print(a,n);
    start=clock();
    selection(a,n);
    end=clock();
    print(a,n);
    printf("Time taken= %lld\n", end-start);
}

