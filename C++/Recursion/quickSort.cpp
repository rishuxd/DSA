#include <iostream>
using namespace std;

int partition(int *arr, int s, int e)
{

    int pivot = arr[s];

    int c = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            c++;
        }
    }
    // place pivot at right position
    int pivotIndex = s + c;
    swap(arr[pivotIndex], arr[s]);

    int i = s;
    int j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (j > pivotIndex && i < pivotIndex)
        {
            swap(arr[i++], arr[j++]);
        }
    }
    return pivotIndex;
}
void quickSort(int *arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }
    // doing partition
    int p = partition(arr, s, e);
    // recursive call
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}