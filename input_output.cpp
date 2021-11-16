#include<stdio.h>
#include<conio.h>
/*main()
{
	float f=20, width_f=3; // Missing type specifier - int (width_f should be int)
	
	printf("%*.2f",width_f,f);
	getch();
}*/

/*void main()
{
		float a=20.123;
		int width_a;
		printf("Using indirect width specification to display \n");
		printf("Enter the field width off:");
		scanf("%d", width_a);
		printf("%f", width_a, a); //it should be printf("%*f",width_a,a);
		getch();
}
*/

/*void main()
{

	char s1[8], s2[8];
	scanf("%s%s",s1,s2);
	printf("Char1= %c, char2= %c", s1[52-'0'], s2[*s2-0[s2]]+4);
	getch();
	//output => char1 = i, char2 = i;

}
*/

/*void main()
{
	char address[30]= " vidhana soudha, %d, Banglore";
	printf(address); -> //vidhana Soudha, 38765, Banglore
	printf("\n %s",address); -> // viddhana soudha, %d, Banglore
	getch();
}

*/

/*void main()
{
	int j=100;
	printf("%s, %d is a good score ""%s",(j>=100)?"yes":"no", j, (1, ".....OK"), ("No...... ", 1));
	getch();
}
*/

/*void main()
{  //doubt

	int j, i=-1;
	j=i<<8;
	printf("%d\t %x\n",i,i);
	printf("%d\t %x\n",j,j);
	getch();
}
*/

/*void main()
{
	int j=100;
	j=!j>8 && j<100;
	printf("%d\n",j);
	printf("\nb" "\bUV" "CE");
	getch();
}*/

/*void main()
{
	int i;
	scanf("%d", printf("%d\n", scanf("%d",&i)));
	getch();
}*/


/*void main()
{
	static int x=0x8;
	printf("%d",getchar(x));
	getch();
}*/

/*
#include<math.h>
void main()
{
	static int x;
	printf("%d",x=(pow(printf("hi\b"), -~x)));
	getch();
}*/