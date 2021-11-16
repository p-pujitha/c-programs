
#include<stdio.h>
#include<conio.h>
int checkoutput(int ,int);
int dotest();
int findlength(int arr[]);
int find_length(int []);
int find(int []);
int binarysearch(int ,int ,int[]);
struct test
{
	int a[30];
	int length;
}
testcases[4]={
	{ {1,2,5,7,9,4,0,0,0,0},4},
	{ {2,4,5,1,0,0},2},
	{ { -1,2,5,3,0,0},2}

};
void main()
{
	dotest();
	getch();
}
int dotest()
{
	printf("Method1:");
	
	for( int i=0;i<3;i++)
	{
		int n=findlength(testcases[i].a);
		checkoutput(n,testcases[i].length);
	}
	printf("\n Method2:");
	for( int i=0;i<3;i++)
	{
		int n=find_length(testcases[i].a);
		checkoutput(n,testcases[i].length);
	}
	printf("\nMethod3:");
	for( int i=0;i<3;i++)
	{
		int n=find(testcases[i].a);
		checkoutput(n,testcases[i].length);
	}
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
int findlength( int a[])
{
	int i=0;
	while(a[i]!=0)
	{i++;
	}
return i-2;
}
int find_length(int a[])
{
	int i=0;
	while(a[i]<a[i+1])
	{
		i++;
	}
	
	return i;
}
int find(int a[])
{
	int j,i=1,num;
	while(a[i]!=0)
	{
		
		j=i;
		i=i*2;
		
	}
	int v1=j;
	int v2=i;
 num= binarysearch( v1,v2,a);
return num;
}
int binarysearch(int j,int i,int a[])
{
	int mid;
	int l=j,h=i;
	while(l<=h)
	{
		mid=(l+h)/2;
	 if(a[mid]!=0 && a[mid]<a[mid-1]&& a[mid]>a[mid+1])
	 return mid-1;
	 else
		if(a[mid]>a[mid-1] && a[mid]!=0)
			 l=l+1;
		else
			h=h-1;
	}
}

