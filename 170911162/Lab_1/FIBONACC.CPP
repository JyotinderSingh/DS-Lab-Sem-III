#include<iostream.h>
#include<conio.h>

int main()
{
	clrscr();
	int first=0, second=1, sum, n;
	cout<<"Enter the limit: ";
	cin>>n;
	cout<<first<<" "<<second<<" ";
	for(int i=2; i<=n;++i)
	{
		sum=first+second;
		cout<<sum<<" ";
		first=second;
		second=sum;
	}
	getch();
	return 0;
}