#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int x)
{
    // Base case
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call
    insertAtBottom(s, x);

    s.push(num);
}

int main()
{
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(6);
    s.push(5);

    int size = s.size();

    insertAtBottom(s, 9);

    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}