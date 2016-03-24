#include<stdio.h>

printarr(int x,int y,int a[100][100])
{
    int i,j;

    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("%d ",a[i][j]);
        }printf("\n");
    }
}


int main()
{
    int i,j,k,l,a,b,c,d, arr1[100][100], arr2[100][100],sum,p,arr3[100][100]={0};
    printf("Enter the size");
    scanf("%d%d",&a,&b);
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            scanf("%d",&arr1[i][j]);
        }
    }

    scanf("%d%d",&c,&d);

    for(i=0;i<c;i++)
    {
        for(j=0;j<d;j++)
        {
            scanf("%d",&arr2[i][j]);
        }
    }
    // Matrix Multiplication begins
    if(b!=c)
    {
        printf("Cannot multiply");
        return 0;
    }
    p=c;
    printf("first array is\n");
    printarr(a,b,arr1);

    printf("second array is\n");
    printarr(c,d,arr2);


    for(i=0;i<a;i++)
    {
        for(j=0;j<d;j++)
        {
            sum=0;

            for(k=0;k<p;k++)
            {
                sum = sum + arr1[j][k]*arr2[k][i];
            }
            arr3[i][j]=sum;
        }

    }
    printf("Multiplied array is\n");
    printarr(a,d,arr3);
}
