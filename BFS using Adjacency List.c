#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int V;
    struct node *N;
}node;
node *tail=NULL,*head=NULL;

typedef struct vertex
{
    int v;int col;int d;
    struct vertex *par;
    struct vertex *next;
}vertex;

vertex **create_graph(int n)
{
    int i;
    vertex **temp=(vertex **)malloc(sizeof(vertex*)*n);
    for(i=0;i<n;i++)
    {
        temp[i]=(vertex*)malloc(sizeof(vertex));
        temp[i]->v=i;temp[i]->col=0;temp[i]->d=-1;temp[i]->par=NULL;
        temp[i]->next=NULL;
    }
    return temp;
}
vertex **make_edge(vertex **L,int src,int dest)
{
    vertex *temp=(vertex*)malloc(sizeof(vertex));
    if(L[src]->next==NULL)
    {
        temp->v=dest;temp->col=0;temp->d=-1;temp->par=NULL;temp->next=NULL;
        L[src]->next=temp;
    }
    else
    {
        temp->v=dest;temp->col=0;temp->d=-1;temp->par=NULL;temp->next=L[src]->next;
        L[src]->next=temp;
    }
    return L;
}
void disp_graph(vertex **L,int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        vertex *temp=L[i]->next;printf("Adjacency List of %d is: ",L[i]->v);
        while(temp!=NULL)
        {
            printf("%d ",temp->v);temp=temp->next;
        }printf("\n");
    }
}
void disp_que()
{
    node *n=tail;
    printf("The que is : ");
    while(n!=NULL){printf("%d ",n->V);n=n->N;}
    printf("\n");
}
node *queue(int V)
{
    if(head==NULL)
    {
        head=(node *)malloc(sizeof(node));
        head->V=V;head->N=NULL;
        tail=head;
    }
    else
    {
        node *temp=(node *)malloc(sizeof(node));
        temp->V=V;temp->N=NULL;
        head->N=temp;
        head=temp;
    }
}

node *deque()
{
    if(tail==NULL){head=NULL;printf("Empty\n");}
    else
    {
        tail=tail->N;if(tail==NULL){head=NULL;}
    }
}

vertex **bfs(vertex **L,int s)
{
    int Q=0;
    vertex *x,*y;
    L[s]->d=0;
    queue(s);Q++;
    while(tail!=NULL)
    {
        //disp_que();
        x=L[tail->V];
        y=L[tail->V]->next;
        while(y!=NULL)
        {
            if(L[y->v]->col==0)
            {
                y->d=x->d+1;
                L[y->v]->d=x->d+1;

                y->par=x;
                L[y->v]->par=x;

                y->col=1;
                L[y->v]->col=1;

                queue(y->v);Q++;
            }
            y=y->next;
        }
        x->col=1;deque();Q--;//disp_que();
        printf("Node: %d Distance: %d\n",x->v,x->d);
    }
    return L;
}

void printpath(vertex **L,int V,int V2)
{
    if(V==V2)
    {
        printf("%d",L[V]->v);
    }
    else if(L[V2]->par==NULL){printf("Path not possible");}
    else{printpath(L,V,L[V2]->par->v);printf("%d",V2);}
}

int main()
{
    int n,i,e,query,V,src,dest;printf("This is an Undirected Graph\n");
    printf("No of Vertices: ");scanf("%d",&n);
    vertex **L=create_graph(n);
    printf("No of edges: ");scanf("%d",&e);
    for(i=0;i<e;i++)
    {
        printf("Enter the edge(source destination) : ");scanf("%d%d",&src,&dest);
        L=make_edge(L,src,dest);L=make_edge(L,dest,src);
    }
    disp_graph(L,n);
    printf("BFS through vertex: ");scanf("%d",&V);
    L=bfs(L,V);
    printpath(L,2,6);
}
