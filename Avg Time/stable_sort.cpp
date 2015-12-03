#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long *a,n,i,start,end;
    scanf("%lld",&n);
    a=(long long int *)malloc((n+1)*sizeof(long long int));
    srand((unsigned)time(NULL));
    for(i=0;i<n;i++)
    {
        a[i]=rand();
    }
    start=clock();
    stable_sort(a,a+n);
    end=clock();
    printf("Time taken= %lld\n", end-start);
}
