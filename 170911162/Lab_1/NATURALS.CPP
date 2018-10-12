#include<iostream.h>
#include<conio.h>

int main()
{
	clrscr();
	int n;
	cout<<"Enter any natural number: ";
	cin>>n;
	long sum=(n*(n+1))/2;
	cout<<"Sum of "<<n<<" numbers is "<<sum;
	getch();
	return 0;
}