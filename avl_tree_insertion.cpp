/*avl tree insertion deletion and display */
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
struct node * insert (struct node * , int );
//struct node *deletee(struct node *, int);
struct node *singleLrot(struct node *);
struct node *singleRrot(struct node *);
struct node *doubleLR(struct node *);
struct node *doubleRL(struct node *);
void preorder(struct node *);
void inorder(struct node *);
int avlht(struct node *);
void search(struct node *, int);

struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
};
void main()
{
	int ch,a;
	char  c;
	struct node *root=NULL;
	printf("AVL TREE IMPLEMENTATION\n");
	printf("\n 1. Insert 2. Preorder 3. INorder 4.Exit 5.Search ");
	while(1)
	{
		printf ("\nEnter choice\n");
		scanf ("%d",&ch);
		switch (ch) 
		{
		case 1 : printf ("Enter element\n");
				 scanf("%d",&a);
				 root= insert(root,a);
				 break;
		case 2: printf("\n Elements are");
				preorder(root);
				break;
		case 3: printf("\n Elements in order");
				inorder(root);
				break;
		case 4: exit(0);
				break;
		case 5: int element;
				printf("\n Enter the element to find");
				scanf("%d",&element);
				search(root, element);
				break;
		default: exit(0);
		}
		
	}
	getch();
}

						
struct node * insert(struct node *p, int a)
{
	if (p==NULL)
	{
		p=(struct node *)malloc(sizeof(struct node));
		p->data=a;
		p->lchild=NULL;
		p->rchild=NULL;
		
	}
	else
	{
		if(a<p->data)
		{
			p->lchild=insert(p->lchild, a);
			if(avlht(p->lchild)- avlht(p->rchild) ==2)
			{
				if(a< p->lchild->data)
					p=singleRrot(p);
				else
					p=doubleLR(p);
			}
		}
		else if(a> p->data)
		{
			p->rchild=insert(p->rchild, a);
			if(avlht(p->rchild) -avlht(p->lchild) ==2)
			{
					if(a > p->rchild->data)
						p=singleLrot(p);
					else
						p=doubleRL(p);
			}
		}
	}
	return p;
}

void preorder(struct node *p)
{
	if(p!=NULL)
	{
		printf("%d\t",p->data);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
void inorder(struct node *p)
{
	if(p!=NULL)
	{
		inorder(p->lchild);
		printf("%d\t",p->data);
		inorder(p->rchild);
	}
}
int avlht(struct node *p)
{
	if(p==NULL)
		return 0;
	else
	{
		int ldepth=avlht(p->lchild);
		int rdepth=avlht(p->rchild);
		if (ldepth >rdepth)
			return ldepth+1;
		else
			return rdepth+1;
	}
}


struct node * singleLrot(struct node *p1)
{
	struct node *p2;
	p2=p1->rchild;
	p1->rchild=p2->lchild;
	p2->lchild=p1;
return p2;
}

struct node * singleRrot(struct node *p1)
{
	struct node *p2;
	p2=p1->lchild;
	p1->lchild=p2->rchild;
	p2->rchild=p1;
	return p2;
}

struct node * doubleLR(struct node *p)
{
	p->lchild=singleLrot(p->lchild);
	p=singleRrot(p);
	return p;
}

struct node * doubleRL(struct node *p)
{
	p->rchild=singleRrot(p->rchild);
	p=singleLrot(p);
	return p;
}

void search(struct node *p, int a)
{
	if(a<p->data)
	{
		search(p->lchild,a);
	}
	if(a==p->data)
	{
		printf("Element found %d \n", a);
		printf("Height of that node =%d ", avlht(p));
	}
	if(a>p->data)
		search(p->rchild,a);
}

