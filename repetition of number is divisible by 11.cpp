/* An unsigned number Q is formed by taking input p which is an unsigned integer in string format ,
k: number of times p repeated from Q . write a function to find whether the number Q is divisible by 11 or not */
/* If it is divisible it return 1 else it return 0 */
#include<stdio.h>
#include<conio.h>
#include<string.h>
int dotest();
int repetitive_divisible_by_11(char[], int);
int checkoutput(int,int);
struct test
{
	char inp[300];
	int k;
	int output;
}
testcases[7]={
	{ "123",3,0}, /* Here output 1 indicates that 123123123 is divisible by 11 other wise the output is 0. */
	{ "-22",0,1},   /* Divisibility Rule of 11 : Given no : 123123 evencount=2+1+3=7 oddcount=1+3+2=7 */
	{ "33",4,1},  /*if evencount-count==0 || 11 ||-11 , it is divisible else it is not divisible */
	{"121",2,1},
	{"80905",10,1},
	{"-80904",15,1},
	{"111-11",10,1}
};
int main()
{
	dotest();
	getch();
	return 0;
}
int dotest()
{
	int i,num;
	for(i=0;i<7;i++)
	{
		num=repetitive_divisible_by_11(testcases[i].inp, testcases[i].k);
		checkoutput(num, testcases[i].output);
	}
 return 0;
}
int repetitive_divisible_by_11(char str[], int k)
{
	char newstr[100];
	int strlength=strlen(str), Q[100],index;
	int i,j=0,l,countvalue=0,num,evencount=0,oddcount=0;
	if(str[0]=='-')
	{
		index=1;
	}
	else
	{
		index=0;
	}
	for(i=1;i<k;i++)
	{
		for(l=index;l<strlength;l++)
		{
			newstr[j]=str[l];
			j++;
		}
	}
	newstr[j]='\0';
	for(i=0;i<j;i++)
	{
		num=newstr[i]-'0';
		//printf("%c",newstr[i]);
		countvalue=countvalue*10+num;
		Q[i]=num;

	}
/*	printf("\n");
	for(j=0;j<i;j++)
	{
		printf("%d",Q[j]);
	}*/
	for(j=0;j<i;j++)
	{
		if(j%2==0)
		{
			evencount=evencount+Q[j];
		}
		else
		{
			oddcount=oddcount+Q[j];
		}
	}
	int answer=evencount-oddcount;
	if(answer==0 || answer==11 || answer==-11)
		return 1;
	else
		 return 0;
}
int checkoutput(int a, int b)
{
	if(a==b)
		printf("\nValid");
	else
		printf("\nInvalid");
	return 0;
}
	
