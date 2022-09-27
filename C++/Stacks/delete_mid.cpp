#include <iostream>
#include <stack>
using namespace std;


void solve(stack<int> &inputStack, int count, int size)
{
    // Base case
    if (size / 2 == count)
    {
        inputStack.pop();
        return;
    }
    int num = inputStack.top();
    inputStack.pop();

    // recursive call
    solve(inputStack, count + 1, size);

    inputStack.push(num);
}

void deleteMiddle(stack<int> &inputStack, int N)
{
    int count = 0;
    solve(inputStack, count, N);
}

int main()
{
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(6);
    s.push(5);
    int size = s.size();
    deleteMiddle(s, 4);
    for (int i = 0; i < size; i++)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    
    return 0;
}