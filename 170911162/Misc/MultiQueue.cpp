MultiQueue.txt
#include<iostream>
#include<bits/stdc++.h>
#define Max 100
using namespace std;
class MultiQueue
{
	int q[Max], f[Max / 2], r[Max / 2], b[Max / 2];
	int nqueues;
public:
	void construct(int);
	void addq();
	int delq();
	void display();
};
void MultiQueue::construct(int n)
{
	int i;
	nqueues = n;
	for(i = 0; i < n; i++)
		f[i] = r[i] = b[i] = (Max / n) * i - 1;
	b[i] = Max - 1;
}
void MultiQueue::addq()
{
	int i, ele;
	cout<<"Select your queue\n";
	for(i = 1; i <= nqueues; i++)
		cout<<i<<endl;
	cin>>i;
	cout<<"Enter element\n";
	cin>>ele;
	if(r[i - 1] == b[i])
	{
		cout<<"Full queue\n";
		return;
	}
	q[++r[i - 1]] = ele;
}
int MultiQueue::delq()
{
	int i;
	cout<<"Select your queue\n";
	for(i = 1; i <= nqueues; i++)
		cout<<i<<endl;
	cin>>i;
	if(f[i - 1] == r[i - 1])
	{
		cout<<"Empty queue\n";
		return -999;
	}
	return q[++f[i - 1]];
}
void MultiQueue::display()
{
	int i;
	cout<<"Select your queue\n";
	for(i = 1; i <= nqueues; i++)
		cout<<i<<endl;
	cin>>i;
	if(f[i - 1] == r[i - 1])
	{
		cout<<"Empty queue\n";
		return;
	}
	for(i = f[i - 1]; i <= r[i - 1]; i++)
		cout<<q[i]<<endl;
}
int main()
{
	MultiQueue obj;
	int nqueues, c, f = 0;
	cout<<"Enter number of queues\n";
	cin>>nqueues;
	obj.construct(nqueues);
	do
	{
		cout<<"0.Exit\n1.Add\n2.Delete\n3.Display\n";
		cin>>c;
		switch(c)
		{
			case 0:
				f = 1;
				break;
			case 1:
				obj.addq();
				break;
			case 2:
				if((c = obj.delq()) != -999)
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