#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct node
{
    int i;
    struct node *b;
    struct node *p;
}node;

void createnode(node *start)
{
    node *n1;
    n1=start;
    printf("Enter the start element ");
    //scanf("%d",&(n1->i));
    n1->i=rand()%100;
    n1->p=NULL;
    n1->b=NULL;
}

node *insertnode(node *head)
{
    node *n1,*n2;
    n1=head;
    if(n1->p==NULL)
    {
        n1->p=(node *)malloc(sizeof(node));
        n2=n1->p;
        //printf("Enter the element in the node ");
        //scanf("%d",&(n2->i));
        n2->i=rand()%100;
        n2->b=n1;
        n2->p=NULL;
        return n2;
    }
}
int printer(node *head)
{
    printf("\nnow printing\n");
    node *n1;
    n1=head;
    while(n1!=NULL)
    {
        printf("%d ",n1->i);
        n1=n1->p;
    }
}

int printer2(node *end)
{
    printf("\nnow printing in reverse\n");
    node *n1;
    n1=end;
    while(n1!=NULL)
    {
        printf("%d ",n1->i);
        n1=n1->b;
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

isort(node *head)
{
    node *n1,*n2,*n3;int temp;
    n1=head->p;
    while(n1!=NULL)
    {
        temp=n1->i;
        n2=n1->b;
        while(n2->b!=NULL && n2->i > temp)
        {
            (n2->p)->i=n2->i;printf("what");
            n2=n2->b;
        }if(n2->b==NULL){(n2->p)->i=n2->i;printf("what");
            n2=head;}
        (n2->p)->i=temp;
        n1=n1->p;
    }
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

node *copy(node *head, node *chead)
{
    node *n3,*n1=head,*n2=chead;
    n2->i=n1->i;printf("%d ",n2->i);
    n2->b=NULL;
    n2->p=NULL;
    n1=n1->p;
    while(n1->p!=NULL)
    {
        n2->p=(node *)malloc(sizeof(node));
        n3=n2->p;
        n3->i=n1->i;
        n3->b=n2;
        n3->p=NULL;
        n2=n2->p;
        n1=n1->p;
    }
        n2->p=(node *)malloc(sizeof(node));
        n3=n2->p;
        n3->i=n1->i;
        n3->b=n2;
        n3->p=NULL;
    return n3;
}

int main()
{
    int i,t,f;
    node list,*end,*found;
    node clist,*cend;
    srand(time(NULL));
    printf("How many elements? ");
    scanf("%d",&t);
    createnode(&list);
    end=&list;
    for(i=1;i<t;i++)
    {
        end=insertnode(end);
    }
    printer(&list);
    printer2(end);
    printf("\n\nPrinting copy\n\n");
    cend=copy(&list,&clist);
    printer(&clist);
    printer2(cend);
    /*printf("\nEnter the key to be found ");
    scanf("%d",&f);
    found=search(&list,f);*/
    printf("\nNow sorting");
    sort(&list);
    printer(&list);
    isort(&clist);
    printer(&clist);
}
