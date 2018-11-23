MultiStacks.txt
#include<iostream>
#include<bits/stdc++.h>
#define Max 100
using namespace std;
class MultiStack
{
	int st[Max], t[Max / 2], b[Max / 2];
	int nstacks;
public:
	void construct(int);
	void push();
	int pop();
	void display();
};
void MultiStack::construct(int n)
{
	int i;
	nstacks = n;
	for(i = 0; i < n; i++)
		t[i] = b[i] = (Max / n) * i - 1;
	b[i] = Max - 1;
}
void MultiStack::push()
{
	int i, ele;
	cout<<"Select your stack\n";
	for(i = 1; i <= nstacks; i++)
		cout<<i<<endl;
	cin>>i;
	cout<<"Enter element\n";
	cin>>ele;
	if(t[i - 1] == b[i])
	{
		cout<<"Full stack\n";
		return;
	}
	st[++t[i - 1]] = ele;
}
int MultiStack::pop()
{
	int i;
	cout<<"Select your stack\n";
	for(i = 1; i <= nstacks; i++)
		cout<<i<<endl;
	cin>>i;
	if(t[i - 1] == b[i - 1])
	{
		cout<<"Empty stack\n";
		return -999;
	}
	return st[t[i - 1]--];
}
void MultiStack::display()
{
	int i, k;
	cout<<"Select your stack\n";
	for(i = 1; i <= nstacks; i++)
		cout<<i<<endl;
	cin>>i;
	if(t[i - 1] == b[i - 1])
	{
		cout<<"Empty stack\n";
		return;
	}
	for(k = b[i - 1] + 1; k <= t[i - 1]; k++)
		cout<<st[k]<<endl;
}
int main()
{
	MultiStack obj;
	int nstacks, c, f = 0;
	cout<<"Enter number of stacks\n";
	cin>>nstacks;
	obj.construct(nstacks);
	do
	{
		cout<<"0.Exit\n1.Push\n2.Pop\n3.Display\n";
		cin>>c;
		switch(c)
		{
			case 0:
				f = 1;
				break;
			case 1:
				obj.push();
				break;
			case 2:
				if((c = obj.pop()) != -999)
					cout<<c<<endl;
				break;
			case 3:
				obj.display();
		}
		if(f == 1)
			break;
	}
	while(true);
	return 0;
}