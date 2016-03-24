#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int pivot(long long a[],long long l,long long r)
{
    long long t,i=l,k=l,p,temp;
    p=a[r];
    for(k=l;k<r;k++)
    {
        if(p>a[k])
        {
            temp=a[i];
            a[i]=a[k];
            a[k]=temp;
            i++;
        }
    }
    temp=a[i];
    a[i]=a[r];
    a[r]=temp;

    return i;
}

void divider(long long a[],long long x,long long z)
{
    long long y;
    if(x<z)
    {
        y=pivot(a,x,z);
        divider(a,x,y-1);
        divider(a,y+1,z);
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
        a[i]=rand()%100;
    }
    start=clock();
    divider(a,0,n-1);
    end=clock();
    for(i=0;i<n;i++)
    {
        printf("%lld ",a[i]);
    }
    printf("Time taken= %lld\n",end-start);
}
