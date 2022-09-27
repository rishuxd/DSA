#include<iostream>
using namespace std;
int main(){
    char name[10];
    cout<<"Enter your name : ";
    cin>>name;
    name[2]='\0';
    cout<<"Here's your name : ";
    cout<<name<<endl;
}