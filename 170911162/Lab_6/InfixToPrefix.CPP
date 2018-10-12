// INFIX TO PREFIX
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 20
class constack{
private:
	int top;
	char a[50];
public:
	char inf[50],infi[50];
	constack()
	{
		top=-1;
	}
	void read();
	void con();
	void push(char ele)
	{
		if(top==MAX-1)
			cout<<"stack overflow";
		else
			a[++top]=ele;
	}
	char pop()
	{
		if(top==-1)
			{	cout<<"stack empty";
		return '#';
	}
	else
		return (a[top--]);
}
int isempty()
{if(top==-1)
	return 1;
	else
		return 0;
}
int pre(char z)
{
	switch(z)
	{
		case ')':
		{return 0;
			break;}
			case '+':
			case '-':{ return 1;break;}
			case '*':
			case '/':
			case '%':{ return 2;break;}
			case '$':
			case '^': {return 3;break;}
		}
	}
};
void constack:: read()
{   int l,i,j=0;
	cout<<"enter the infix expression";
	gets(infi);
	l=strlen(infi);
	for(i=l-1;i>=0;i--)
	{
		inf[j++]=infi[i];
	}
	inf[j]='\0';
	puts(inf);

}

void constack:: con()
{int i=0,j=0,h=0;
	char pref[50],pr[50];
	char b;
	for(i=0;inf[i]!='\0';i++)
	{
		char a=inf[i];
		switch(a)
		{
			case ')':
			{  push(a);
				break;
			}
			case '(':
			{
				b= pop();
				if(b!=')')
				{
					pref[j++]=b;
				}
				break;
			}
			case '+':
			case '-':
			case '*':
			case '/':
			case '$':
			case '^':
			case '%':
			{
				if(isempty()==0)
				{
					b=pop();
					while(pre(a)<=pre(b))
					{
						pref[j++]=b;
						if(isempty()==0)
							b=pop();
						else
							break;
					}
					if(pre(a)>pre(b))
					{
						if(b!=')')
							push(b);
					}
					push(a);
				}
				else
					push(a);
				break;
			}
			default:
			{
				pref[j++]=a;
				break;
			}

		}
	}


	while(isempty()==0)
		{pref[j++]= pop();
		}
		pref[j]='\0';
		int t=strlen(pref);
		for(i=t-1;i>=0;i--)
			{pr[h++]=pref[i];
			}
			pr[h]='\0';
			cout<<"the obtained prefix expression is";
			puts(pr);

		}



		void main()
		{ clrscr();
			constack s;
			s.read();
			s.con();

			getch();
		}
