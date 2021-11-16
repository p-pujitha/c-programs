#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void create_linkedlist(struct node *);
struct node * createNode(int);
void display(struct node *);
struct node{
	int data;
	struct node *next;
}*head;

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
void display(struct node *p)
{
	struct node *ptr=p;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

void create_linkedlist(struct node *head)
{
	int choice;
	do{
		
		 int num;
		 printf("Enter the number");
		 scanf("%d",&num);
		 add(&head,num);
		
		 printf("Do you want to continue-yes-1,no-0");
		 scanf("%d",&choice);
	}while(choice!=0);
	display(head);
}
void main()
{
	 
	 struct node *head=NULL;
	 create_linkedlist(head);
	struct node *start=NULL;
	create_linkedlist(start);
	merge(head,start);
	printf("\n");
	 
	getch();
}
void merge(struct node *head, struct node *start)
{
	struct node *ptr1=head;
	struct node *ptr2=start;
	struct node *ptr3=NULL;
    int count1=0, count2=0;
	while(ptr1->next!=NULL)
	{
		count1++;
		ptr1=ptr1->next;
	}
	while(ptr2->next!=NULL)
	{
		count2++;
		ptr2=ptr2->next;
	}
/*	if(count1<=count2)
		ptr3=head;
	else
		ptr3=start;*/
	while(ptr1->next!=NULL && ptr2->next!=NULL)
	{
		if(ptr3->next==NULL)
		{
			if(ptr1->data<=ptr2->data)
				ptr3->next=ptr1;
			else
				ptr3->next=ptr2;
		}
		ptr
