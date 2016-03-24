#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int i;
    struct node *p;
}node;

void createnode(node *start)
{
    node *n1;
    n1=start;
    printf("Enter the start element ");
    scanf("%d",&(n1->i));
    n1->p=NULL;
}

node *insertnode(node *head)
{
    node *n1,*n2;
    n1=head;
    if(n1->p==NULL)
    {
        n1->p=(node *)malloc(sizeof(node));
        n2=n1->p;
        printf("Enter the element in the node ");
        scanf("%d",&(n2->i));
        n2->p=NULL;
        return n2;
    }
}
int printer(node *head)
{
    node *n1;
    n1=head;
    while(n1!=NULL)
    {
        printf("%d ",n1->i);
        n1=n1->p;
    }
}


node  *search(node *head,int f)
{
    node *n1;int i=0,flag=0;
    n1=head;
    while(n1!=NULL)
    {
        if(n1->i==f)
        {
            flag=1;break;
        }
        i++;
        n1=n1->p;
    }
    if(flag==1){printf("\nThe key found at pos %d",i);return n1;}
    else{printf("\nKey not found");return NULL;}
}

sort(node *head)
{
    node *n1,*n2;int temp;
    n1=head;n2=head;
    while(n1!=NULL)
    {
        while(n2!=NULL)
        {
            if(n1->i > n2->i)
            {
                temp=n1->i;
                n1->i=n2->i;
                n2->i=temp;
            }n2=n2->p;
        }n2=n1->p;
        n1=n1->p;
    }
}

int main()
{
    int i,t,f;
    node list,*end,*found;
    printf("How many elements? ");
    scanf("%d",&t);
    createnode(&list);
    end=&list;
    for(i=1;i<t;i++)
    {
        end=insertnode(end);
    }
    printer(&list);
    printf("\nEnter the key to be found ");
    scanf("%d",&f);
    found=search(&list,f);
    printf("\nNow sorting");
    sort(&list);
    printer(&list);
}
