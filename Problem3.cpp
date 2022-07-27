#include <iostream>
using namespace std;

int merge(int arr[], int const begin, int const mid, int const end)
{
    int i = begin, j = mid, k = begin;
    int Inversions = 0;
    int temp[end + 1];
    while ((i <= mid - 1) && (j <= end))
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            Inversions = Inversions + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= end)
        temp[k++] = arr[j++];

    for (i = begin; i <= end; i++)
        arr[i] = temp[i];
    return Inversions;
}
int mergeSort(int arr[], int begin, int end)
{
    int mid, Inversions = 0;
    if (begin >= end)
        return 0;

    mid =begin+ (end - begin) / 2;
    Inversions += mergeSort(arr, begin, mid);
    Inversions += mergeSort(arr, mid + 1, end);
    Inversions += merge(arr, begin, mid + 1, end);

    return Inversions;
}
int main()
{
    int Array[] = {3,2,1,4};
    int sizeArray = sizeof(Array) / sizeof(Array[0]);
    int inversions = mergeSort(Array, 0, sizeArray - 1);
    cout << " Inversions is = " << inversions;
    return 0;
}
