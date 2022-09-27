#include <stack>
#include <iostream>
#include <vector>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() >= curr)
        {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {2,1,4,3};
    for (int i = 0; i < 4; i++)
    {
        cout << nextSmallerElement(arr, 4)[i] <<" ";
    }
    return 0;
}
