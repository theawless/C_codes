#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int i;
    struct node* p;
}node;

node *push(node *head,int data)
{
    node *n1;
    if(head==NULL)
    {
        head=(node*)malloc(sizeof(node));
        head->i=data;
        head->p=NULL;
        return head;
    }
    else
    {
        n1=(node*)malloc(sizeof(node));
        head->p=n1;
        n1->i=data;
        n1->p=NULL;
        return n1;
    }
}

node *pop(node *end)
{
    node *n1;
    if(end==NULL)
    {
        printf("Already Empty\n");
        return end;
    }
    else
    {
        n1=end->p;
        return n1;
    }
}

void disp(node *head)
{
    node *n1=head;
    while(n1!=NULL)
    {
        printf("%d ",n1->i);
        n1=n1->p;
    }printf("\n");
}

int main()
{
    node *head=NULL,*end;
    int c,data;
    do
    {
        printf("1 for push, 2 for pop, 3 for end ");
        scanf("%d",&c);
        if(c==1)
        {
            printf("Enter Element ");
            scanf("%d",&data);
            if(head==NULL)
            {
                head=push(head,data);
                end=head;
            }
            else
            {
                head=push(head,data);
            }
        }
        else if(c==2)
        {
            end=pop(end);
        }
        else if(c==3)
        {
            continue;
        }
        else
        {
            printf("Invalid choice\n");
            continue;
        }
        disp(end);
    }while(c!=3);
}
