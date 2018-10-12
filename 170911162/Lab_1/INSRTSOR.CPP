#include <iostream.h>
#include<conio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insertionSort(int arr[], int n)
{
	for(int i=0; i<n; ++i)
	{
		int key = arr[i];
		for(int j=i-1; j>=0; --j)
		{
			if(arr[j]>key)
			{
				arr[j+1] = arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j+1] = key;
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	int i, arr[20],n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	for (i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	printArray(arr, n);
	insertionSort(arr, n);
	cout<<"\nSorted array: \n";
	printArray(arr, n);
	getch();
	return 0;
}