/* binary to octal directly :
1011 -> 001 | 011 -> 1 3 */
/* convert binary to decimal and decimal to octal */
#include<stdio.h>
#include<conio.h>
#include<string.h>
int dotest();
int binarytooctal(char []);
int binary_to_octal(char []);
int power (int ,int);
int decitooct(int);
int checkoutput(int ,int);

struct test
{
	char bin[30];
	int num;
}
testcases[3]={
	{"1011",13},
	{"101",5},
	{"0",0}
};
void main()
{
	dotest();
	 getch();
}
int dotest()
{
	printf("\n Converting binary to decimal and decimal to octal ");
	for(int i=0;i<3;i++)
	{
		int n=binarytooctal(testcases[i].bin);
		checkoutput(n,testcases[i].num);
	}
	printf("\n Converting directly from binary to octal ");
	for(int i=0;i<3;i++)
	{
		int n=binary_to_octal(testcases[i].bin);
		checkoutput(n,testcases[i].num);
	}
	return 0;
}
int binarytooctal(char str[])
{
	int strlength=strlen(str),j=0,sum=0;
	for(int i=strlength-1;i>=0;i--)
	{
		int n=str[i]-'0';
		if(n==1)
		{
			sum=sum+n*power(2,j);
			j++;
		}
		else
		{
			j++;
		}
	}
//	printf("%d",sum);
	int output=decitooct(sum);
	return output;
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
int decitooct(int n)
{
	 int a[30],i=0,j;
	 long int count=0;
	while(n!=0)
	{
		a[i]=n%8;
		n=n/8;
		i++;
	}
	
	for(int j=i-1;j>=0;j--)
	{
		//printf("%d",a[j]);
		count=count*10+a[j];
	}
/*	printf("\t%d",count);
	printf("\n");*/
	return count;
}
int checkoutput(int a, int b)
{
	if(a==b)
		printf("\nvalid");
	else
		printf("\nInvalid");
	return 0;
}

int binary_to_octal(char str[])
{
	int strlength=strlen(str);
	int count=0,j=1,a[10],k=0,sum=0,pow=0,i,n;
//	printf("%d",strlength);
	for(i=strlength-1;i>=0;)
	{
		while(j!=4 && i!=-1 )
		{
		 n=str[i]-'0';
		if(n==1)
		{
		count=count+(n* power(2,pow));
		pow++;
		}
		else
		{ pow++;
		}
		j++;
		i--;
		}
		
			//printf("%d\t",count);
			a[k]=count;
			count=0;
			pow=0;
			j=1;
			k++;
		
		

	}
	for(int i=k-1;i>=0;i--)
	{
		sum=sum*10+a[i];
	}
	//printf("%d",sum);
	return sum;
}








