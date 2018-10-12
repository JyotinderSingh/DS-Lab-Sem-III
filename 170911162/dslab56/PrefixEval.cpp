//PREFIX EVAL
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#define SIZE 20
using namespace std;
class eval{
 private:
 int top;
  int a[20];
 public:
   char pfix[20] , pf[20];

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
     void  read()
	   {   int l,i,j=0;
	       cout<<"enter the prefix expression";
	       gets(pf);
	       l=strlen(pf);
		for(i=l-1;i>=0;i--)
		    {
		     pfix[j++]=pf[i];
		    }
		  pfix[j]='\0';
		  cout<<"reversed expression";
		  puts(pfix);

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
	     {  a=pfix[i];

		if(isoperand(a)==1)
		 {
		  push(a-'0');
		 }
		else
		{
		 op2=pop();
		 op1=pop();
		 res=operation(op2,a,op1);
		 push(res);

		}
	      }
	     cout<<"prefix evaluation "<<pop();
	 }
};
 int main()
{      eval s;
    s.read();
    s.con();
    return 0;
}
