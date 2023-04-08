#include <stdio.h>
#include <iostream>
#include <stack>
// #include<algorithm>
#include <vector>
using namespace std;

void nge(vector<int> &nums)
{
    stack<int> s;
    vector<int> ans(nums.size());

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!s.empty() and s.top() <= nums[i])
        {
            s.pop();
        }

        if (!s.empty())
            ans[i] = s.top();
        else
            ans[i] = -1;

        s.push(nums[i]);
    }

    for (int n : ans)
    {
        cout << n << " ";
    }
}

void ngeCircular(vector<int> &nums)
{
    // if not understood do a dry run recommended
    stack<int> s;
    int n = nums.size();
    vector<int> ans(n);
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!s.empty() and s.top() <= nums[i % n])
        {
            s.pop();
        }
        // since we just want to store elements from 0->n index
        if (i < n)
        {
            if (!s.empty())
                ans[i] = s.top();
            else
                ans[i] = -1;
        }
        s.push(nums[i % n]);
    }
    for (int n : ans)
    {
        cout << n << " ";
    }
}

int main()
{

    vector<int> nums = {1, 2, 3, 4, 3};
    nge(nums);
    cout << endl;
    ngeCircular(nums);
    return 0;
}