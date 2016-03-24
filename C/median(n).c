#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int pivot(int a[], int p, int r)
{
    int pivot=a[r],q=p,temp,i;
    for(i=p;i<r;i++)
    {
        if(a[i]<pivot)
        {
            temp=a[i];
            a[i]=a[q];
            a[q]=temp;
            q++;
        }
    }
    temp=a[r];
    a[r]=a[q];
    a[q]=temp;
    return q;
}

int median(int a[],int p,int r,int i)
{
        if(p==r)
        {
            return a[p];
        }
        int q,k;
        q=pivot(a,p,r);
        k=q-p+1;
        if(k==i)
        {
            return a[q];
        }
        else if(k>i)
        {
            return median(a,p,q-1,i);
        }
        else
        {
            return median(a,q+1,r,i-k);
        }
}

int main()
{
    int ans,*a,c,n;
    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*(n+1));
    srand(time(NULL));
    for(c=0;c<n;c++)
    {
        scanf("%d",&a[c]);
        //a[c]=rand();
    } clock_t end,start;
    start=clock();
    ans=median(a,0,n-1,(n+1)/2);
    end=clock();
    printf("\n%d",ans);
    printf("\n\nTime taken= %ld",end-start);
}
