#include<stdio.h>
int n,heapsize=0;
int buildheap(int a[])
{
    int i;
    for(i=n/2;i>=1;i--)
    {
        heapify(a,i);
    }

}
int insert(int a[],int n)
{
    printf("Enter the number to be inserted");
    int temp,p,num,pos;
    scanf("%d",&num);
    pos=n+1;p=pos/2;
    a[pos]=num;
    while(a[p]<a[pos])
    {
        temp=a[p];
        a[p]=a[pos];
        a[pos]=temp;
        pos=p;p=pos/2;
    }

}
int heapify(int a[],int i)
{
    int r,l,maxpos,temp;
    r=(i*2)+1;
    l=i*2;
    if(l<=heapsize && a[l]>a[i])
    {
        maxpos=l;
    }
    else
    {
        maxpos=i;
    }
    if(r<=heapsize && a[r]>a[maxpos])
    {
        maxpos=r;
    }

    if(i!=maxpos)
    {
        temp=a[maxpos];
        a[maxpos]=a[i];
        a[i]=temp;
        heapify(a,maxpos);
    }
}

int main()
{
    int i,j,temp,arr[101];
    printf("Enter total num ");
    scanf("%d",&n);
    printf("Enter the numbers ");
    printf("\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    heapsize=n;
    buildheap(arr);
    printf("\n");
    for(i=1;i<=n;i++)
    {
        printf("%d ",arr[i]);
    }printf("\n");
    /*for(i=n;i>=2;i--)
    {
        temp=arr[1];
        arr[1]=arr[i];
        arr[i]=temp;
        heapsize=heapsize-1;
        heapify(arr,1);
    }*/
    insert(arr,n);
    printf("\n");
    for(i=1;i<=n+1;i++)
    {
        printf("%d ",arr[i]);
    }

}
