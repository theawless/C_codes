#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int print(long long a[],long long n)
{
    long long i;
    for(i=1;i<=n;i++)
    {
        printf("%lld\n",a[i]);
    }printf("\n");
}
int heapify(long long a[],long long i,long long heapsize)
{
    long long l=2*i, r=(2*i)+1,temp,pos=i;

    if(l<=heapsize && a[l]>a[i])
    {
        pos=l;
    }
      if(r<=heapsize && a[r]>a[pos])
    {
        pos=r;
    }

    if(i!=pos)
    {
        temp=a[i];
        a[i]=a[pos];
        a[pos]=temp;
        heapify(a,pos,heapsize);
    }
}
int build(long long a[], long long n)
{
    long long i;
    for(i=n/2;i>=1;i--)
    {
        heapify(a,i,n);
    }
}
int heapsort(long long a[],long long n)
{
    long long temp,heapsize=n,i;
    build(a,n);
    for(i=n;i>=2;i--)
    {
        temp=a[1];
        a[1]=a[i];
        a[i]=temp;
        heapsize--;
        heapify(a,1,heapsize);
    }
}
int main()
{
    long long *a,n,i,start,end;
    scanf("%lld",&n);
    a=(long long int *)malloc((n+1)*sizeof(long long int));
    srand((unsigned)time(NULL));
    for(i=1;i<=n;i++)
    {
        a[i]=rand();
    }
    start=clock();
    heapsort(a,n);
    end=clock();
    printf("Time taken= %lld\n", end-start);
}
