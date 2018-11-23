
#include<iostream>
#include<string>
#include<bits/stdc++.h>
#define Max 100
using namespace std;
class ExpTree
{
	char data;
	ExpTree *left;
	ExpTree *right;
public:
	ExpTree* construct(char []);
	ExpTree* create(char);
	void inorder(ExpTree*);
	void display(ExpTree*, int);
	int eval(ExpTree*);
	bool isOp(char);
	ExpTree()
	{
		left = right = NULL;
	}
};
class Stack
{
	ExpTree *st[Max];
	int t;
public:
	void push(ExpTree*);
	ExpTree* pop();
	int toInt(char);
	Stack()
	{
		t = -1;
	}
};
int Stack::toInt(char s)
{
	return s - '0';
}
void ExpTree::display(ExpTree *root, int level)
{
	int i;
	if(root == NULL)
		return;
	display(root->right, level + 1);
	for(i = 0; i < level; i++)
		cout<<"\t";
	cout<<root->data<<endl;
	display(root->left, level + 1);
}
ExpTree* ExpTree::construct(char post[])
{
	Stack obj;
	ExpTree *t, *t1, *t2;
	for(unsigned int i = 0; i < strlen(post); i++)
	{
		if(!isOp(post[i]))
		{
			t = create(post[i]);
			obj.push(t);
		}
		else
		{
			t = create(post[i]);
			t1 = obj.pop();
			t2 = obj.pop();
			t->left = t1;
			t->right = t2;
			obj.push(t);
		}
	}
	t = obj.pop();
	return t;
}
ExpTree* ExpTree::create(char v)
{
	ExpTree *temp = new ExpTree();
	temp->data = v;
	return temp;
}
void ExpTree::inorder(ExpTree *root)
{
	if(root)
	{
		inorder(root->left); 
		cout<<root->data<<endl; 
		inorder(root->right); 
	}
}

int ExpTree::eval(ExpTree *root) 
{
	Stack obj;
	if(!root){
		return 0;
	}
	if(root->left != NULL && root->right != NULL)
	{
		int left = obj.toInt(eval(root->left));
		int right = obj.toInt(eval(root->right));
		switch(root->data)
		{
			case '+':
				return left + right;
			case '-':
				return left - right;
			case '*':
				return left * right;
			case '/':
				return left / right;
		}
	}
	else
		return root->data;
	return 0;
}
void Stack::push(ExpTree *ExpTree)
{
	st[++t] = ExpTree;
}
ExpTree* Stack::pop()
{
	if(t == -1)
		return NULL;
	return st[t--];
}
bool ExpTree::isOp(char s)
{
	switch(s)
	{
		case '+':
		case '-':
		case '*':
		case '/':
			return true;
	}
	return false;
}
int main()
{
	ExpTree tree;
	char post[Max];
	cout<<"Enter postfix expression\n";
	cin>>post;
	ExpTree *root = tree.construct(post);
	tree.display(root, 1);
	cout<<tree.eval(root);
	return 0;
}