//postfix to infix
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

class pfix_ifix
{
	char stack[25][25], infix[50];
	char op1[20], op2[20], res[20];
	int top;
public:
	pfix_ifix() {
		top = -1;
	}
	void push(char a[]) {
		strcpy(stack[++top], a);
	}
	char* pop() {
		return stack[top--];
	}
	void pfix(char pfix_exp[]);
};

void pfix_ifix::pfix(char pfix_exp[]) {
	int count = 0;
	char sym[2];
	while (pfix_exp[count] != '\0') {
		sym[0] = pfix_exp[count];
		sym[1] = '\0';
		if(sym[0] == '+' || sym[0] == '-' || sym[0] == '*' || sym[0] == '/' || sym[0] == '^') {
			strcpy(op2, pop());
			strcpy(op1, pop());
			strcpy(res, "(");
			strcat(res, op1);
			strcat(res, sym);
			strcat(res, op2);
			strcat(res, ")");
			push(res);
		}
		else {
			push(sym);
		}
		count++;
	}

	strcpy(infix, pop());
	cout<<"\nInfix Expression: "<<infix;
}

int main()
{
	char exp[50];
	pfix_ifix pi;
	cout<<"\nEnter postfix: ";
	cin>>exp;
	pi.pfix(exp);
}
