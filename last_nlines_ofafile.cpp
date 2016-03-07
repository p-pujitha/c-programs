#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void print_last_k_lines_file_1(char *file_name, int k);


void main()
{
	print_last_k_lines_file_1("puji.txt", 5);
	
	
	getch();
}

void print_last_k_lines_file_1(char *file_name, int k)			//  n-k method
{
	FILE *p1, *p2;
	char ch;
	int count = 0, count2 = 0;

	p1 = fopen(file_name, "r");

	if (p1 == NULL)
		printf("Error: File not found");
	while (!feof(p1))
	{
		if (fgetc(p1) == '\n')
			count++;
	}

	p2 = fopen(file_name, "r");

	while (!feof(p2))
	{
		ch = fgetc(p2);
		if (ch == '\n')
			count2++;
		if (count2 > count - k)
			putchar(ch);
	}
	fclose(p1);
	fclose(p2);
}