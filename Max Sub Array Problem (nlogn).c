#include<stdio.h>

typedef struct
{
    int l;
    int r;
    int sum;
} back;

back maxcross(int a[],int low, int mid,int high)
{
    int ls=-50000, rs=-50000, i=mid, j=mid+1, sum=0, lmax, rmax;
    back wow5;
    while(i>=low)
    {
        sum=sum+a[i];
        if(sum>ls)
        {
            ls=sum;
            lmax=i;
        }i--;
    }
    sum=0;
    while(j<=high)
    {
        sum=sum+a[j];
        if(sum>rs)
        {
            rs=sum;
            rmax=j;
        }j++;
    }
    wow5.l=lmax;
    wow5.r=rmax;
    wow5.sum=ls+rs;
    return wow5;
}

back maxarray(int a[],int low,int high)
{
    int mid;
    back wow1,wow2,wow3,wow4;

    if(high==low)
    {
        wow1.l=low;
        wow1.r=high;
        wow1.sum=a[low];
       return wow1;
    }
    else
    {
        mid=(low+high)/2;

        wow2=maxarray(a,low,mid);

        wow3=maxarray(a,mid+1,high);

        wow4=maxcross(a,low,mid,high);

        if(wow2.sum>=wow3.sum && wow2.sum>=wow4.sum)
        {
            return wow2;
        }
        else if(wow3.sum>=wow2.sum && wow3.sum>=wow4.sum)
        {
            return wow3;
        }
        else if (wow4.sum>=wow2.sum && wow4.sum>=wow3.sum)
        {
            return wow4;
        }
    }
}
int main()
{
    int arr[100], new[100], num,i;
    back ans;
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

    ans=maxarray(new,0,num-2);

    for(i=ans.l;i<=ans.r;i++)
    {
        printf("%d ",new[i]);
    }printf("\n");
    printf("max sum is %d", ans.sum);
    printf("\n");

    for(i=ans.l;i<=ans.r+1;i++)
    {
        printf("%d ",arr[i]);
    }printf("\n");
}
