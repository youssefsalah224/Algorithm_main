#include <bits/stdc++.h>
using namespace std;
int insertionSort(int arr[], int n)
{
    int counter=0;
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
            counter++;
		}
		arr[j + 1] = key;
	}
    return counter;
}
int main()
{
	int arr[] = { 2,1,3,1,2,0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout<<insertionSort(arr, n);
	return 0;
}
