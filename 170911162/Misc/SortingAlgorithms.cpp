#include <bits/stdc++.h>
using namespace std;


void bubbleSort(vector<int> &a) {
    for(int i = 0; i < a.size()-1; ++i) {
        for (int j = 0; j < a.size() - i - 1; ++j) {
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}


void insertionSort(vector<int> &a) {
    int i, j, key;
    for(i = 0; i < a.size(); ++i) {
        key = a[i];
        j = i-1;
        while(j>=0 && a[j]>key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}


void selectionSort(vector<int> &a) {
    int minindex;

    for (int k = 0; k < a.size() - 1; ++k) {
        minindex = k;
        for (int l = k+1; l < a.size(); ++l) {
            if(a[l] < a[minindex]) {
                minindex = l;
            }
        }
        swap(a[k], a[minindex]);
    }
}


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}


void quickSort(int a[], int low, int high) {
    int pivot, i = low-1, j = high+1, temp;
    if(low < high) {
        pivot = a[low];
        do {
            do {
                i++;
            } while (a[i] <= pivot);
            do {
                j--;
            } while (a[j] > pivot);

            if (i < j) {
                swap(a[i], a[j]);
            }
        } while (i < j);

        swap(a[j], a[low]);

        quickSort(a, low, j);
        quickSort(a, j + 1, high);
    }
}


void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if(r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if(i != largest) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for(int i = n/2 -1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    for(int i = n-1; i >=0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


int getMax(int arr[], int n) {
    int mx = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > mx) {
            mx = arr[i];
        }
    }
    return mx;
}

void countSort(int arr[], int n, int place) {
    int i, freq[10] = {0};
    int output[n];
    for(i = 0; i < n; ++i) {
        freq[(arr[i]/place)%10]++;
    }
    for(i = 1; i < 10; ++i) {
        freq[i] += freq[i-1];
    }

    for(i = n-1; i >= 0; --i) {
        output[freq[(arr[i]/place)%10] - 1] = arr[i];
        freq[(arr[i]/place)%10]--;
    }

    for(i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int maxx = getMax(arr, n);
    int mul = 1;

    while(maxx) {
        countSort(arr, n, mul);
        mul *= 10;
        maxx /= 10;
    }
}


int main() {
    int n = 7;
    vector <int> arr{45, 34, 66, 0, 23, 5, 1};

    cout<<"\nOriginal array is:\n";
    for(auto i: arr){
        cout<<i<<" ";
    }

    vector <int> a1(n), a2(n), a3(n);
    copy(arr.begin(), arr.end(), a1.begin());
    copy(arr.begin(), arr.end(), a2.begin());
    copy(arr.begin(), arr.end(), a3.begin());

    // bubbleSort(a1);
    // cout<<"\nBubble Sort:\n";
    // for(auto i: a1) {
    //     cout<<i<<" ";
    // }

    // insertionSort(a2);
    // cout<<"\nInsertion Sort:\n";
    // for(auto i: a2) {
    //     cout<<i<<" ";
    // }

    // selectionSort(a3);
    // cout<<"\nSelection Sort:\n";
    // for(auto i: a3) {
    //     cout<<i<<" ";
    // }
    int a[] = {1838, 8038, 8430, 7215, 1, 3205, 9722, 6527, 288, 520, 1748, 8682, 1644, 8622, 3825, 9728, 1254, 841, 9652, 1073, 276, 4356, 8466, 3792, 3493, 5377, 2642, 1228, 4386, 9882, 5176, 5619, 6592, 6912, 3852, 4068, 2152, 2532, 8342, 1080, 3794, 1130, 2157, 4872, 6512, 7449, 8302, 9369, 4031, 2398, 8840, 3856, 3581, 6219, 1185, 2781, 140, 6552, 4583, 7288, 4514, 1513, 299, 5920, 4003, 4020, 9231, 8295, 4796, 1511, 4310, 6733, 7958, 9118, 2096, 2758, 2426, 7400, 8148, 7680, 3656, 7244, 4047, 8256, 1057, 1415, 9019, 632, 1544, 5090, 814, 4976, 9512, 6547, 5043, 1784, 4324, 6765, 5588, 7953};
    mergeSort(a, 0, 6);
    cout<<"\nMerge Sort:\n";
    for(auto i: a) {
        cout<<i<<" ";
    }

    int b[] = {1838, 8038, 8430, 7215, 1, 3205, 9722, 6527, 288, 520, 1748, 8682, 1644, 8622, 3825, 9728, 1254, 841, 9652, 1073, 276, 4356, 8466, 3792, 3493, 5377, 2642, 1228, 4386, 9882, 5176, 5619, 6592, 6912, 3852, 4068, 2152, 2532, 8342, 1080, 3794, 1130, 2157, 4872, 6512, 7449, 8302, 9369, 4031, 2398, 8840, 3856, 3581, 6219, 1185, 2781, 140, 6552, 4583, 7288, 4514, 1513, 299, 5920, 4003, 4020, 9231, 8295, 4796, 1511, 4310, 6733, 7958, 9118, 2096, 2758, 2426, 7400, 8148, 7680, 3656, 7244, 4047, 8256, 1057, 1415, 9019, 632, 1544, 5090, 814, 4976, 9512, 6547, 5043, 1784, 4324, 6765, 5588, 7953};
    quickSort(b, 0, 6);
    cout<<"\nQuick Sort:\n";
    for(auto i: b){
        cout<<i<<" ";
    }

    int c[] = {1838, 8038, 8430, 7215, 1, 3205, 9722, 6527, 288, 520, 1748, 8682, 1644, 8622, 3825, 9728, 1254, 841, 9652, 1073, 276, 4356, 8466, 3792, 3493, 5377, 2642, 1228, 4386, 9882, 5176, 5619, 6592, 6912, 3852, 4068, 2152, 2532, 8342, 1080, 3794, 1130, 2157, 4872, 6512, 7449, 8302, 9369, 4031, 2398, 8840, 3856, 3581, 6219, 1185, 2781, 140, 6552, 4583, 7288, 4514, 1513, 299, 5920, 4003, 4020, 9231, 8295, 4796, 1511, 4310, 6733, 7958, 9118, 2096, 2758, 2426, 7400, 8148, 7680, 3656, 7244, 4047, 8256, 1057, 1415, 9019, 632, 1544, 5090, 814, 4976, 9512, 6547, 5043, 1784, 4324, 6765, 5588, 7953};
    heapSort(c, 7);
    cout<<"\nHeap Sort:\n";
    for(auto i: c) {
        cout<<i<<" ";
    }

    int d[] = {45, 34, 66, 0, 23, 5, 1};
    radixSort(d, 7);
    cout<<"\nRadix Sort:\n";
    for(auto i: d){
        cout<<i<<" ";
    }


    return 0;
}