#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int min(int a, int b)
{
    if (a <= b)
        return a;
    else
        return b;
}

int func(int idx, vector<int> &nums, int k, int n, vector<int> &dp)
{
    if (idx == nums.size())
        return 0;
    if (dp[idx] != -1)
        return dp[idx];
    int len = 0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;
    int tillLast = min(idx + k, nums.size());
    for (int j = idx; j < tillLast; j++)
    {
        len++;
        maxi = max(maxi, nums[j]);
        int sum = len * maxi + func(j + 1, nums, k, n, dp);
        maxAns = max(maxAns, sum);
    }
    return dp[idx] = maxAns;
}

int maxSum(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n, -1);
    return func(0, arr, k, n, dp);
}

int main()
{

    vector<int> nums = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    cout << maxSum(nums, k) << endl;
    return 0;
}