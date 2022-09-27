#include <iostream>
using namespace std;

bool checkInArray(int *arr, int size, int key)
{
    if (size == 0)
        return false;

    if (key == arr[0]){
        return true;
    }
    else{
        checkInArray(arr + 1, size - 1, key);
    }
}

int main()
{
    int arr[3] = {1, 5, 1};
    int size = 3;
    int key = 5;
    cout << checkInArray(arr, size, key) << endl;
    ;
}