#include<iostream.h>
#include <stdio.h>
#include <string.h>
#include<conio.h>

const int MAX = 30;
class Stack{

	char data[MAX];
	int top;
public:
	Stack()
	{
		top = -1;
	}
	void push(int);
	int pop();
	void display();
	int isEmpty();
};

void Stack ::push(int ele)
{
	if(top == MAX-1)
	{
		cout<<"\nOverflow\n";
		return;
	}
	data[++top] = ele;
}

int Stack ::pop()
{
	if(top == -1)
	{
		cout<<"\nUnderflow\n";
		return -99999;
	}
	else
	{
		int x = data[top--];
		return x;
	}
}

void Stack ::display()
{
	cout<<endl;
	for(int i =0; i<=top; ++i)
	{
		cout<<data[i]<<" <- ";
	}
	cout<<endl;
}

int Stack ::isEmpty()
{
	if(top<0)
	{
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
	Stack s;
	char str[30];
	cout<<"Enter a string: ";
	cin>>str;
	for(int i = 0; str[i]!='\0'; ++i)
	{
		s.push(str[i]);
	}
	char revString[30];
	int j=0;
	while(s.isEmpty()==1)
	{
		revString[j++] = s.pop();
	}
	revString[j] = '\0';
	if(!strcmp(revString,str))
	{
		cout<<"String is a palindrome!";
	}
	else
	{
		cout<<"String is NOT a palindrome";
	}

	getch();
	return 0;
}