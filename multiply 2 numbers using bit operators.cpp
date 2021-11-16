/* Multiplication of 2 numbers without using multiplication or addition operators */
#include<stdio.h>
#include<conio.h>
int dotest();
	int multiply(int , int);
int checkoutput(int, int);
struct test
{
	int n1;
	int n2;
	int output;
} testcases[3]=
{
	{2,3,6},
	{10,20,200},
	{0,2,0},
	
	
};
int main()
{
	dotest();
	getch();
	return 0;
}
int dotest()  
{
	int n,i;
	for(i=0;i<3;i++) 
	{
		n=multiply(testcases[i].n1,testcases[i].n2);
		checkoutput(n,testcases[i].output);

	}
	return 0;
}
int checkoutput(int a,int b)
{
	if(a==b)
		printf("Valid");
	else
		printf("Invalid");
 return 0;
}
int multiply(int n1, int n2)
{
	int n3,n4,i,x,y;
	if(n1==0 || n2==0)
		return 0;
	else
	{
	n3 = n2;
  n4 = n2;
  n1-=1;
  for(i = n1;i > 0;i-=1)
  { 
    do { 
      x = n2 & n3; 
      y= n2 ^ n3; 
      n2 = x << 1; 
      n3 = y; 
    } while (x);
    n2 = y;
    n3 = n4;

  }
	}
 //printf("Product of the two numbers is %d",y);
 return y;
}