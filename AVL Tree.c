#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *p;
    struct node *l;
    struct node *r;
    int i;
    int bf;
    int h;
}node;
node *root;

int getbf(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->l) - height(N->r);
}
int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->h;
}

int maxoftwo(int a, int b)
{
    return (a > b)? a : b;
}

void disp(node *root)
{
    node *x=root;
    if(x!=NULL)
    {
	disp(x->l);
	printf("%d ",x->i);if(x->p==NULL){printf("root");}printf("(%d), ",x->bf);
	disp(x->r);
    }
}

node *search(node *root)
{
	int e;
	printf("Enter the key ");
	scanf("%d",&e);
	node *x=root;
	if(x==NULL){return x;}
	else
	{
		while(x!=NULL && x->i!=e)
		{
			if(x->i>e){x=x->l;}
			else if(x->i<e){x=x->r;}
		}
		return x;
	}
}

node* min(node *root)
{
    node *x=root;
    if(x==NULL){return NULL;}
    while(x->l!=NULL)
    {
        x=x->l;
    }
   return x;
}

node* max(node *root)
{
    node *x=root;
    if(x==NULL){return NULL;}
    while(x->r!=NULL)
    {
        x=x->r;
    }
    return x;
}


node* succ(node *n)
{
    node *x=n->r;
    if(x==NULL)
    {
        x=n;
        node *y=x->p;
        while(y!=NULL && x==y->r)
        {
            x=y;
            y=y->p;
        }
        return y;
    }
    else
    {
        return min(x);
    }
}


node* pre(node *n)
{
    node *x=n->l;
    if(x==NULL)
    {
    	x=n;
        node *y=x->p;
        while(y!=NULL && x==y->l)
        {
                x=y;
                y=y->p;
        }
     return y;
    }
    else
    {
	 return max(x);
    }
}

void transplant(node* u, node *v)
{
    if(u->p==NULL)
    {
        root=v;
    }
    else if(u==u->p->l)
    {
        u->p->l=v;
    }
    else
    {
        u->p->r=v;
    }
    if(v!=NULL)
    {
        v->p=u->p;
    }
}
void delete(node *z)
{
    node *y;
    if(z->l==NULL)
    {
        transplant(z,z->r);
    }
    else if(z->r==NULL)
    {
        transplant(z,z->l);
    }
    else
    {
        y=min(z->r);
        if(y->p!=z)
        {
            transplant(y,y->r);
            y->r=z->r;
            y->r->p=y;
        }
        transplant(z,y);
        y->l=z->l;
        y->l->p=y;
    }
}
node *rightrotate(struct node *x)
{
    node *ptemp=x,*ctemp=x->r;
    transplant(x,x->r);
    ptemp->r=ctemp->l;if(ptemp->r!=NULL){ptemp->r->p=ptemp;}printf("case 2");
    ctemp->l=ptemp;ptemp->p=ctemp;
     ptemp->h = maxoftwo(height(ptemp->l), height(ptemp->r))+1;ptemp->bf = getbf(ptemp);
    ctemp->h = maxoftwo(height(ctemp->l), height(ctemp->r))+1;ctemp->bf = getbf(ctemp);
    if(ctemp->p==NULL)root=ctemp;

}

node *leftrotate(struct node *x)
{
      node *ptemp=x,*ctemp=x->l;
    transplant(x,x->l);
    ptemp->l=ctemp->r;if(ptemp->l!=NULL){ptemp->l->p=ptemp;}printf("case 1");
    ctemp->r=ptemp;ptemp->p=ctemp;
     ptemp->h = maxoftwo(height(ptemp->l), height(ptemp->r))+1;ptemp->bf = getbf(ptemp);
     ctemp->h = maxoftwo(height(ctemp->l), height(ctemp->r))+1;ctemp->bf = getbf(ctemp);
    if(ctemp->p==NULL)root=ctemp;
}
void insert()
{
    int data;node *x=root,*n1=NULL, *y=NULL,*ptemp=NULL,*ctemp=NULL;
    printf("Enter Element: ");
    scanf("%d",&data);
    if(root==NULL)
    {
        root= (node*)malloc(sizeof(node));
        root->p=NULL;
        root->l=NULL;
        root->r=NULL;
        root->i=data;
        root->bf=0;root->h=1;
    }
    else if(root!=NULL)
    {
        while(x!=NULL)
        {
            n1=x;
            if(data>x->i){x=x->r;}
            else{x=x->l;}
        }
        x=(node *)malloc(sizeof(node));
        x->i=data;
        x->l=NULL;
        x->r=NULL;
        x->p=n1;
        x->bf=0;x->h=1;
        if(data>n1->i)
        {n1->r=x;}
        else{n1->l=x;}
    do
    {
        x=x->p; if(x==NULL){return;}
        x->h = maxoftwo(height(x->l), height(x->r)) + 1;printf("n");
        x->bf = getbf(x);printf("n");
    }while(x!=NULL && x->bf<=+1 && -1<=x->bf);

    if(x->bf==2 &&x->l!=NULL&& x->l->bf==1)
    {
        leftrotate(x);
    }
    else if(x->bf==-2 &&x->r!=NULL&& x->r->bf==-1)
    {
        rightrotate(x);
    }
    else if(x->bf==+2 &&x->l!=NULL&& x->l->bf==-1)
    {
        y=x->l;rightrotate(y);
        leftrotate(x);
    }
    else if(x->bf==-2 &&x->r!=NULL&& x->r->bf==+1)
    {
        y=x->r;leftrotate(y);
        rightrotate(x);
    }
    }
}

int main()
{
    node *found=NULL;root=NULL;
    int op=0;
    do
    {
        printf("1 for insert, 2 for max, 3 for min, 4 for succ, 5 for pre,6 for search, 7 for delete,8 for exit\n");
        scanf("%d",&op);

        if(op==1)
        {
            insert();
        }
        else if(op==2)
        {
            found=max(root);if(found!=NULL){printf("%d",found->i);}else{printf("Not found\n");}
        }
        else if(op==3)
        {
            found=min(root);if(found!=NULL){printf("%d",found->i);}else{printf("Not found\n");}
        }
        else if(op==4)
        {
	    found=search(root);if(found!=NULL){found=succ(found);}if(found==NULL){printf("Not found\n");}
	   else{printf("SUCC Element %d\n",found->i);}

        }
        else if(op==5)
        {
	   found=search(root);if(found!=NULL){found=pre(found);}if(found==NULL){printf("Not found\n");}
	   else{printf("PRE Element %d\n",found->i);}

        }
	else if(op==6)
	{
	   found=search(root);
           if(found==NULL){printf("Not found\n");}
	   else{printf("Searched Element %d\n",found->i);}
	}
	else if(op==7)
	{
		printf("delete not working yet");//found=search(root);if(found!=NULL){delete(found);}else{printf("Not found");}
	}
        else if(op==8)
        {
            break;
        }
        else{continue;}
	printf("\n");disp(root);printf("\n");
    }while(op!=8);
}
