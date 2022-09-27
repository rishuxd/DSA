#include <iostream>
using namespace std;

bool binarySearch(int *arr, int s,int e, int key)
{
    if (s>e)
        return false;

    int mid = s + (e-s)/2;

    if(arr[mid]==key)
        return true;

    if (arr[mid] < key)
    {
        return binarySearch(arr, mid+1, e, key);
    }
    else
    {
        return binarySearch(arr, s, mid-1, key);
    }
}

int main()
{
    int arr[4] = {1, 2, 3, 4};
    int s = 0;
    int e = 3;
    int key = 5;
    cout << binarySearch(arr, s, e, key) << endl;
    ;
}