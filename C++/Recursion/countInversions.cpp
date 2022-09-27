#include <iostream>
using namespace std;

int count = 0;

void merge(int *arr, int s, int e)
{
    // finding mid
    int mid = s + (e - s) / 2;

    // finding length of splited arrays
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // creating new arrays
    int *first = new int[len1];
    int *second = new int[len2];

    // copying values
    int mainArrayIndex = s;

    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len1; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // merge two sorted array
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            count++;
            arr[mainArrayIndex++] = second[index2++];
        }
    }
    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }
    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}
void merSort(int *arr, int s, int e)
{
    // Base Case
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    // left part sort
    merSort(arr, s, mid);

    // right part sort
    merSort(arr, mid + 1, e);

    // merge
    merge(arr, s, e);
}
int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    merSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    cout<<"Number of Inversions : "<<count<<endl;
}