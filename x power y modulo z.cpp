/* Given three unsigned numbers as input x,y,z find out x to the power of y modulo z ( power(x,y)modz) */
/* If you give any float number also by default it converts into an integer and gives us the appropriate result */
#include<stdio.h>
#include<conio.h>
int calculate(int, int, int);
int checkoutput(int,int);
int power(int,int);
int dotest();
struct test
{
		int x;
		int y;
		int z;
		int output;
}testcases[3]=
{
	{ 2,3,5,3},
	{2.5,3,5,3},
	{3,2,9,0}
};
int main()
{
	dotest();
	getch();
	return 0;
}
int dotest()
{
	int num,i;
	for(i=0;i<3;i++)
	{
		num=calculate(testcases[i].x,testcases[i].y, testcases[i].z);
		checkoutput(num,testcases[i].output);
	}


	return 0;
}

int calculate(int a, int b, int c)
{
		int n,result;
	n=power(a,b);
	result=n%c;
	return result;
}
int power(int a, int b)
{
	int mul=1, i;
	for(i=0;i<b;i++)
	{
		mul=mul*a;
	}
	return mul;
}
int checkoutput(int ouroutput, int originaloutput)
{
	if(ouroutput==originaloutput)
		printf("Valid");
	else
		printf("Invalid");
	return 0;
}

