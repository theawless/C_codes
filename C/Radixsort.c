#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int countsort(int a[], int ten, int n)
{
    int i;
    int b[10]={0},*c=(int *)malloc(n*sizeof(int));
    for(i=0;i<10;i++)
    {
        b[i]=0;
    }
    for(i=0;i<n;i++)
    {
        b[((a[i]/ten)%10)]++;
    }
    for(i=1;i<10;i++)
    {
        b[i]+=b[i-1];
    }//printf("1");
    for(i=n-1;i>=0;i--)
    {
        c[b[((a[i]/ten)%10)]-1]=a[i];
        b[((a[i]/ten)%10)]--;
    }
    for(i=0;i<n;i++)
    {
        a[i]=c[i];
    }
    free(c);
}
int main()
{
    int *d,maxdigit=0,*c,*b,n,max=-10000,*a,i;
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
    }start=clock();
    while(max>0)
    {
        maxdigit++; max=max/10;
    } int m=1,ten=1;
    while(m<=maxdigit)
    {
        countsort(a,ten,n);
        m++;ten=ten*10;
    }
    end=clock();
    free(a);
    printf("\nTime take is %ld",end-start);
}
