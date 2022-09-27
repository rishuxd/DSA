#include <iostream>
using namespace std;

void sayDigit(string *arr, int n){
    if (n==0){
        return;
    }
    int digit = n%10;
    n=n/10;
    sayDigit(arr, n);
    cout << arr[digit] << endl;
}

int main(){
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int n;
    cin>>n;
    sayDigit(arr, n);
}