#include<stdio.h>
#include<string.h>
#include<conio.h>

struct test{
	char a[30];
	char output[50];
}
testcases[1]=
{
	{"1/1/2015","oneJanuaryof twothousandfifteen"}
};
void fundate(char [], int);
void dotest();
char* calculate(int);
char* calculatemonth(int);
char* letters(int,int,int);
int checkoutput(char *, char *);
void main()
{
	
	dotest();

	getch();
}
void dotest()
{
	int i;
	for(i=0;i<1;i++)
	{
		fundate(testcases[i].a,i);
	}
}
void fundate(char str[], int index)
{
	char a[100],* result;
	int day,month,year;
	int b[50],j=0, i,countvalue=0,sum=1,k,l=0,len;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]=='/')
		{
			if(sum==1)
			{
				day=countvalue;
				countvalue=0;
				sum=sum+1;
			}
			else if(sum==2)
			{
				month=countvalue;
				countvalue=0;
				sum=sum+1;
			}

		}
		else
		{
			b[j]=str[i]-'0';
			countvalue=countvalue*10 +b[j];

		}
	}
	if(sum==3)
		year=countvalue;
	/*printf("day=%d",day);
	printf("month=%d",month);
	printf("Year=%d",year);*/
 result=letters(day,month,year);
 for(i=0;result[i]!='\0';i++)
	 {
		 printf("%c",result[i]);
 }checkoutput(result,testcases[index].output);
}
char* letters(int day, int month, int year)
{
	char *day1, *month1, *year1;
	int i,j=0,k;
	char finalresult[400];
	char *result;
	day1=calculate(day);
	for(i=0;day1[i]!='\0';i++)
	{
		finalresult[j]=day1[i];
		j++;
	}
	month1=calculatemonth(month);
	for(i=0;month1[i]!='\0';i++)
	{
		finalresult[j]=month1[i];
		j++;

	}
	year1=calculate(year);
	
	
	for(i=0;year1[i]!='\0';i++)
	{
		finalresult[j]=year1[i];
		j++;
	}
	finalresult[j]='\0';
	result=finalresult;
	return result;
	
}
	
char *calculate( int n)
{
	char thous[30]={"thousand"},hun[30]={"hundred"};
	char result[50];
	char* finalresult;
	
	int j=0,i;
	char a[10][10]={ "one","two","three","four","five","six","seven","eight","nine"};
	char b[10][10]={"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
	char c[10][10]={"ten","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
	int t;
	if(n>1000)
	{
		t=n/1000;
		n=n%1000;
		for( i=0; a[t-1][i]!='\0';i++)
		{
			result[j]=a[t-1][i];
			j++;
		}
		for(i=0;thous[i]!='\0';i++)
		{
			result[j]=thous[i];
			j++;
		}
	}
	if(n>100)
	{
		t=n/100;
		n=n%100;

		for(i=0;a[t-1][i]!='\0';i++)
		{
			result[j]=a[t-1][i];
			j++;
		}
		for(i=0;hun[i]!='\0';i++)
		{
			result[j]=hun[i];
			j++;
		}
	}
	if(n>=10 && n<20)
	{
		t=n%10;
		for(i=0;b[t-1][i]!='\0';i++)
		{
			result[j]=b[t-1][i];
			j++;
		}
		
	}
	if(n>19 && n<=100)
	{
		t=n/10;
		n=n%10;
		for(i=0;c[t-1][i]!='\0';i++)
		{
			result[j]=c[t-1][i];
			j++;
		}
	}
	if(n<10)
	{
		for(i=0;a[n-1][i]!='\0';i++)
		{	
			result[j]=a[n-1][i];
		    j++;
			
		}
		
	}
	result[j]='\0';
	
	finalresult=result;
	return finalresult;
}
char * calculatemonth(int n)
{
	char *result, finalresult[40];
	int i;
	char a[12][30]={"Januaryof ", "Februaryof","Marchof", "Aprilof","Mayof"," Juneof", "Julyof","Augustof","Septemberof","octoberof", "Novemberof","Decemberof" };
	for(i=0;a[n-1][i]!='\0';i++)
	{
		finalresult[i]=a[n-1][i];
	}
	finalresult[i]='\0';
	result=finalresult;
	return result;
}
int checkoutput(char *a, char *b)
{
	int i,flag=0;
	for(i=0;a[i]!='\0';)
	{
		if(a[i]==b[i])
		{
			i++;
			flag=1;
		}
		else
		{
			flag=0;
			break;
		}
	}
		if(flag==1)
			printf("Valid");
		else
			printf("Invalid");
	return 0;
}
	

	
	
	