#include<stdio.h>

typedef struct
{
    int l;
    int r;
    int sum;
}this;

this marray(int a[],int n)
{
    int i,j,k,max_here=0,max_sofar=0,l=0,r=0;
    this re;
    for(i=0;i<n;i++)
    {
        max_here+=a[i];

        if(max_here<0)
        {
            max_here=0;
            l=i+1;
        }
        if(max_here>0 && max_here>max_sofar)
        {
            max_sofar=max_here;
            r=i;
        }
    }
    re.l=l;
    re.r=r;
    re.sum=max_sofar;
    return re;
}

int main()
{
    int arr[100], new[100], num,i;
    this ans;
    printf("Enter the num of integers ");
    scanf("%d",&num);
    printf("Enter the integers: ");
    for(i=0;i<num;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<num-1;i++)
    {
        new[i]=arr[i+1]-arr[i];
    }

    for(i=0;i<num-1;i++)
    {
        printf("%d ",new[i]);
    }printf("\n");

    ans=marray(new,num-1);
    printf("The max sub array sum is %d\n", ans.sum);

    for(i=ans.l;i<=ans.r;i++)
    {
        printf("%d ",new[i]);
    }printf("\n");

    for(i=ans.l;i<=ans.r+1;i++)
    {
        printf("%d ",arr[i]);
    }printf("\n");
}
