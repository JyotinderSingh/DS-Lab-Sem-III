#include<iostream.h>
#include<conio.h>

int main()
{
	int arr[20], n, pos, ele, i;
	clrscr();
	cout<<"Enter the number of elements in the array: ";
	cin>>n;
	for(i =0; i<n; ++i)
	{
		cin>>arr[i];
	}
	cout<<"The array is:\n";
	for(i=0; i<n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\nEnter the postion at which the element is to be entered: ";
	cin>>pos;
	cout<<"\nEnter the element to be inserted: ";
	cin>>ele;
	for(i=n; i>pos-1; --i)
	{
		arr[i]=arr[i-1];
	}
	arr[pos-1]=ele;
	n++;
	cout<<endl;
	for(i=0; i<n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	getch();
	return 0;



}
