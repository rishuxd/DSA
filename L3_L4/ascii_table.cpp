#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char a;
    cin >> a;
    if (a > 96 && a < 173)
        cout << "Lower case" << endl;
    else if (a > 64 && a < 91)
        cout << "Upper case" << endl;
    else if (a > 47 && a < 58)
        cout << "THis is numeric." << endl;
    return 0;
}
