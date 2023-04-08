#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

bool func(int idx, vector<int> &nums, int target, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (idx == 0)
        return (nums[0] == target);
    if (dp[idx][target] != -1)
        return dp[idx][target];
    bool notTake = func(idx - 1, nums, target, dp);
    bool take = false;
    if (nums[idx] <= target)
        take = func(idx - 1, nums, target - nums[idx], dp);

    return dp[idx][target] = take or notTake;
}

bool funcTab(int target, vector<int> &nums)
{
    int n = nums.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));
    for (int i = 0; i < nums.size(); i++)
    {
        dp[i][0] = true;
    }
    if (nums[0] <= target)
        dp[0][nums[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            bool notTake = dp[i - 1][j];
            bool take = false;
            if (nums[i] <= j)
            {
                take = dp[i - 1][j - nums[i]];
            }
            dp[i][j] = take or notTake;
            cout << i << " " << j;
            if (dp[i][j])
                cout << "true";
            else
                cout << "false";
            cout << endl;
        }
        cout << endl;
    }
    return dp[n - 1][target];
}
bool funcSpace(int target, vector<int> &nums)
{
    int n = nums.size();
    vector<bool> prev(target + 1), curr(target + 1);
    prev[0] = true;
    curr[0] = true;

    prev[nums[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            bool notTake = prev[j];
            bool take = false;
            if (nums[i] <= j)
            {
                take = prev[j - nums[i]];
            }
            curr[j] = take or notTake;
        }
        prev = curr;
    }
    return prev[target];
}

bool subsetSumToK(int k, vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return func(n - 1, arr, k, dp);

    // return funcTab(k, arr);
    //     return funcSpace(k,arr);
}

int main()
{

    vector<int> nums = {1, 2, 3, 4};
    int k = 10;
    if (subsetSumToK(k, nums))
        cout << "true";
    else
        cout << "false";
    return 0;
}