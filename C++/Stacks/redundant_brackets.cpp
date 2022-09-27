#include <iostream>
#include <stack>
using namespace std;

bool isRedundant(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                bool ans = true;
                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        ans = false;
                    }
                    st.pop();
                }
                if (ans == true)
                {
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}

int main()
{
    string s = "((a+b))";

    if (isRedundant(s)){
        cout<<"String is redundant."<<endl;
    }
    else{
        cout<<"String is valid."<<endl;
    }
        return 0;
}