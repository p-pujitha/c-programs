/* Add two integer strings */
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
int dotestcases();
int checkoutput(char [], char []);
void add_integerstrings(char [], char[],int );
void add2integerstrings(char[],char[],int);
void addnumbers(char[],char[],int);
int noofdigits(int);
struct test
{
	char input1[40];
	char input2[40];
	char output[40];

}
testcases[4]={
	{ "123","19","142" },       /*  1=carry */
	{"5231","123","5354" },     /* 123 */
     { "111","222","333"},		 /* 19 */
   {"99","9","108"}				/*-------*/   /* 99+9=108 works in both method 2 and 3 */
							   /*  142  */
};
void main()
{
	dotestcases();
	getch();
}
int dotestcases()
{
	printf("\nmethod1:");
	for(int i=0;i<4;i++)
	{
		add_integerstrings(testcases[i].input1, testcases[i].input2,i);
		
	}
	printf("\n Method2:");
	for(int i=0;i<4;i++)
	{
		addnumbers(testcases[i].input1, testcases[i].input2,i);
		
	}
	printf("\n Method 3:");
	for(int i=0;i<=3;i++)
	{
		add2integerstrings(testcases[i].input1, testcases[i].input2,i);
		
	}
	return 0;
}
void  add_integerstrings(char a[], char b[], int index)
{
	int i;
	char newstring[30], *string;
	int carry=0,sum=0,j=0;
	int alength=strlen(a);
	int blength=strlen(b);
	if(alength > blength || alength==blength)
	{
		int k=blength;
		for( i=alength-1;i>=0 && k!=0 ;i--,k--)
		 {
			 int anum=a[i]-'0';
			 int bnum=b[k-1]-'0';
			 sum=anum+bnum+carry;
			 if(noofdigits(sum)==2)
			 {
				 carry=sum/10;
				 newstring[j]=(char)((sum%10)+'0');
				 j++;
				 a[i-1]=(char) (((a[i-1]-'0')+carry) +'0');
				 carry=0;
			 }
			 else
			 {
				 newstring[j]=(char)(sum+'0');
				 j++;
				 
			 }
		 }
		for(int k=0;k<=i;k++)
		{
			int anum=a[k]-'0';
				int total=anum+carry;
			newstring[j]=(char) (total+'0');
			j++;
			carry=0;
		}



		 newstring[j]='\0';
	}

	else
	{

	int k=alength;
		for( i=blength-1;i>=0 && k!=0 ;i--,k--)
		 {
			 int bnum=b[i]-'0';
			 int anum=a[k-1]-'0';
			 sum=anum+bnum+carry;
			 if(noofdigits(sum)==2)
			 {
				 carry=sum/10;
				 newstring[j]=(char)((sum%10)+'0');
				 j++;
				 b[i-1]=(char) (((b[i-1]-'0')+carry) +'0');
				 carry=0;
			 }
			 else
			 {
				 newstring[j]=(char)(sum+'0');
				 j++;
				 
			 }
		 }
		for(int k=0;k<=i;k++)
		{
			int bnum=b[k]-'0';
				int total=bnum+carry;
			newstring[j]=(char) (total+'0');
			j++;
			carry=0;
		}



		 newstring[j]='\0';
	}
	strrev(newstring);
	string=newstring;
	checkoutput(string, testcases[index].output);
}
void add2integerstrings(char str1[], char str2[], int index)
{
	char str3[50];
	int i,j,carry=0,sum,k=0;
	int str1length=strlen(str1);
	int str2length=strlen(str2);
	 j=str1length-1;

	for(i=str2length-1;i>=0;i--)
	{
		if(j>=0)
		{
			int str2num=str2[i]-'0';
			int str1num=str1[j]-'0';
			sum=str2num+str1num+carry;
			if(noofdigits(sum)==2)
			{
				str3[k]= (sum%10) + '0';
					carry=sum/10;
					k++;
			
			}
			else
			{
				str3[k]=(sum%10) + '0';
				k++;
				carry=0;
				
			}
		}
		j--;
		sum=0;
	}
		for(int l=0;l<=j;l++)
		{
			sum=(str1[l]-'0')+carry;
			if(noofdigits(sum)==2)
			{
				str3[k]= (sum%10) + '0';
				carry=sum/10;
				k++;
			}
			else
			{
				str3[k]= (sum%10) + '0';
				k++;
				carry=0;
			}
		}
		if(carry!=0)
		{
			str3[k]=carry+'0';
			k++;
		}
		str3[k]='\0';

			strrev(str3);

/*for(int k=0;str3[k]!='\0';k++)
{
	printf("%c",str3[k]);
}*/
checkoutput(str3, testcases[index].output);
}

int noofdigits(int num)
{
	int rem, sum=0;
	while(num!=0)
	{
		rem=num%10;
		sum=sum+1;
		num=num/10;
	}
	return sum;
}

void addnumbers(char str1[], char str2[], int index)
{
	int n1,n2,sum,k=0,rem;
	char str3[50];
	n1=atoi(str1);
	n2=atoi(str2);
	//printf("\n%d\n%d",n1,n2);
	sum=n1+n2;
	//printf("%d",sum);
	while(sum!=0)
	{
		rem=sum%10;
		str3[k]=rem+'0';
		sum=sum/10;
		k++;
	}
	str3[k]='\0';
	strrev(str3);
  /* for(int i=0;str3[i]!='\0';i++)
	{
		printf("%c",str3[i]);
	}*/
	 checkoutput(str3,testcases[index].output);
}



int checkoutput(char getoutput[], char originaloutput[])
{
	int i,flag=0;
	/*for(i=0;getoutput[i]!='\0';i++)
		printf("%c",getoutput[i]);*/

	for(i=0;getoutput[i]!='\0';i++)
	{
		if(getoutput[i]==originaloutput[i]){
			flag=1;
			i++;}
		else
			break;
	}
	if(flag==1)
		printf("\nValid");
	else
		printf("\nInvalid");
return 0;
}

