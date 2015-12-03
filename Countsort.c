#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int *c,*b,n,max=-1,*a,i;
    scanf("%d",&n);
    clock_t end,start;
    a=(int *)malloc(n*sizeof(int));
    srand(time(NULL));
    for(i=0;i<n;i++)
    {
        a[i]=rand();
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    b=(int *)malloc((max+1)*sizeof(int));
    start=clock();
    for(i=0;i<=max;i++)
    {
        b[i]=0;
    }
    for(i=0;i<n;i++)
    {
        b[a[i]]++;
    }
    for(i=1;i<=max;i++)
    {
        b[i]+=b[i-1];
    }
    c=(int *)malloc(n*sizeof(int));
    for(i=n-1;i>=0;i--)
    {
        c[b[a[i]]-1]=a[i];
        b[a[i]]--;
    }
    end=clock();
    for(i=0;i<n;i++)
    {
        printf("%d ",c[i]);
    }
    free(a);free(b);free(c);
    printf("\nTime take is %ld",end-start);
}
