#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int i,n,arr[100];
    clock_t start,end;
    scanf("%d",&n);printf("\n");
    for(i=0;i<n;i++)
    {
        arr[i]=rand()%1000;
    }
    srand(time(NULL));
    int flag=0,np,temp;
    start=clock();
    while(flag==0)
    {
        flag=1;
        for(i=0;i<n;i++)
        {
            np=i+(rand()%(n-i));
            temp=arr[i];
            arr[i]=arr[np];
            arr[np]=temp;
        }/*
        for(i=0;i<n;i++)
        {
            printf("%d\n",arr[i]);
        }printf("\n");*/
        for(i=0;i<n-1;i++)
        {
            if(arr[i]>arr[i+1])
            {
                flag=0;
            }
        }
    }end=clock();

    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }printf("\n");

    printf("\nTotal time taken in sec %f\n",(double)(end-start)/CLOCKS_PER_SEC);
}
