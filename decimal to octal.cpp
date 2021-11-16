/* Convert a given decimal number into octal number*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
int dotest();
void decitooct(int,int);
void deci_to_oct(int,int);
int checkoutput(char*, char*);
int power(int,int);
struct test
{
	long int deci;
	char oct[100];
}
testcases[3]={
	{369,"561"},
	{100,"144"},
	{10,"12"}
};
	
void main()
{
	dotest();
	getch();
}
int dotest()
{
	printf("\nMethod:1");
	for(int i=0;i<3;i++)
	{
		decitooct(testcases[i].deci,i);
	}
	printf("\nMethod:2");
	for(int i=0;i<3;i++)
	{
		deci_to_oct(testcases[i].deci,i);
	}
	return 0;
}
void decitooct(int n, int index)
{
	 char a[30];
	 int i=0,j;
	 long int count=0;
	 while(n!=0)
	{
		int n1=(n%8);
		a[i]=n1+'0';
		//printf("%c",a[i]);
		n=n/8;
		i++;
	}
	
	a[i]='\0';
	char *aa=a;
	strrev(a);
	checkoutput(a, testcases[index].oct);
	}

int checkoutput(char *op, char *result)
{
	int i,flag=0;
	for(i=0;op[i]!='\0';)
	{
		if(op[i]==result[i])
		{
			i++;
			flag=1;
		}
	}
	 
	if(flag==1)
	printf("Valid");
	else
		printf("Invalid");
return 0;
}
 void deci_to_oct(int n, int index)
{
	int i,powersof8[100],j,k=0;
	char ans[100];
	i=0;
	while(power(8,i)<n)									/* intially find the power of 8 which is less than of agiven nuber */
	{

		powersof8[i]=power(8,i);						/* sub given number - (givennumber / power of 8) = remainder */
		i++;
	}															/* 98/64=1 -> 98-(1*64)=34*/
	for(j=i-1;j>=0;j--)											/* 34/8=4 ->  34-(4*8)=2 */
	{                                                           /* 2/1=2  */
		int a=n/powersof8[j];									/* deci(98)=oct(142) */
		ans[k]=a+'0';
		k++;
		n=n-(a*powersof8[j]);
	}
	ans[k]='\0';

	checkoutput(ans,testcases[index].oct);

 }
int power(int a, int b)
{
	int mul=1;
	for(int i=0;i<b;i++)
	{
		mul=mul*a;
	}
	return mul;
}
 
