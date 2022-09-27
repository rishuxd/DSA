// TC: O(n)
// SC: O(n)

#include<iostream>
#include<stack>
using namespace std;

int main(int argc, char const *argv[])
{
    string str = "rishi";
    stack<char> s;
    string ans = "";

    for (int i = 0; i < str.length(); i++)
    {
        char p = str[i];
        s.push(p);
    }

    while (!s.empty())
    {
        char a = s.top();
        ans.push_back(a);

        s.pop();
    }

    cout<<"Reversed string : "<<ans<<endl;

    return 0;
}
