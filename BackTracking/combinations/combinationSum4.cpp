// Given an array of distinct integers nums and a target integer target,
//  return the number of possible combinations that add up to target.

// The test cases are generated so that the answer can fit in a 32-bit integer.

// Input: nums = [1,2,3], target = 4
// Output: 7
// Explanation:
// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
// Note that different sequences are counted as different combinations.
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int func(int idx, vector<int> &nums, int tar, vector<vector<int>> &dp)
{

    if (tar == 0)
    {
        return 1;
    }

    if (dp[idx][tar] != -1)
        return dp[idx][tar];
    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] <= tar)
        {

            ans += func(i, nums, tar - nums[i], dp); // here i is not changing because we have to get the combination of duplicate sum also
        }
    }

    return dp[idx][tar] = ans;
}
int combinationTab(vector<int> &nums, int tar)
{
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= tar; i++)
    {
        int ans = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] <= i)
            {
                ans += dp[i - nums[j]];
            }
        }
        dp[i] = ans;
    }
    return dp[tar];
}




int combination(vector<int> &nums, int tar)
{
    // vector<int> dp(tar + 1, -1);
    vector<vector<int>> dp(nums.size(), vector<int>(tar + 1, -1));

    // int ans = func(0, nums, tar, dp);
    int ans = combinationTab(nums, tar);

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    int tar;
    cout << "enter the target val:" << endl;
    cin >> tar;

    int ans = combination(nums, tar);

    cout << "number of possible combinations that add up to target is:" << ans << endl;
    return 0;
}