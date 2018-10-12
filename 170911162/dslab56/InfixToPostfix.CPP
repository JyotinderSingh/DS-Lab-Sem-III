// INFIX TO POSTFIX
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 20
using namespace std;
class constack{
 private:
    int top;
    char a[20];
 public:
     char inf[20];
     constack()
      {
           top=-1;
      }
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
                cout<<"stack empty";
            else
                return (a[top--]);
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
    void read();
    void con();
    };
    void constack::read()
	   {
	       cout<<"enter the infix expression";
	       gets(inf);
	   }
    void constack::con()
	{
	 int i=0,j=0;
	  char postf[20];
	  char b;
	  for(i=0;inf[i]!='\0';i++)
	    {
	       char a=inf[i];
	       switch(a)
		{
		 case '(':
		    {  push(a);
		       break;
		    }
		 case ')':
		    {
		       b= pop();
		       if(b!='(')
			   {
			     postf[j++]=b;
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
				      postf[j++]=b;
				      if(isempty()==0)
					 b=pop();
				      else
					break;
				    }
				if(pre(a)>pre(b))
				{
				   if(b!='(')
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
			  postf[j++]=a;
			  break;
			}

		    }
		 }


	      while(isempty()==0)
		   {postf[j++]= pop();
		   }
	      postf[j]='\0';
	     cout<<"the obtained postfix expression is \n";

	     cout<< postf;
	   }

  int main()
  {
    constack s;
    s.read();
    s.con();
    return 0;
  }
