#include<iostream.h>
#include<conio.h>

int main()
{
	int i, x, y, arr[20], n, ele, flag=0,pos;
	clrscr();
	cout<<"Enter the size of the array: ";
	cin>>n;
	for(i=0; i<n; ++i)
	{
		cin>>arr[i];
	}
	
	cout<<"Enter the element to be searched: ";
	cin>>ele;
	for(i=0; i<n; ++i)
	{
		if(arr[i] == ele)
		{
			flag=1;
			pos=i+1;
		}
	}
	if(flag)
	{
	cout<<"\nElement was found at "<<pos<<" position";
	}
	else
	{
		cout<<"\nNot Found";
	}

	getch();
}