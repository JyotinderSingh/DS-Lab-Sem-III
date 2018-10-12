#include<iostream.h>
#include<conio.h>
#include<process.h>


void bubbleSort(int arr[],int n)
{
	int x, y, i;
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
}

int binarySearch(int arr[], int n, int ele)
{
	int start, end, mid;
	start=0;
	end=n-1;
	while(start<=end)
	{
		mid = (start+end)/2;
		if(arr[mid]==ele)
		{
			return mid+1;
		}
		else if(arr[mid]>ele)
		{
			end-=1;
		}
		else
		{
			start+=1;
		}
	}
	cout<<"\nElement not found\n";
	return 0;
	exit(0);
}

int main()
{
	int i, x, y, arr[20], n, ele;
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
	bubbleSort(arr, n);
	cout<<"Enter the element to be searched: ";
	cin>>ele;
	cout<<"\nElement was found at "<<binarySearch(arr, n, ele)
		<<" position";
	getch();
}