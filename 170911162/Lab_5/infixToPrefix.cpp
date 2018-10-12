#include <iostream>
#include <stdio.h>
#include <string.h>
#define maxe 30
using namespace std;
class in2pre
{
    int top=-1;
    char s[maxe],pfix[maxe],infix[maxe];
public:
    void push(char);
    char pop();
    void read();
    int prec(char);
    int isEmpty();
    void conv();
};
int in2pre::isEmpty()
{
    if(top==-1)
        return 1;
    return 0;
}
void in2pre::push(char x)
{
    if(top==maxe-1)
        cout<<"Overflow!";
    else
        s[++top]=x;
}
char in2pre::pop()
{
    if(top==-1)
            return '#';
    else
        return s[top--];
}
void in2pre::read()
{
    cout<<"Enter the Infix Expression : ";
    gets(infix);
    strrev(infix);
}
int in2pre::prec(char x)
{
    switch(x)
    {
    case '+':
    case '-':return 2;
    case '*':
    case '/':return 3;
    default: return 1;
    }
}
void in2pre::conv()
{
    int i,p1,k=0;
    char e1,e2;
    for(i=0;infix[i]!='\0';i++)
    {
        e1=infix[i];
        switch(e1)
        {
            case ')':push(e1);
                     break;
            case '(':while((e2=pop())!=')')
                      pfix[k++]=e2;
                     break;
            case '+':
            case '-':
            case '*':
            case '/':if(!isEmpty())
                     {
                         p1=prec(e1);
                         e2=pop();
                         while(p1<=prec(e2))
                         {
                             pfix[k++]=e2;
                             if(!isEmpty())
                                e2=pop();
                            else
                                break;
                         }
                         if(p1>prec(e2))
                            push(e2);
                      }
                      push(e1);
                      break;
            default:pfix[k++]=e1;
        }
    }
    while(!isEmpty())
        pfix[k++]=pop();
    pfix[k]='\0';
    strrev(pfix);
    puts(pfix);
}
int main()
{
    in2pre ob;
    ob.read();
    cout<<"Postfix expression: ";
    ob.conv();
}
