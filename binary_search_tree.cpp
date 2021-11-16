/*creation of binary search tree */
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void insert(int *arr, int len);

struct btreenode{
	struct btreenode *leftchild;
	int data;
	struct btreenode *rightchild;
};


void insert_data(struct btreenode **bt, int num);
void inorder(struct btreenode *bt);
int avlht(struct btreenode *p);
void search(struct btreenode *p, int a,int root_value, struct btreenode *root, int i);
int min(int a, int b);
void postorder(struct btreenode *p);
void preorder(struct btreenode *p);
//void print_elements_in_level_wise(struct btreenode *p, int *, int, struct btreenode *);
void print_elements_in_level_wise(struct btreenode *p);
int printGivenLevel(struct btreenode* root, int level, int *, int );



void main()
{
	int len;
	int *arr;
	
	
	printf("Enter length");
	scanf("%d",&len);
	arr=(int *)malloc(sizeof(int)*len);
	printf("Enter the array");
	for(int i=0;i<len;i++)
		scanf("%d",&arr[i]);
	 insert(arr,len);
	
	 getch();
	 
}
void insert(int *arr, int len)
{
	struct btreenode *bt;
	bt=NULL;
	for (int i=0;i<len;i++)
	{
		insert_data(&bt,arr[i]);
	}
	printf("\n In order Elements are : "); 
	inorder(bt);
	printf("\n Pre order Elements are :");
	preorder(bt);
	printf("\n Post order Elements are :");
	postorder(bt);
	printf("\n Searching a element in ther array");
	int element;
	scanf("%d",&element);
	search(bt,element,bt->data,bt,0);
	printf("\n printing Elements in level wise ");
	print_elements_in_level_wise(bt);
	getch();

}
void insert_data(struct btreenode **bt, int num)	// Inserting the data in the binary search tree
{
	if (*bt==NULL)
	{
		*bt=(struct btreenode *)malloc(sizeof(struct btreenode));
		(*bt)->leftchild =NULL;
		(*bt)->data=num;
		(*bt)->rightchild= NULL;
		return;
	}
	else
	{
		if (num < (*bt)->data)
			insert_data(&((*bt)->leftchild),num);
		else
			insert_data(&((*bt)->rightchild),num);
	}
	return;
}

void inorder(struct btreenode *bt)		// Inorder traversal of the binary search tree
{
	if (bt!=NULL)
	{
		inorder(bt->leftchild);
		printf("%d",bt->data);
		inorder(bt->rightchild);
	}
	else
		return;
}

void search(struct btreenode *p, int a, int root_value, struct btreenode *root, int i)
{
	
	int distance=0;					//Find the min distance from leaf to the particular node 
	if(a<p->data)
	{
		i=i+1	;
		search(p->leftchild,a,root_value, root, i);
	}
	if(a==p->data)
	{  
		int distance_leaf=avlht(p)-1;
		printf("Element found %d \n", a);
		printf("Height of that node =%d \n", distance_leaf);
		if(a<root_value){
			distance=avlht(root->rightchild);
			printf("Height of the right subtree of the root= %d\n", distance);}
		else if(a>root_value){
			distance=avlht(root->leftchild);
			printf("Height of the left subtree of the root =%d\n",distance);}
		printf("Height from root to the find node = %d\n",i);
		printf("Minimum of the distance from leaves to that particular node is %d", min(i+distance,distance_leaf));
	}
	if(a>p->data){
		i=i+1;
		search(p->rightchild,a,root_value,root, i);}
}

int avlht(struct btreenode *p)		// Calculating the height of the particular node
{
	if(p==NULL)
		return 0;
	else
	{
		int ldepth=avlht(p->leftchild);
		int rdepth=avlht(p->rightchild);
		if (ldepth >rdepth)
			return ldepth+1;
		else
			return rdepth+1;
	}
}

int min(int a, int b)
{
	if(a<b)
		return a;
	else
		return b;
}

void preorder(struct btreenode *p)
{
	if (p!=NULL)
	{
		printf("%d",p->data);
		preorder(p->leftchild);
		preorder(p->rightchild);
	}
	else
		return;
}

void postorder(struct btreenode *p)
{
	if (p!=NULL)
	{
		
		postorder(p->leftchild);
		postorder(p->rightchild);
		printf("%d",p->data);
	}
	else
		return;
}

/*void print_elements_in_level_wise(struct btreenode *p, int * arr, int length, struct btreenode *bt)
{
	if(p->leftchild==NULL && p->rightchild ==NULL)
		return;
	else
	{
		if(length ==0 )
		{
			arr[length]=p->data;
			length++;
		}
		else
		{
			arr[length]=p->data;
			length++;
			arr[length]=bt->data;
		}
	}
		print_elements_in_level_wise(p->leftchild, arr, length, p->rightchild);
	
}*/

void print_elements_in_level_wise(struct btreenode *p)
{
	int height=avlht(p);
	int *arr=(int*)malloc(sizeof(int)*(height*2));
	int len=0;
	for(int i=1;i<=height;i++)
	{
		int k=printGivenLevel(p,i,arr,&len);
		len=k;
	}
	for(int k=0;k<len;k++)
		printf("%d\t",arr[k]);
}
int printGivenLevel(struct btreenode* root, int level,int *arr, int *len)
{
    if (root == NULL)
        return 0;
    if (level == 1){
        //printf("%d\t", root->data);
			arr[*len]=root->data;
			*len+=1;}
    else if (level > 1)
    {
        printGivenLevel(root->leftchild, level-1,arr,len);
        printGivenLevel(root->rightchild, level-1,arr,len);
    }
	
}



/* closest distance.....!!!!
int closest_distance_down(struct node *root)
{
	struct store
	{
		struct node *root;
		int level;
	};

	struct store *queue = (struct store*)malloc(sizeof(struct store));
	int front = 0, rear = 1, next_len = 2;

	queue[0].root = root;
	queue[0].level = 0;

	while (1)
	{
		if (queue[front].root->left != NULL)
		{
			queue = (struct store*)realloc(queue, sizeof(struct store)*next_len);
			next_len++;
			queue[rear].level = queue[front].level + 1;
			queue[rear].root = queue[front].root->left;
			rear++;
		}
		if (queue[front].root->right != NULL)
		{
			queue = (struct store*)realloc(queue, sizeof(struct store)*next_len);
			next_len++;
			queue[rear].level = queue[front].level + 1;
			queue[rear].root = queue[front].root->right;
			rear++;
		}
		if (queue[front].root->left == NULL && queue[front].root->right == NULL)
		{
			return queue[front].level;
		}

		front++;
		if (front >= rear)
			break;
	}
	return 0;
}

int get_distance_btw_two_nodes(struct node *root, struct node *sub_node)
{
	int distance = 0;
	
	while (1)
	{
		if (root->data == sub_node->data)
			break;
		if (sub_node->data > root->data)
			root = root->right;
		else
			root = root->left;
		distance++;
	}
	return distance;
}

int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL)
		return -1;
	if (temp == NULL)
		return -1;
	if (temp->left == NULL && temp->right == NULL)
		return 1;

	int distance = closest_distance_down(temp);
	int temp_dist;

	while (1)
	{
		if (root->data == temp->data)
		{
			return distance;
		}
		if (temp->data < root->data)
		{
			temp_dist = closest_distance_down(root->right) + 1;
			temp_dist = temp_dist + get_distance_btw_two_nodes(root, temp);
			if (temp_dist < distance)
				distance = temp_dist;
			root = root->left;
		}
		else
		{
			temp_dist = closest_distance_down(root->left) + 1;
			temp_dist = temp_dist + get_distance_btw_two_nodes(root, temp);
			if (temp_dist < distance)
				distance = temp_dist;
			root = root->right;
		}
	}

}
*/


/*FIXED BINARY SEARCH TREE.....!!!

void inorder_fix(struct node *root, int **prev, int **toswap1, int **toswap2)
{
	if (root != NULL)
	{
		inorder_fix(root->left, prev, toswap1, toswap2);
		if (**prev > root->data && *toswap1 == NULL)
		{
			*toswap1 = *prev;
			*toswap2 = &root->data;
		}
		else if (**prev > root->data && *toswap1 != NULL)
			*toswap2 = &root->data;
		*prev = &root->data;
		inorder_fix(root->right, prev, toswap1, toswap2);
	}
}


void fix_bst(struct node *root)
{
	int *prev = NULL, temp = -1;
	int *a = NULL, *b = NULL;
	if (root == NULL)
		return;
	prev = &temp;
	inorder_fix(root, &prev, &a, &b);
	temp = *a;
	*a = *b;
	*b = temp;

}



*/