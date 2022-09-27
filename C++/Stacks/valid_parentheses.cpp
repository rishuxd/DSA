#include <iostream>
#include <stack>
using namespace std;



bool isValidParenthesis(string expression)
{
    stack<char> s;

    for (int i = 0; i < expression.length(); i++)
    {

        char ch = expression[i];

        // if opening, stack push
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            if (!s.empty())
            {
                if ((s.top() == '[' && ch == ']') ||
                    (s.top() == '{' && ch == '}') ||
                    (s.top() == '(' && ch == ')'))
                {
                    s.pop();
                }
                else
                    return false;
            }
            else
            {
                return false;
            }
        }
    }
    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string str = "{[]}";
    cout<<isValidParenthesis(str)<<endl;
    string str2 = "{[}";
    cout << isValidParenthesis(str2) << endl;
    return 0;
}