#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int arr[2000];

int comp(int left, int right)
{
    if (left >= right)
        return 0;

    
   int x = min_element(arr + left, arr + right) - arr;
    
   int mini = arr[x];

    for (int i = left; i <= right; i++)                                      


    {

        arr[i] = arr[i] - mini;                                           // remove the occurrence
    }

    return min(right - left, comp(left, x) + comp(x + 1, right) + mini);
}
int main()
{
    int number;
    cout<<"Enter number of samples ?"<<endl;
    cin >> number;
    cout<<"Enter samples using spaces?"<<endl;
    for (int i = 0; i < number; i++)
    {
        cin >> arr[i];
    }
    cout <<"Minimum number of operations required to delete all elements from the multiset  "<< comp(0, number)<<endl;
}

