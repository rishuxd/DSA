#include <stack>
#include <iostream>
#include <vector>
using namespace std;

vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
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
    vector<int> arr = {5, 7, 4, 9, 8, 10};
    // Output: [-1, 5, -1, 4, 4, 8]
    for (int i = 0; i < 6; i++)
    {
        cout << prevSmallerElement(arr, 6)[i] << " ";
    }
    return 0;
}