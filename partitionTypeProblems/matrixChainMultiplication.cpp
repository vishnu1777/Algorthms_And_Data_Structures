#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int func(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        int steps = nums[i - 1] * nums[k] * nums[j] + func(i, k, nums, dp) + func(k + 1, j, nums, dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}
int tabulation(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;

    for (int i = n - 1; i >= 1; i--)
    {

        for (int j = i + 1; j < n; j++)
        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int steps = nums[i - 1] * nums[k] * nums[j] + dp[i][k] + dp[k + 1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n - 1];
}
int getVal(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // return func(1, n - 1, nums, dp);
    return tabulation(nums);
}

int main()
{
    vector<int> nums = {10, 15, 20, 25};
    cout << getVal(nums) << endl;
    return 0;
}