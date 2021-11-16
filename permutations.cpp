/*  Min Rank of a given number: Given an unsigned number as input, find the index of the number (index starts from 0) 
in all permutations of the number, sorted in ascending order. 
input 213: output 2 (as 123, 132, 213, 231, 312, 321 are the permutations and 2 is the index values of 213)*/
#include<stdio.h>
#include<conio.h>
int permutations(int);
void dotest();
int checkoutput( int, int);
struct test
{
	int num;
	int outputindex;
}
testcases[5]=
{
	{231,2},
	{451,4},
	{563,5},
	{678,7},
	{234,5}
};
void main()
{
	dotest();
	getch();
}
void dotest()
{
	int i,index;
	for(i=0;i<5;i++)
	{
		index=permutations(testcases[i].num);
		checkoutput( index,testcases[i].outputindex);
	}
}
int permutations( int n)
{
	int arr[10],i=0,t,j,finalvalue,temp,k,l,sum=1;
	int per;
	while(n!=0)
	{
		t=n%10;
		n=n/10;
		arr[i]=t;
		i++;
	}
		finalvalue=arr[i-1];
	per=i*(i-1);
	for(j=0;j<i;j++)
	{
		for(k=j+1;k<i;k++)
		{
			if(arr[j]>arr[k])
			{ temp=arr[j];
			  arr[j]=arr[k];
			  arr[k]=temp;
			}
		}
	}
	
	
		
	for(k=0;k<i;k++)
		{
			printf("%d",arr[k]);
			  for(l=0;l<i;l++)
			   {
				if(arr[l]==arr[k])
					continue;
				else
					printf("%d",arr[l]);
			  }
		printf("\t");
		printf("%d",arr[k]);
		for(l=i-1;l>=0;l--)
		{
			if(arr[l]==arr[k])
				 continue;
			else
				printf("%d",arr[l]);
		}
		printf("\t");
	}		
		
 return finalvalue;  
}
int checkoutput(int a, int b)
{
	if(a==b)
		printf("\nValid\n");
	else
		printf("\nInvalid\n");
 return 0;
}

   
