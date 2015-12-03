#include<stdio.h>

int n,heapsize=0;
int buildheap(int a[])
{
    printf("Inside build heap");
    int i;
    for(i=n/2;i>=1;i--)
    {
        heapify(a,i);
    }

}

int heapify(int a[],int i)
{
    int r,l,maxpos,temp;
    r=(i*2)+1;
    l=i*2;
    printf("inside heapify");
    if(l<=heapsize && a[l]<a[i])
    {
        maxpos=l;
    }
    else
    {
        maxpos=i;
    }
    if(r<=heapsize && a[r]<a[maxpos])
    {
        maxpos=r;
    }

    if(i!=maxpos)
    {
        temp=a[maxpos];
        a[maxpos]=a[i];
        a[i]=temp;
        printf("Calling heapify again");
        heapify(a,maxpos);
    }
}

int main()
{
    int i,j,temp,arr[101];
    printf("Enter total num");
    scanf("%d",&n);
    printf("Enter the numbers");

    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Going in");

    heapsize=n;

    buildheap(arr);
    printf("\n");
    for(i=1;i<=n;i++)
    {
        printf("%d ",arr[i]);
    }printf("\n");
    for(i=n;i>=2;i--)
    {
        temp=arr[1];
        arr[1]=arr[i];
        arr[i]=temp;
        heapsize=heapsize-1;
        printf("\n");
    for(j=1;j<=n;j++)
    {
        printf("%d ",arr[j]);
    }printf("\n");
        heapify(arr,1);
    }
    printf("done the shit");
    printf("\n");
    for(i=1;i<=n;i++)
    {
        printf("%d ",arr[i]);
    }
}
