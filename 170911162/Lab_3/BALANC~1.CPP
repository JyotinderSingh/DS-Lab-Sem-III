#include<iostream.h>
#include<conio.h>
#include<stdio.h>

const int MAX = 30;
class Stack{

	char data[MAX];
	int Top;
public:
	Stack()
	{
	       Top = -1;
	}
	void push(int);
	int pop();
	void display();
	int isEmpty();
	int top();
};

void Stack ::push(int ele)
{
	if(Top == MAX-1)
	{
		cout<<"\nOverflow\n";
		return;
	}
	data[++Top] = ele;
}
int Stack :: top()
{
	return data[Top];
}

int Stack ::pop()
{
	if(Top == -1)
	{
		cout<<"\nUnderflow\n";
		return -99999;
	}
	else
	{
		int x = data[Top--];
		return x;
	}
}

void Stack ::display()
{
	cout<<endl;
	for(int i =0; i<=Top; ++i)
	{
		cout<<data[i]<<" <- ";
	}
	cout<<endl;
}

int Stack ::isEmpty()
{
	if(Top<0)
	{
	return 1;
	}
	else
	{
	return 0;
	}
}


int isParanthesBalanced(char str[])
{
	Stack s;
	char x;

	for (int i=0; str[i]!='\0'; i++)
	{
		if (str[i]=='('||str[i]=='['||str[i]=='{')
		{
			s.push(str[i]);
			continue;
		}

		if (s.isEmpty())
			return 0;

		switch (str[i])
		{
			case ')':

				x = s.top();
				s.pop();
				if (x=='{' || x=='[')
					return 0;
				break;

			case '}':

				x = s.top();
				s.pop();
				if (x=='(' || x=='[')
					return 0;
				break;

			case ']':

				x = s.top();
				s.pop();
				if (x =='(' || x == '{')
					return 0;
				break;
		}
	}

	return (s.isEmpty());
}


int main()
{
	clrscr();
	char str[20];
	gets(str);
	if(isParanthesBalanced(str)==1)
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
	getch();
}