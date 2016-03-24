#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    struct node *p;
    struct node *l;
    struct node *r;
    int i;
}node;
node *root;
void disp(node *root)
{
    node *x=root;
    if(x!=NULL)
    {
	disp(x->l);
	printf("%d ",x->i);
	disp(x->r);
    }
	//printf("\n");
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
    while(x->l!=NULL)
    {
        x=x->l;
    }
   return x;
}

node* max(node *root)
{
    node *x=root;
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

void insert(node* *root)
{
    int data;
    printf("Enter Element: ");
    scanf("%d",&data);
    if(*root==NULL)
    {
        *root= (node*)malloc(sizeof(node));
        (*root)->p=NULL;
        (*root)->l=NULL;
        (*root)->r=NULL;
        (*root)->i=data;
    }
    else if(*root!=NULL)
    {   node *x=*root,*n1;
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
	if(data>n1->i){n1->r=x;}
	else{n1->l=x;}
    }//return root;
}

int main()
{
    node *found=NULL;
    int op=0;
    do
    {
        printf("1 for insert, 2 for max, 3 for min, 4 for succ, 5 for pre,6 for search, 7 for delete,8 for exit\n");
        scanf("%d",&op);

        if(op==1)
        {
            //scanf("%d",&data);
            insert(&root);
        }
        else if(op==2)
        {
            found=max(root);printf("%d",found->i);
        }
        else if(op==3)
        {
            found=min(root);printf("%d",found->i);
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
		found=search(root);if(found!=NULL){delete(found);}else{printf("Not found");}
	}
        else if(op==8)
        {
            break;
        }
        else{continue;}
	printf("\n");disp(root);printf("\n");
    }while(op!=8);
}
