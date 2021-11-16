#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node{
	int num;
	struct node *next;
};
void generate(int);
void loop(struct node*,int);
void loopcheck(struct node*);
void main(){
	generate(10);
	getch();

}
void generate(int num1){
	int i = 0, count = 0;
	struct node *head1, *current1, *temp1, *head2, *current2, *temp2;
	current1 = (struct node*)malloc(sizeof(struct node));

	current1->num = 0;
	current1->next = NULL;
	head1 = current1;
	while (i <= num1){
		temp1 = (struct node*)malloc(sizeof(struct node));
		temp1->num = i;
		i += 1;
		count++;
		temp1->next = NULL;

		current1->next = temp1;
		current1 = temp1;

	}

	temp1 = head1->next;
	count = num1 / 2;
	for (i = 0; i <= count ; i++){
		temp1 = temp1->next;
	}
	current1->next = temp1;
	loop(head1,num1);

}
void loop(struct node *head,int num){
	struct node *current1,*current2,*pred;
	current1= head->next;

	pred=current1;
	current2=head->next;
	int i,flag=0;
	/*for (i = 0, current1 = head->next; current1!=NULL; current1 = current1->next){
		printf("%d  ", current1->num);
	}*/
	while(flag!=1)
	{
		pred=current1;
		current1=current1->next;
		
		current2=current2->next->next;
		
		if(current1==current2)
		{
			break;
		}
		
	}
	printf("%d\n",current1->num);	
	while(flag!=1)
	{
		pred=current1;
		current1=current1->next;
		
		current2=current2->next->next;
		if(current1==current2)
		{
			flag=0;
			if(num%2!=0)
			{
			printf("%d\n",pred->num);
			 pred->next=NULL;
			}
			else
			{
			printf("%d\n",current1->num);
			current1->next=NULL;
			}
			break;
		}
		
	}
	loopcheck(head);
}
void loopcheck(struct node *head){
	struct node *current1;
	for(current1=head->next;current1!=NULL;current1=current1->next){
	printf("%d\t",current1->num);
	}
}


