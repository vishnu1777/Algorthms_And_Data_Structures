#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int func(int i, vector<int> &nums, int tar, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (tar == 0 and nums[i] == 0)
            return 2; // if the tar == 0 and the first is also equal to tar then one case is we can pick
        // then the ways we will be 1 and we cannot pick it and ways will be 1 and final ans will be 2
        if (tar == nums[i] || tar == 0)
            return 1; // if any one condtition satisfies then only one way is possible
        else
            return 0;
    }
    if (dp[i][tar] != -1)
        return dp[i][tar];

    int notPick = func(i - 1, nums, tar, dp);
    int pick = 0;
    if (nums[i] <= tar)
    {
        pick = func(i - 1, nums, tar - nums[i], dp);
    }
    return dp[i][tar] = pick + notPick;
}
int tabulation(vector<int> &nums, int tar)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1));
    if (nums[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if (nums[0] <= tar and nums[0] != 0)
        dp[0][nums[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target <= tar; target++)
        {
            int notPick = dp[i - 1][target];
            int pick = 0;
            if (nums[i] <= target)
            {
                pick = dp[i - 1][target - nums[i]];
            }
            dp[i][target] = pick + notPick;
        }
    }
    return dp[n - 1][tar];
}
int tabSpace(vector<int> &nums, int tar)
{
    int n = nums.size();
    vector<int> prev(tar + 1), curr(tar + 1);
    if (nums[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;

    if (nums[0] <= tar and nums[0] != 0)
        prev[nums[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target <= tar; target++)
        {
            int notPick = prev[target];
            int pick = 0;
            if (nums[i] <= target)
            {
                pick = prev[target - nums[i]];
            }
            curr[target] = pick + notPick;
        }
        prev = curr;
    }
    return prev[tar];
}
int oneDSpace(vector<int> &nums, int tar)
{
    int n = nums.size();
    vector<int> prev(tar + 1);
    if (nums[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;

    if (nums[0] <= tar and nums[0] != 0)
        prev[nums[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int target = tar; target >= 0; target--)
        {
            int notPick = prev[target];
            int pick = 0;
            if (nums[i] <= target)
            {
                pick = prev[target - nums[i]];
            }
            prev[target] = pick + notPick;
        }
    }
    return prev[tar];
}
int numberOfSubset(vector<int> &nums, int tar)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    // return func(n - 1, nums, tar, dp);
    // return tabulation(nums, tar);
    // return tabSpace(nums,tar);
    return oneDSpace(nums, tar);
}

int main()
{

    vector<int> nums = {1, 2, 2, 3, 2};
    int tar = 3;
    cout << numberOfSubset(nums, tar);

    return 0;
}