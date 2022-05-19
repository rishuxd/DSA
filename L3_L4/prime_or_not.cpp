#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "Enter ur number : ";
    cin >> a;
    int b = 2;
    for (b; b < a; b++)
    {
        if (a % b == 0)
        {
            cout << "Not Prime";
            break;
        }
    }
    if (b == a)
    {
        cout << "Prime";
    }
    return 0;
}
