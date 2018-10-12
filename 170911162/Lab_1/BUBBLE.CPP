#include<iostream.h>
#include<conio.h>

int main()
{
	int i, x, y, arr[20], n;
	clrscr();
	cout<<"Enter the size of the array: ";
	cin>>n;
	for(i=0; i<n; ++i)
	{
		cin>>arr[i];
	}
	cout<<"\nThe array is:\n";
	for(i=0; i<n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	for(x=0; x<n; ++x)
	{
		for(y=0; y<n-1-x; ++y)
		{
			if(arr[y]>arr[y+1])
			{
				int temp = arr[y];
				arr[y] = arr[y+1];
				arr[y+1] = temp;
			}
		}
	}
	cout<<"\n\nSorted array is:\n";
	for(i=0; i<n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	getch();
	return 0;
}