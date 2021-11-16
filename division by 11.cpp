/* Given a unsigned number as a string input (it can be of length max 10000 chars ) write a function to find whether
the number is divisible by 11 or not */

#include<stdio.h>
#include<conio.h>
int dotest();
int divisible_by_11(char []);
int divisibleby11(char []);
int divisibility(char []);
int checkoutput(int,int);
struct test
{
	char a[10000];
	int output;
}
testcases[7]={                            /* if the output is 1 means it is divisible by 11 or 
										    it is not divisible by 11*/
{ "22",1},
{"-90904",1},
{ "-1364",1},									
{ "913",1},									
{ "3729-",1},
{ "9-78",1}	,
{"80902",1},

};											
int  main()										
{
	dotest();
	getch();
	return 0;

}
int dotest()
{
	int i,num;
	printf("\n Method 1:");
	for(i=0;i<7;i++)
	{
		num=divisible_by_11(testcases[i].a);
		checkoutput(num,testcases[i].output);
	}
	printf("\n Method 2 :");
	for(i=0;i<7;i++)
	{
		num=divisibleby11(testcases[i].a);
		checkoutput(num,testcases[i].output);
	}
	printf("\n Method 3: ");
	for(i=0;i<7;i++)
	{
		num=divisibility(testcases[i].a);
		checkoutput(num,testcases[i].output);
	}
	
 return 0;
}
int checkoutput(int org, int res)
{
	if(org==res)
		printf("\nValid");
	else
		printf("\nInvalid");
	return 0;
}

int divisible_by_11( char str[])						  /* Divisibilty rule of 11... */
{	int i,num,countvalue=0,a[30],j,result;				/*913=9-1+3=11 (11%11==0)hence divisible by 11;*/
	if(str[0]=='-')
	{
	for(i=1;str[i]!='\0';i++)
	{
		num=str[i]-'0';
		a[i+1]=num;
		countvalue=countvalue*10+num;
	}
	countvalue=-(countvalue);
	}
	else
	{
		for(i=0;str[i]!='\0';i++)
	{
		num=str[i]-'0';
		a[i+1]=num;
		countvalue=countvalue*10+num;
	}
	}
	//printf("%d",countvalue);
	if(str[0]!='-')
	{
		j=2;
	result=a[1];
	
	while(j<=i)
	{
		if(j%2==0){
			result=result-a[j];
			
			j++;}
		else{
			result=result+a[j];
		
			j++;}
	}}
	else
	{j=3;
	result=a[2];
	
	while(j<=i)
	{
		if(j%2!=0){
			result=result-a[j];
			
			j++;}
		else{
			result=result+a[j];
		
			j++;}
	}}

	//printf("%d",result);
	if((result%11)==0)
		return 1;
	else
		return 0;

}


int divisibleby11( char str[])									/* (evencount-oddcount)%11==0)
																  divisible */
{   
	int i,j,countvalue=0,arr[50],k=0,evencount=0,oddcount=0,ans;	/* eg: 90904= (0+0)-(9+9+4)=22%11==0 it is divisible */
/*	for(i=0;str[i]!='\0';i++)
	{
		printf("%c",str[i]);
	}*/
	if(str[0]=='-')
	{  
		j=1;
	}
	else
	{
		j=0;
	}
	for(i=j;str[i]!='\0';i++)
	{
		int num=str[i]-'0';
		countvalue=countvalue*10+num;
		arr[k]=num;
		k++;
	}
	for(j=0;j<k;j++)
	{
		if(j%2==0)
		{
			evencount=evencount+arr[j];
		}
		else
		{
			oddcount=oddcount+arr[j];
		}
	}
	ans=evencount-oddcount;
/*	if(ans==0 || ans==11 || ans==-11)
		return 1;
	else
		return 0;*/
	if(ans%11==0)
		return 1;
	else
		return 0;

}

int divisibility(char str[])    /* eg: 121%11==0 divisble or it isnot divisible */
{
	int i,j,countvalue=0;
	if(str[0]=='-')
	{  
		j=1;
	}
	else
	{
		j=0;
	}
	for(i=j;str[i]!='\0';i++)
	{
		int num=str[i]-'0';
		countvalue=countvalue*10+num;
	}
	if(countvalue % 11==0)
		return 1;
	else
		return 0;
}

