#include <iostream>
using namespace std;

int sumA(int *arr, int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];

    int remaing = sumA(arr + 1, n-1);
    int ans = arr[0]+remaing;
    
    return ans;
}

int main()
{
    int arr[3]={1,5,1};
    cout << sumA(arr, 3) << endl;
    ;
}