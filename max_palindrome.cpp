#include<stdio.h>
#include<conio.h>
#include<malloc.h>

int check_even_digits(int num);
int iseven(int num, int arr[],int i);
int max_palindrome(int num);
int make_no(int *arr,int i);
int * arraynum(int num, int *len);
int reverse(int num);
int check_output(int a,int b);
void dotest();
struct test
{
	int input;
	int output;
}
testcases[2]={{2112, 2112}
};
void main()
{
	dotest();
	getch();
}

void dotest()
{
	for(int i=0;i<1;i++)
	{
		int check=check_even_digits(testcases[i].input);
		if(check==1)
		{
			int op=max_palindrome(testcases[i].input);
			int check_op=check_output(op,testcases[i].output);
			if(check_op==1)
				printf("Valid");
			else
				printf("Invalid");
		}
	}
}


int check_even_digits(int num)
{
	int *arr=(int *)malloc(sizeof(int)*10),i=0;
	int new_arr[10],k=0;
	int rem;
	while(num!=0)
	{
		rem=num%10;
		arr[i]=rem;
		i++;
		num=num/10;
	}
	for(int j=i;j>=0;j++)
	{
		int flag=0;
		new_arr[k]=arr[j];
		k++;
		for(int l=0;l<k;l++)
			if(arr[j]=new_arr[l]){
				flag=1;
				break;}
		if(flag!=1)
			new_arr[k]=arr[j];
	}
	int flag=0;
	for(int l=0;l<k;l++)
	{
		int ans=iseven(new_arr[k],arr,i);
		if(ans==1)
			l++;
		else{
			flag=1;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}


int iseven(int num, int arr[],int i)
{
	int count=0;
	for(int j=0;j<i;j++)
		if(num==arr[j])
			count++;
	if(count%2==0)
		return 1;
	else
		return 0;
}

int max_palindrome(int num)
{
	int *arr=(int *)malloc(sizeof(int)*10);
	int len=0,i=0;
	int *a=arraynum(num,&len);
	
	
	for(int j=len;j>=0;j--)
	{
		arr[i]=a[j];
	}
	len=i;
	int k=0;

	/*while(k!=len)
	{
	     i++;
			arr[i]=arr[k];
		int num=make_no(arr,i);
		int ans=reverse(num);
		if(ans==num)
			return ans;
		else
			k++;
	}*/

	for(int i=1;i<len;i++)
	{


	}



}

	int make_no(int *arr,int i)
	{
		int sum=0;
		for(int j=0;j<i;j++)
			sum=(sum * 10) +arr[j];
		return sum;
	}
		

	
int * arraynum(int num, int *len)
{
	
	int *arr=(int *)malloc(sizeof(int)*10),i=0;
	int new_arr[10],k=0;
	int rem;
	while(num!=0)
	{
		rem=num%10;
		arr[i]=rem;
		i++;
		num=num/10;
	}
	return arr;
	*len=i;
}
int reverse(int num)
{
	int *arr=(int *)malloc(sizeof(int)*10),i=0;
	int new_arr[10],k=0;
	int rem;
	while(num!=0)
	{
		rem=num%10;
		arr[i]=rem;
		i++;
		num=num/10;
	}
	int sum=0;
	for(int j=0;j<i;j++)
	{
		sum=sum*10+arr[j];
	} 

	return sum;
} 


int check_output(int a,int b)
{
	
	if(a==b)
		return 1;
	else
		return 0;
}



