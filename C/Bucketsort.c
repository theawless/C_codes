#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct what
{
    float e;
    struct what *p;
}what;
bucket(float a[],int n)
{
    int i,pos;
    what buc[10], *now;
    for(i=0;i<n;i++)
    {
        buc[i].e=0;
        buc[i].p=NULL;
    }
    for(i=0;i<n;i++)
    {
        pos=a[i]*10; float data=a[i];

    what *current;

    if(buc[pos].e==0 && buc[pos].p==NULL)
    {
        buc[pos].e=data;
        continue;
    }
    if(buc[pos].e!=0 && buc[pos].p==NULL)
    {
        buc[pos].p=(what *)malloc(sizeof(what));
        current=buc[pos].p;
        current->e=data;
        current->p=NULL;
        continue;
    }current=buc[pos].p;
    while(current->p!=NULL)
    {
       current=current->p;
    }
    current=(what *)malloc(sizeof(what));
    current->e=data;
    current->p=NULL;
    }

    what *n1,*n2; float temp;
    for(i=0;i<10;i++)
    {

        n1=&buc[i];
        n2=&buc[i];
        while(n1!=NULL)
        {
            while(n2!=NULL)
            {
                if(n1->e > n2->e)
                {
                   temp=n1->e;
                   n1->e=n2->e;
                   n2->e=temp;
                }
                n2=n2->p;
            }
            n2 = n1 ->p;
            n1=n1->p;
        }
    }
    float fa[20];int k=0;
    for(i=0;i<10;i++)
    {
        if(buc[i].e==0 && buc[i].p==0)
        {
            continue;
        }
        n1=&buc[i];
        while(n1!=0)
        {
            fa[k] = n1 -> e;
            n1 = n1 -> p;k++;
        }
    }
for(i=0;i<n;i++)
{
    printf("%.2f ",fa[i]);}
}

int main()
{
    int i,n=10;
    float a[10]={0.78,0.17,0.39,0.26,0.72,0.94,0.01,0.12,0.23,0.68};
    clock_t end,start;
    srand(time(NULL));
    start=clock();
    bucket(a,n);
    end=clock();
    printf("\nTime taken is %ld",end-start);
}
