#include<stdio.h>

void combine(int a[],int l, int m,int r)
{
    int left[100],right[100],i,j,k,o1=0,o2=0;

    for(i=l;i<=m;i++)
    {
        left[i-l]=a[i];o1++;
    }left[(m-l)+1]=50000;

    for(i=m+1;i<=r;i++)
    {o2++;
        right[i-(m+1)]=a[i];
    }right[r-(m+1)+1]=50000;

    j=0;k=0,i=l;

    while(j<o1 && k<o2)
    {
        if(right[k]>left[j])
        {
            a[i]=left[j];
            j++;
        }
        else if(right[k]<=left[j])
        {
            a[i]=right[k];
           k++;
        }
        i++;
    }
    while(j<o1)
    {
        a[i]=left[j];
        j++;i++;
    }

    while(k<o2)
    {
        a[i]=right[k];
        k++;i++;
    }
}

void divider(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid =(low+high)/2;

        divider(a,low,mid);

        divider(a,mid+1,high);

        combine(a,low,mid,high);
    }
}
int main()
{
    int a[100], num,i;

    printf("Enter the num of integers ");

    scanf("%d",&num);

    printf("Enter the integers: ");

    for(i=0;i<num;i++)
    {
        scanf("%d",&a[i]);
    }

    divider(a,0,num-1);

    for(i=0;i<num;i++)
    {
        printf("%d ",a[i]);
    }printf("\n");
}
