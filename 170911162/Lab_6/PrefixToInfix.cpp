//prefix to infix
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
    char pfix[20], pf[20]; char inf[50];
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
		     pfix[j++]=pf[i];
		    }
		  pfix[j]='\0';
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
void con()
 {
    char res[20],f[20],g[20],w[30],o[30],y[60];
    int k=0;
    for(i=0;pfix[i]!='\0';i++)
      {
        if(isoperand(pfix[i])==1)
             {
                w[0]=pfix[i];
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
                o[0]=pfix[i];
                o[1]='\0';
               strcat(res,o);
               strcat(res,g);
               strcat(res,")");
                push(res);
            }
       }
    strcpy(y,pop());
     cout<<"infix";
   puts(y);
  }
};
int main()
 {  
    eval s;
   s.read();
   s.con();
   return 0;
}
