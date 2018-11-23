#include<iostream>
#include<bits/stdc++.h>
#define Max 100
using namespace std;
class SPM
{
	int r, c, v;
public:
	void construct(SPM []);
	void display(SPM []);
	void transpose(SPM [], SPM []);
	void fasttranspose(SPM [], SPM []);
};
void SPM::construct(SPM a[])
{
	int k = 1, val, row, col;
	cout<<"Enter the dimensions of the matrix\n";
	cin>>row;
	cin>>col;
	cout<<"Enter the elements of the matrix\n";
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cin>>val;
			if(val == 0)
				continue;
			a[k].r = i;
			a[k].c = j;
			a[k++].v = val;
		}
	}
	a[0].r = row;
	a[0].c = col;
	a[0].v = k - 1;
}
void SPM::display(SPM a[])
{
	cout<<"SPM:\n";
	for(int i = 0; i <= a[0].v; i++)
		cout<<i <<"\t"<<a[i].r<<"\t"<<a[i].c<<"\t"<<a[i].v<<endl;
}
void SPM::transpose(SPM a[], SPM b[])
{
	b[0].r = a[0].c;
	b[0].c = a[0].r;
	b[0].v = a[0].v;
	int k = 1;
	for(int i = 0; i < a[0].c; i++)
	{
		for(int j = 1; j <= a[0].v; j++)
		{
			if(a[j].c == i)
			{
				b[k].r = a[j].c;
				b[k].c = a[j].r;
				b[k++].v = a[j].v;
			}
		}
	}
}
void SPM::fasttranspose(SPM a[], SPM b[])
{
	int rT[a[0].c], sp[a[0].c], j;
	sp[0] = 1;
	for(int i = 0; i < a[0].c; i++)
		rT[i] = 0;
	for(int i = 1; i < a[0].v; i++)
		rT[a[i].c]++;
	for(int i = 1; i < a[0].c; i++)
		sp[i] = rT[i - 1] + sp[i - 1];
	for(int i = 1; i < a[0].v; i++)
	{
		j = sp[a[i].c]++;
		b[j].r = a[i].c;
		b[j].c = a[i].r;
		b[j].v = a[i].v;
	}
}
int main()
{
	SPM a[100], b[100], c[100], obj;
	obj.construct(a);
	obj.display(a);
	obj.transpose(a, b);
	obj.display(b);
	obj.fasttranspose(b, a);
	obj.display(a);
	return 0;
}