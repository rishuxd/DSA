// checking a string a PALLINDROME or NOT

#include <iostream>
using namespace std;

char tolowercase(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
bool checkPalindrome(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
    {
        if (tolowercase(s[i]) == tolowercase(s[j]))
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    if (i == j)
    {
        return true;
    }
}

int main()
{
    string s = "Noon";
    cout<<checkPalindrome(s)<<endl;
    cout<<tolowercase('A')<<endl;

    
}