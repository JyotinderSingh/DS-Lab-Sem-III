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
	node* insert(node *h, int co, int ex);
	node* multiply(node *h1, node *h2);
	node* simplify(node *h);	
	void display(node *h);
	node* build();
};
node* node::set_header()
{
	node *header = new node();
	header->coef = header->exp = 0;
	header->next = header->prev = header;
	return header;
}
node* node::insert(node *h, int co, int ex)
{
	node *temp = new node();
	node *cur = h;
	temp->coef = co;
	temp->exp = ex;
	temp->next = temp->prev = temp;
	if(h->next == h)
	{
		h->next = temp;
		temp->prev = h;
		temp->next = h;
		h->prev = temp;
		return h;
	}
	while(cur->next != h)
		cur  =cur->next;
	h->prev = temp;
	temp->prev = cur;
	temp->next = h;
	cur->next = temp;
	return h;
}
node* node::multiply(node *h1, node *h2)
{
	node *h3 = set_header();
	node *a = h1->next;
	node *b = h2->next;
	if(h1->next == NULL || h2->next == NULL)
	{
		cout<<"Impossible\n";
		return NULL;
	}
	while(a != h1)
	{
		while(b != h2)
		{
			h3 = insert(h3, a->coef * b->coef, a->exp + b->exp);
			b = b->next;	
		}
		b = h2->next;
		a = a->next;
	}
	node *simplified = simplify(h3);
	return simplified;
}
node* node::simplify(node *h1)
{
	node *h2 = set_header();
	node *cur1 = h1->next;
	node *cur2 = h1->next;
	while(cur1 != h1)
	{
		while(cur2 != h1)
		{
			node *temp = cur2->next;
			if(cur1 != cur2 && cur1->exp == cur2->exp)
			{
				cur1->coef = cur1->coef + cur2->coef;
				(cur2->prev)->next = cur2->next;
				(cur2->next)->prev = cur2->prev;
				delete(cur2);
			}
			cur2 = temp;
		}
		cur2 = h1->next;
		cur1 = cur1->next;
	}
	cur1 = h1->next;
	while(cur1 != h1)
	{
		if(cur1->coef != 0)
			h2 = insert(h2, cur1->coef, cur1->exp);
		cur1 = cur1->next;
	}
	return h2;
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
	cout<<"Build list 1\n";
	node *h1 = obj.build();
	cout<<"Build list 2\n";
	node *h2 = obj.build();
	node *h3 = obj.multiply(h1, h2);
	cout<<"Result\n";
	obj.display(h3);
	return 0;
}













































// #include<iostream>

// using namespace std;
// class node
// {
// 	int exp;
// 	int coe;
// 	node *next;

//     public:
// 	node *create(node *,int,int);
// 	void display(node *);
// 	node *add(node *,node *);
// 	node *mul(node *,node *);
// 	node *sortin(node *);
// };
// node *first1=NULL,*first2=NULL,*first3=NULL,*first4=NULL,*first6=NULL;

// node * node::mul(node *f1,node *f2)
// {
// 	node *res=NULL;
// 	for(node *i=f1;i!=NULL;i=i->next)
// 		for(node *j=f2;j!=NULL;j=j->next)
// 			res=create(res,i->coe*j->coe,i->exp+j->exp);
// 	return(res);
// }



// node * node::create(node *f,int c,int e)
// {
// 		node *temp;
// 	temp=new node;

// 	temp->coe=c;
// 	temp->exp=e;
// 	temp->next=NULL;

// 	if(f==NULL)	f=temp;
// 	else
// 	{
// 		   node *curr;
// 		   for(curr=f;curr->next!=NULL;curr=curr->next);
// 		   curr->next=temp;
// 	}
// 	return(f);
//  }
// node* node::sortin(node *f)
// {
//     int max=0;
//     node *curr;
//     for (curr=f;curr;curr=curr->next)
//         {if (curr->exp>max)
//         max=curr->exp;}
//     int n=max;
//     int arr[n];node *res=NULL; node a;
//     for (int i=0;i<n+1;i++)
//     {
//         arr[i]=0;
//     }
//     for (curr=f;curr!=NULL;curr=curr->next)
//     {
//         arr[curr->exp]=arr[curr->exp]+curr->coe;
//     }

//     for(int i=0;i<n+1;i++)
// 	{
// 		res=a.create(res,arr[i],i);
// 	}
//     return (res);
// }
//     void node::display(node *f)
//     {

// 	for(node *curr=f;curr!=NULL;curr=curr->next)
// 	{
// 	    cout<<curr->coe<<"x^"<<curr->exp;
// 	    if(curr->next!=NULL)
// 	      cout<<"+";
// 	}
// 	cout<<"\n";
//     }

// node* node::add(node *f1,node *f2)
// {
// 	node *res=NULL;
// 	node *a=f1,*b=f2;

// 	while((a!=NULL)&&(b!=NULL))
// 	{
// 		if (a->exp>b->exp)
// 		{
// 			res=create(res,a->coe,a->exp);
// 			a=a->next;
// 		}
// 		else if(a->exp==b->exp)
// 		{
// 			res=create(res,a->coe+b->coe,a->exp);
// 			a=a->next;
// 			b=b->next;
// 		}
// 		else //b->exp<a->exp
// 		{
// 			res=create(res,b->coe,b->exp);
// 			b=b->next;
// 		}
// 	}
// 	while(a!=NULL)
// 	{
// 		res=create(res,a->coe,a->exp);
// 		a=a->next;
// 	}
// 	while(b!=NULL)
// 	{
// 		res=create(res,b->coe,b->exp);
// 		b=b->next;
// 	}
// 	return(res);
// }

// int main()
// {
// 	int n,i,e,c;
// 	node a;

// 	cout<<"how many terms in 1 polynomial\n";
// 	cin>>n;
// 	for(i=0;i<n;i++)
// 	{
// 		cout<<"\nEnter coe: ";
// 		cin>>c;
// 		cout<<"Enter exp: ";	cin>>e;
// 		first1=a.create(first1,c,e);
// 	}
// 	a.display(first1);

// 	cout<<"how many terms in 2 polynomial\n";
// 	cin>>n;

// 	for(i=0;i<n;i++)
// 	{
// 		cout<<"\nEnter coe: ";
// 		cin>>c;
// 		cout<<"Enter exp: ";	cin>>e;
// 		first2=a.create(first2,c,e);
// 	}
// 	a.display(first2);
// 	first3=a.add(first1,first2);
// 	first4=a.mul(first1,first2);
// 	first6=a.sortin(first4);
// 	cout<<"Result of sorting"; a.display(first6);cout<<endl;
// 	cout<<"Result of addition: ";		a.display(first3);	cout<<endl;
// 	cout<<"Result of multiplication: ";	a.display(first4);	cout<<endl;
// }