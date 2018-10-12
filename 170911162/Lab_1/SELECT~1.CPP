#include <iostream.h>
#include<conio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_index;

    for (i = 0; i < n-1; i++)
    {
	min_index = i;
	for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_index])
		min_index = j;
	swap(&arr[min_index], &arr[i]);
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
	selectionSort(arr, n);
	cout<<"\nSorted array: \n";
	printArray(arr, n);
	getch();
	return 0;
}