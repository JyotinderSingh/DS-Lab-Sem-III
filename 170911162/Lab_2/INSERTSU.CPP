#include<iostream.h>
#include<conio.h>
#include<stdio.h>

int insertString(char str[], char sub[], int pos)
{
	for(int len=0; str[len]!='\0'; ++len);
	if(pos<0)
	{
		cout<<"\nInvalid Position\n";
		return 0;
	}
	else if(pos>len)
	{
		cout<<"\nInvalid Position\n";
		return 0;
	}
	else
	{
		char temp[30];
		for(int k=0; str[k]!='\0'; ++k)
		{
			temp[k] = str[k];
		}
		temp[k] = '\0';
		for(int j=pos, i=0; sub[i]!='\0'; ++i,++j)
		{
			str[j] = sub[i];
		}

		for(i=pos;temp[i]!='\0'; ++i, ++j)
		{
			str[j]=temp[i];
		}
		str[j]='\0';
	}
	return 1;

}

int main()
{
	clrscr();
	int pos;
	char str[30], sub[30];
	cout<<"Enter the string: ";
	gets(str);
	cout<<"Enter the sub string: ";
	gets(sub);
	cout<<"Enter the position at which the "
		<<"sub string should be inserted: ";
	cin>>pos;
	pos--;
	if(insertString(str, sub, pos))
		cout<<"\nNew string is: "<<str;
	else
	{
		cout<<"\nError Occured\n";
	}
	getch();
	return 0;

}