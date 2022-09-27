#include<iostream>
using namespace std;

void reachHome(int& src, int& des){
    if(src = des){
        return;
    }
    src++;
    reachHome(src, des);
}

int main(){
    int src = 1;
    int des = 10;

    reachHome(src, des);

    cout<<src<<endl;
}