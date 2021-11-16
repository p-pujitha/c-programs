#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node
{
	int data;
	struct node *next;
};
void dotest();
struct node *insert_node_Recursion_method(struct node *, int, struct node * );
struct node *Array_to_linked_list(int *arr, int len);		// Array to Linked list converter
struct testcases
{
	int arr[100];
	int inplen;
	int N;
	int output[100];
	int oplen;
}testcases[10] = {
/*1*/	{ { 1, 2, 4, 5, 6 }, 5, 3, { 1, 2, 3, 4, 5, 6 }, 6 },
/*2*/	{ { 1, 2, 3, 4, 5 }, 5, 6, { 1, 2, 3, 4, 5, 6 }, 6 },
/*3*/	{ { 1, 1, 1, 1, 1 }, 5, 1, { 1, 1, 1, 1, 1, 1 }, 6 },
/*4*/	{ { 1, 1, 1, 1, 1 }, 5, -1, { -1, 1, 1, 1, 1, 1 }, 6 },
/*5*/	{ { 2, 3, 4 }, 3, 1, { 1, 2, 3, 4 }, 4 },
/*6*/	{ { 1, 2, 2, 3, 3, 3, 5, 5, 7 }, 9, 5, {1, 2, 2, 3, 3, 3, 5, 5, 5, 7}, 10 },
/*7*/	{ { 1, 2, 3 }, 3, NULL, {NULL, 1, 2, 3}, 4 },
/*8*/	{ NULL, 1, 5, { 5 }, 2 },
/*9*/	{ NULL, 1, NULL, NULL, 1 }
};

struct node * createNode(int n1) {
			struct node *newNode = (struct node *)malloc(sizeof(struct node));
			newNode->data= n1;
			newNode->next = NULL;
			return newNode;
		}
void add(struct node **head, int p){
			struct node *temp = *head;
			if (*head == NULL){
				(*head) = createNode(p);
				(*head)->next = NULL;
			}
			else{
				while (temp->next != NULL){
					temp = temp->next;
				}
				temp->next = createNode(p);
				temp->next->next = NULL;
			}
		}

void main()
{
	dotest();
	getch();
}


void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;	
}
void dotest()
{
	int i, count = 7;



	printf(" Finding median by count Method\n\n");
	for (i = 0; i < count; i++)
	{
		struct node *ptr=Array_to_linked_list(testcases[i].arr,testcases[i].inplen);
		if (testcases[i].output == insert_node_Recursion_method(ptr,testcases[i].N,ptr))
			printf("TESTCASE %d Valid\n", i + 1);
		else
			printf("TESTCASE %d Invalid\n", i + 1);
	}
}

struct node *insert_node_Recursion_method(struct node *head, int N, struct node *ans)
{
	struct node *i = head, *temp, *op = NULL;

	if (ans == NULL)
		return op;
	else
	{
		if (i->next->data < N && &i->next->data != &ans->data)
			i = insert_node_Recursion_method(i->next, N, ans);
		else
		{
			op = (struct node*)malloc(sizeof(struct node));
			op->data = N;
			op->next = NULL;
			if (ans->data >= N)
				swap(&ans->data, &op->data);
			temp = i->next;
			i->next = op;
			op->next = temp;
		}

		return ans;
	}
}

struct node *Array_to_linked_list(int *arr, int len)
{

	int j;
	struct node *temp = (struct node*)malloc(sizeof(struct node)), *head = NULL, *ccl;

	if (arr == NULL || len == 0)
		return NULL;
	else
	{
        ccl = temp;
		for (j = len - 1; j >= 0; j--)
		{
			temp->data = arr[j];
			head = (struct node*)malloc(sizeof(struct node));
			head->next = temp;
			temp = head;
		}

		ccl->next = head->next;
		return head->next;
	}
