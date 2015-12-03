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
    //n1=(node *)malloc(sizeof(node));
    printf("Enter the start element");
    scanf("%d",&(n1->i));
}

node *insertnode(node *head)
{
    node *n2;
    n2=head;

    while(n2->p!=NULL)
    {
        n2=n2->p;
    }
        n2->p=(node *)malloc(sizeof(node));
        n2=n2->p;
        printf("Enter the element in the node");
        scanf("%d",&(n2->i));
        n2->p=NULL;
        return n2;
}
int printer(node *head)
{
    node *n1;
    n1=head;
    printf("now printing");
    while(n1!=NULL)
    {
        printf("%d ",n1->i);
        n1=n1->p;
    }
}

int main()
{
    int i,t;
    node list;
    list.p=NULL;
    createnode(&list);
    printf("How many elements?");
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        insertnode(&list);
    }
    printer(&list);
}
