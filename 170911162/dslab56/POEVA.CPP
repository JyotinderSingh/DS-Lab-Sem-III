//POSTFIX EVAL
#include<iostream.h>
#include<math.h>
#include<stdio.h>
#include<conio.h>
#define SIZE 20

class eval{
 private:
 int top;
  int a[20];
 public:
   char pfix[20];

   eval()
     {
	top=-1;
     }
    void push(int ele)
     {
      if(top==SIZE-1)
	cout<<"stack overflow";
      else
	a[++top]=ele;
     }
    int pop()
     {
       if(top==-1)
	{
	  cout<<"empty";
	  return 0;
	}
	else
	 return a[top--];
       }
     void read()
      {
	cout<<"enter the postfix expression";
	cin>>pfix;
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
      int operation(int s,char t,int r)
	{
	  switch(t)
	   {
	     case '+':
	      {
		 return (s+r);
		 break;
	      }
	     case'-':
	      {
		return(s-r);
		break;
	      }
	     case'*':
	       {
		return(s*r);
		break;
	       }
	     case '/':
	       {
		return (s/r);
		break;
	       }
	     case '^':
	     case '$':
	       {
		return( pow(s,r));
		break;
	       }
	    }
	 }
      void con()
	 {  char a;
	   int op1,op2,i;
	   int res;

	   for(i=0;pfix[i]!='\0';i++)
	     {   a=pfix[i];

		if(isoperand(a)==1)
		 {
		  push(a-'0');
		 }
		else
		{
		 op2=pop();
		 op1=pop();
		 res=operation(op1,a,op2);
		 push(res);

		}
	      }
	     cout<<"infix expression"<<pop();
	   }
};
void main()
{  clrscr();
    eval s;
    s.read();
    s.con();
    getch();
}
