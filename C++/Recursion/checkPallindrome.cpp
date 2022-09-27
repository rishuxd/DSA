#include <iostream>
using namespace std;

bool checkPallindrome(string& str, int i, int j)
{
    if (i > j)
        return true;
    if (str[i] != str[j])
    {
        return false;
    }
    i++;
    j--;
    checkPallindrome(str, i, j);
}

int main()
{
    string s = "babbar";
    cout<<checkPallindrome(s, 0, s.length() - 1)<<endl;
    return 0;
}
