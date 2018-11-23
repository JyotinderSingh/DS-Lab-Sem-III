#include<iostream>
#include<bits/stdc++.h>
#define Max 100
using namespace std;
class MultiCircularQueue
{
	int q[Max], f[Max / 2], r[Max / 2], b[Max / 2];
	int nqueues;
public:
	void construct(int);
	void addq();
	int delq();
	void display();	
};
void MultiCircularQueue::construct(int n)
{
	int i;
	nqueues = n;
	for(i = 0; i < n; i++)
		f[i] = r[i] = b[i] = (Max / n) * i - 1;
	b[i] = Max - 1;
}
void MultiCircularQueue::addq()
{
	int i, ele;
	cout<<"Select your queue\n";
	for(i = 1; i <= nqueues; i++)
		cout<<i<<endl;
	cin>>i;
	cout<<"Enter element\n";
	cin>>ele;
	if((f[i - 1] == b[i - 1] + 1 && r[i - 1] == b[i]) || (r[i - 1] == (f[i - 1] - 1) % b[i]))
	{
		cout<<"Full queue\n";
		return;
	}
	else if(f[i - 1] == b[i - 1])
	{
		f[i - 1] = r[i - 1] = b[i - 1] + 1;
		q[r[i - 1]] = ele;
	}
	else if(r[i - 1] == b[i] && f[i - 1] != b[i - 1] + 1)
	{
		r[i - 1] = b[i - 1] + 1;
		q[r[i - 1]] = ele;
	}
	else
		q[++r[i - 1]] = ele;
}
int MultiCircularQueue::delq()
{
	int i;
	cout<<"Select your queue\n";
	for(i = 1; i <= nqueues; i++)
		cout<<i<<endl;
	cin>>i;
	if(f[i - 1] == b[i - 1])
	{
		cout<<"Empty queue\n";
		return -999;
	}
	int ret = q[f[i - 1]];
	if(f[i - 1] == r[i - 1])
		f[i - 1] = r[i - 1] = b[i - 1];
	else if(f[i - 1] == b[i])
		f[i - 1] = b[i - 1] + 1;
	else 
		f[i - 1]++;
	return ret;
}
void MultiCircularQueue::display()
{
	int i;
	cout<<"Select your queue\n";
	for(i = 1; i <= nqueues; i++)
		cout<<i<<endl;
	cin>>i;
	if(f[i - 1] == b[i - 1])
	{
		cout<<"Empty queue\n";
		return;
	}
	if(r[i - 1] >= f[i - 1])
	{
		for(int k = f[i - 1]; k <= r[i - 1]; k++)
			cout<<q[k]<<endl;
	}
	else
	{
		for(int k = f[i - 1]; k < b[i] + 1; k++)
			cout<<q[k]<<endl;
		for(int j = b[i - 1] + 1; j <= r[i - 1]; j++)
			cout<<q[j]<<endl;
	}
}
int main()
{
	int nqueues, c, f = 0;
	MultiCircularQueue obj;
	cout<<"Enter the number of queues\n";
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