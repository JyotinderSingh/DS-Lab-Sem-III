//prefix to postfix
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdio.h>
#define SIZE 20
using namespace std;
class eval{
private:
	int top;
	char a[20][20];
public:
	char pref[20], pf[20], inf[50];
	int i=0,c=0,m=0;
	eval()
	{
		top=-1;
	}
	void push(char* ele)
	{
		if(top==SIZE-1)
			cout<<"stack overflow";
		else
			strcpy( a[++top],ele);

	}
	char* pop()
	{
		if(top==-1)
			return NULL;
		else
			return a[top--];
	}
	void  read()
	{   int l,i,j=0;
		cout<<"enter the prefix expression";
		gets(pf);
		l=strlen(pf);
		for(i=l-1;i>=0;i--)
		{
			pref[j++]=pf[i];
		}
		pref[j]='\0';
		puts(pref);

	}

	int isoperand(char z)
	{ switch(z)
		{
			case '+':
			case '-':
			case'*':
			case '/':
			case'^':
			case'$':
			{return 0;
				break;
			}
			default:
			{
				return 1;
				break;
			}
		}
	}
	void conprein()
	{
		char res[20],f[20],g[20],w[30],o[30];
		int k=0;
		for(i=0;pref[i]!='\0';i++)
		{
			if(isoperand(pref[i])==1)
			{
				w[0]=pref[i];
				w[1]='\0';
				push(w);
			}
			else
			{
				strcpy( f,pop());
				strcpy( g, pop());
				res[0]='(';
				res[1]='\0';
				strcat(res,f);
				o[0]=pref[i];
				o[1]='\0';
				strcat(res,o);
				strcat(res,g);
				strcat(res,")");
				push(res);
			}
		}
		strcpy(inf,pop());
		cout<<"infix";
		puts(inf);
	}
	int isempty()
	{
		if(top==-1)
			return 1;
		else
			return 0;
	}
	int pre(char z)
	{
		switch(z)
		{
			case '(': return 0;
			case '+':
			case '-': return 1;
			case '*':
			case '/':
			case '%': return 2;
			case '$':
			case '^': return 3;
		}
	}
	void coninpost()
	{
		int i=0,j=0;
		char postf[20]={'0'};
		char b[20],q[20],u[20],e[20],t[20];
		for(i=0;inf[i]!='\0';i++)
		{
			char a=inf[i];
			switch(a)
			{
				case '(':
				{
					q[0]='(';
					q[1]='\0';
					push(q);
					break;
				}
				case ')':
				{
					strcpy(b, pop());
					if(b[0]!='(')
					{
						postf[j++]=b[0];
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
						strcpy(b, pop());
						while(pre(a)<=pre(b[0]))
						{
							postf[j++]=b[0];

							if(isempty()==0)
								strcpy(b,pop());
							else
								break;
						}
						if(pre(a)>pre(b[0]))
						{
							if(b[0]!='(')
							{
								u[1]=b[0];
								u[0]='\0';
								push(u);
							}

						}
						e[0]=a;
						e[1]='\0';
						push(e);
					}
					else
					{
						t[0]=a;
						t[1]='\0';
						push(t);
					}
					break;
				}
				default:
				{ postf[j++]=a;

					break;
				}

			}
		}


		while(isempty()==0)
			{strcat(postf,pop());
			}

			cout<<"the obtained postfix expression is \n";

			cout<< postf;
		}




	};
	int main()
	{
		eval s;
		s.read();
		s.conprein();
		s.coninpost();

		return 0;
	}

