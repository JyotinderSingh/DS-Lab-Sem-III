#include<iostream.h>
#include<conio.h>

int main()
{
	clrscr();
	long int fact=1;
	int n;
	cout<<"Enter a number: ";
	cin>>n;
	for(int i=2; i<=n; ++i)
	{
		fact*=i;
	}
	cout<<"\nFactorial of "<<n<<" is "<<fact;
	getch();
	return 0;
}