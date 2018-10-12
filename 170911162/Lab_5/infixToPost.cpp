#include <iostream>
#include <stdio.h>
#define maxe 30
using namespace std;
class in2po
{
    char infix[maxe],s[maxe],pfix[maxe];
    int top;
public:
    void push(char);
    char pop();
    void read();
    int prec(char);
    void conv();
    void disp();
    int isEmpty();
    in2po()
    {
        top=-1;
    }
};
void in2po::push(char x)
{
    if(top==maxe-1)
        cout<<"Overflow!";
    else
        s[++top]=x;
}
char in2po::pop()
{
    if(top==-1)
        return '#';
    else
        return s[top--];
}
void in2po::read()
{
    cout<<"Enter the infix expression : ";
    gets(infix);
}
int in2po::prec(char x)
{
    switch(x)
    {
    case '+':
    case '-':return 2;
             break;
    case '*':
    case '/':return 3;
             break;
    default :return 1;
    }
}
void in2po::conv()
{
     int i,p1,k=0,p=0;
     char e1,e2;
    for(i=0;infix[i]!='\0';i++)
    {
        char e1=infix[i];
        switch(e1)
        {
            case '(':push(e1);
                     break;
            case ')':while((e2=pop())!='(')
                    {
                        pfix[k++]=e2;
                    }
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
}
void in2po::disp()
{
    puts(pfix);
}
int in2po::isEmpty()
{
    if(top==-1)
        return 1;
    return 0;
}
int main()
{
    in2po ob;
    ob.read();
    ob.conv();
    cout<<"Postfix Expression : ";
    ob.disp();
    return 0;
}
