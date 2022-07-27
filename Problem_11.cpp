int SMaxS(int arr[], int n)               //sum of maximum subarray
{
    int x = arr[0];
    int y = 0;
    int sum;


    for (int i = 1; i < n; i++)
    {

        sum = (x > y) ? x : y;            //get subset and return sum
        x = y + arr[i];
        y = sum;
    }

    
    if(x > y)                           // return max of x and y
        return x;
    else
        return y;
}


int main()
{

    int arr[] = {3,5,-7,8,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<" sum of maximum sub array is "<<SMaxS(arr, n)<<endl<<endl;
}
