#include<iostream.h>
#include<conio.h>
#include<stdio.h>

void str_cat(char str1[], char str2[])
{
	for(int i=0; str1[i]!='\0'; ++i);
	for(int j=0; str2[j]!='\0'; ++j)
	{
		str1[i]=str2[j];
		i++;
	}
	str1[i]='\0';
}

int main()
{
	clrscr();
	char str1[30], str2[30];
	cout<<"Enter the first string: ";
	gets(str1);
	cout<<"Enter the second string: ";
	gets(str2);
	str_cat(str1, str2);
	cout<<"String 2 was concatenated to string 1:\n";
	cout<<str1;
	getch();
	return 0;
}