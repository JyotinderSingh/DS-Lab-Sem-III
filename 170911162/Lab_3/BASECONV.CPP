#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>

const int MAX = 30;
class Stack{

	int data[MAX];
	int Top;
public:
	Stack()
	{
	       Top = -1;
	}
	void push(int);
	int pop();
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

void BaseConverter(long int num, int base)
{
	long int n;
	switch(base)
	{
		case 2:
			Stack bin;
			n=num;
			while(n)
			{
				bin.push(n%2);
				n/=2;
			}
			cout<<endl;
			while(!bin.isEmpty())
			{
				cout<<bin.top();
				bin.pop();
			}
			break;
		case 8:
			Stack oct;
			n=num;
			while(n)
			{
				oct.push(n%8);
				n/=8;
			}
			cout<<endl;
			while(!oct.isEmpty())
			{
				cout<<oct.top();
				oct.pop();
			}
			break;
		case 16:
			Stack hex;
			n=num;
			while(n)
			{
				hex.push(n%16);
				n/=16;
			}
			cout<<endl;
			while(!hex.isEmpty())
			{
				int ele = hex.top();
				hex.pop();
				switch(ele)
				{
					case 10:
						cout<<"A";
						break;
					case 11:
						cout<<"B";
						break;
					case 12:
						cout<<"C";
						break;
					case 13:
						cout<<"D";
						break;
					case 14:
						cout<<"E";
						break;
					case 15:
						cout<<"F";
					default:
						cout<<ele;
				}
			}
			break;


	}
}

int main()
{
	int k;
	do
	{
		clrscr();
		cout<<"Convert decimal to ...\n"
			<<"1. Binary\n"
			<<"2. Octal\n"
			<<"3. Hexadecimal\n"
			<<"4. EXIT\n\n->";
		cin>>k;
		if(k==4)
		{
			exit(0);
		}
		long int num;
		cout<<"\nEnter the decimal number: ";
		cin>>num;
		switch(k)
		{
			case 1:
				BaseConverter(num, 2);
				break;
			case 2:
				BaseConverter(num, 8);
				break;
			case 3:
				BaseConverter(num, 16);
				break;
			case 4:
				exit(0);
			case 5:
				cout<<"\nInvalid Choice";
		}
	getch();
	}while(k!=4);
	getch();
}