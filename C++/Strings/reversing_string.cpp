// reversing string

#include<iostream>
using namespace std;

void reverse(char name[], int n){
    int s=0;
    int e=n-1;
    while (s<e)
    {
        swap(name[s++], name[e--]);
    }
}

int main()
{
    char name[10];
    cout << "Enter your name : ";
    cin >> name;
    reverse(name, 10);
    cout << "Here's your name : ";
    cout<< name << endl;
    return 0;
}
