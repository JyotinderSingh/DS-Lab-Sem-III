#include <iostream>
#include <stdio.h>
#define max 30
using namespace std;
class eval
{
    int top;
    int s[max];char pfix[max];
public:
    void read();
    int operate(int,int,char);
    void push(int);
    int pop();
    int isEmpty();
    void findres();
    eval()
    {
        top=-1;
    }
};
void eval::read()
{
    cout<<"Enter the postfix expression : ";
    gets(pfix);
}
void eval::push(int x)
{
    if(top==max-1)
        cout<<"Underflow!";
    else
        s[++top]=x;
}
int eval::pop()
{
    if(top==-1)
      return -999;
    else
        return s[top--];
}
int eval::isEmpty()
{
    if(top==-1)
        return 1;
    return 0;
}
int eval::operate(int a,int b,char c)
{
    switch(c)
    {
        case '+':return a+b;
                 break;
        case '-':return a-b;
                 break;
        case '*':return a*b;
                 break;
        case '/':return a/b;
                 break;
    }
}
void eval::findres()
{
    int i,op1,op2,res;
    for(i=0;i<pfix[i]!='\0';i++)
    {
        if(pfix[i]>48&&pfix[i]<=57)
        {
           push(pfix[i]-'0');
        }

        else
        {
            op2=pop();
            op1=pop();
            res=operate(op1,op2,pfix[i]);
            push(res);
        }
    }
    res=pop();
        if(!isEmpty())
            cout<<"Invalid expression";
        else
            cout<<"The result is : "<<res;
}
int main()
{
    eval ob;
    ob.read();
    ob.findres();
}
