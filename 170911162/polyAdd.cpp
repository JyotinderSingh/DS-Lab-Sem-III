
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node
{
	int coef;
	int exp;
	node *next;
	node *prev;
public:
	node* set_header();
	node* insert(node *header, int co, int ex);
	node* add(node *h1, node *h2);
	void display(node *header);
	node *build();
};
node* node::set_header()
{
	node *header = new node();
	header->coef = header->exp = 0;
	header->next = header->prev = header;
	return header;
}
node* node::insert(node *header, int co, int ex)
{
	node *temp = new node();
	node *cur = header;
	temp->coef = co;
	temp->exp = ex;
	temp->next = temp->prev = temp;
	if(header->next == header)
	{

		header->next = temp;
		temp->prev = header;
		temp->next = header;
		header->prev = temp;
		return header;
	}
	while(cur->next != header)
		cur = cur->next;
	header->prev = temp;
	temp->prev = cur;
	temp->next = header;
	cur->next = temp;
	return header;
}
node* node::add(node *h1, node *h2)
{
	node *h3 = set_header();
	node *a = h1->next;
	node *b = h2->next;
	while(a != h1 && b != h2)
	{
		if((a->coef + b->coef) != 0 && a->exp == b->exp)
		{
			insert(h3, a->coef + b->coef, a->exp);
			a = a->next;
			b = b->next;
		}
		else if(a->exp > b->exp)
			a = a->next;
		else if(b->exp > a->exp)
			b = b->next;
	}
	while(a != h1)
	{
		insert(h3, a->coef, a->exp);
		a = a->next;
	}
	while(b != h2)
	{
		insert(h3, b->coef, b->exp);
		b = b->next;
	}
	return h3;
}
void node::display(node *header)
{
	if(header->next == header)
	{
		cout<<"Empty\n";
		return;
	}
	node *cur = header;
	while(cur->next != header)
	{
		cur = cur->next;
		cout<<cur->coef<<"*x^"<<cur->exp;
		if(cur->next != header)
			cout<<"+";
	}
}
node* node::build()
{
	int deg, coef;
	node *header = set_header();
	cout<<"Enter degree of polynomial\n";
	cin>>deg;
	for(int exp = deg; exp >= 0; exp--)
	{
		cout<<"Enter coefficient for degree "<<exp<<endl;
		cin>>coef;
		if(coef != 0)
			header = insert(header, coef, exp);
	}
	cout<<"Polynomial: ";
	display(header);
	cout<<endl;
	return header;
}
int main()
{
	node obj;
	node *h1 = obj.build();
	node *h2 = obj.build();
	node *h3 = obj.add(h1, h2);
	cout<<"Result: ";
	obj.display(h3);
	return 0;
}