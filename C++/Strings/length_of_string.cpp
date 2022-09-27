#include <iostream>
using namespace std;

int getlength(char name[]){
    int c = 0;
    int i = 0;
    while (name[i] != '\0')
    {
        c++;
        i++;
    }
    return c;
}

int main()
{
    char name[10];
    cout << "Enter your name : ";
    cin >> name;
    int c = 0;
    int i = 0;
    while(name[i] != '\0'){
        c++;
        i++;
    }
    cout<<getlength(name)<<endl;
}