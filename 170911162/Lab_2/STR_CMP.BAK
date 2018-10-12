#include<iostream.h>
#include<conio.h>
#include<stdio.h>

int str_len(char str[])
{
	for(int i=0; str[i]!='\0'; ++i);
	return i;
}
int str_cmp(char str1[], char str2[])
{
	int len1, len2;
	len1 = str_len(str1);
	len2 = str_len(str2);
	if(len1 == len2)
	{
		for(int i=0; str1[i]!='\0'; ++i)
		{
			if(str1[i]!=str2[i])
			{
				return  1;
			}
		}
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	clrscr();
	char str1[30], str2[30];
	cout<<"Enter first string: ";
	gets(str1);
	cout<<"Enter second string: ";
	gets(str2);
	if(str_cmp(str1, str2))
	{
		cout<<"\nStrings are different";
	}
	else
	{
		cout<<"\nStrings are the same";
	}
	getch();
	return 0;

}