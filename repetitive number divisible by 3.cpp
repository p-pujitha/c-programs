/* An unsigned number Q is formed by taking input p which is an unsigned integer in string format ,
k: number of times p repeated from Q . write a function to find whether the number Q is divisible by 3 or not */
#include<stdio.h>
#include<conio.h>
#include<string.h>
void dotest();
int repetitive_divisible_by3(char [], int);
int repetitive_divisible_by_3(char [], int);
int noofdigits(int);
int checkoutput(int,int);
struct test
{
	char ip[100];
	int k;
	int output;

} testcases[7]={					/* here output 1 indicates that it is divisible by 3 */
	{ "123",2,1},
	{"3",00100,1},
	{"111111111",1,1},
	{"-143",1,1},
	{"333-",10,0},
	{"1-1",1,1},
	{"00000000",3,1}
	
};
void main()
{
		dotest();
		getch();
}
void dotest()
{
		printf("1st method\n ");
		for(int i=0;i<7;i++)
		{
			int num=repetitive_divisible_by3(testcases[i].ip,testcases[i].k);
			checkoutput(num,testcases[i].output);
		}
		printf("\n second method \n");
		for(int i=0;i<7;i++)
		{
			int num=repetitive_divisible_by_3(testcases[i].ip,testcases[i].k);
			checkoutput(num,testcases[i].output);
		}
}
int checkoutput(int a, int b)
{
	if(a==b)
		printf("\nValid");
	else
		printf("\nInvalid");
  return 0;
}
int repetitive_divisible_by3(char str[], int k)
{
	char newstr[100];									/* eg: 123 =1+2+3 =6 is divisible by 3 hence 123 is divisible by 3 */
	int strlength=strlen(str), Q[100];
	int i,j=0,l,countvalue=0,num;
	j=0;
	//printf("%c\n",str[0]);
	if(str[0]=='-')
	{
		for(i=0;i<k;i++)
	{
		for(l=1;l<strlength;l++)
		{
			newstr[j]=str[l];
			j++;
		}
	}
	newstr[j]='\0';
	}
	else
	{
	for(i=0;i<k;i++)
	{
		for(l=0;l<strlength;l++)
		{
			newstr[j]=str[l];
			j++;
		}
	}
	newstr[j]='\0';
	}
/*	for(i=0;i<j;i++)
	{ printf("%c",newstr[i]);
	}
	printf("\n");

	*/
	for(i=0;i<j;i++)
	{
		num=newstr[i]-'0';
		countvalue=countvalue*10+num;
		Q[i]=num;
	}

	//printf("\n%d",countvalue);
	if(countvalue%3==0)
		return 1;
	else
		return 0;
}


int repetitive_divisible_by_3 (char str[], int k)  /* eg: 123123 add the numbers 1+2+3+1+2+3 =12
												   again add 1+2 =3  if the individual digit is 3 ,6,9 it is divisible */
{
		char newstr[100];							/* or it is not divisible */
	int strlength=strlen(str), Q[100];
	int i,j=0,l,countvalue=0,num,rem,sum=0;
	j=0;
	for(i=0;i<k;i++)
	{
		for(l=0;l<strlength;l++)
		{
			newstr[j]=str[l];
			j++;
		}
	}
	newstr[j]='\0';
    for(i=0;i<j;i++)
	{
		num=newstr[i]-'0';
		countvalue=countvalue*10+num;
		Q[i]=num;
	}
	//printf("%d",countvalue);
	if(countvalue==0)
		return 1;
	while(noofdigits(countvalue)!=1)
	{
		while(countvalue!=0)
		{
			rem=countvalue%10;
			sum=sum+rem;
			countvalue=countvalue/10;
		}
		countvalue=sum;
		sum=0;
	}
	
	if(countvalue==3 || countvalue==6 || countvalue==9)
		return 1;
	else
		return 0;
}

int noofdigits(int n)
{
	int rem,total=0;
	while(n!=0)
	{
		rem=n%10;
		total=total+1;
		n=n/10;
	}
	return total;
}

	




