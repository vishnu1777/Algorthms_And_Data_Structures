#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int func(int idx, vector<int> &nums, int tar)
{
    if (idx == 0)
    {
        if (tar == 0 and nums[0] == 0)
            return 2;
        if (tar == 0 || nums[0] == tar)
            return 1;
        else
            return 0;
    }
    int notPick = func(idx - 1, nums, tar);
    int pick = 0;
    if (nums[idx] <= tar)
        pick = func(idx - 1, nums, tar - nums[idx]);

    return pick + notPick;
}
int funcTab(vector<int> &nums, int tar)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1));

    if (nums[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if (nums[0] != 0 and nums[0] <= tar)
        dp[0][nums[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target <= tar; target++)
        {
            int notPick = dp[i - 1][target];
            int pick = 0;
            if (nums[i] <= target)
                pick = dp[i - 1][target - nums[i]];
            dp[i][target] = pick + notPick;
        }
    }
    return dp[n - 1][tar];
}
int funcTabSpace(vector<int> &nums, int tar)
{
    int n = nums.size();
    vector<int> prev(tar + 1), curr(tar + 1);

    if (nums[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;

    if (nums[0] != 0 and nums[0] <= tar)
        prev[nums[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target <= tar; target++)
        {
            int notPick = prev[target];
            int pick = 0;
            if (nums[i] <= target)
                pick = prev[target - nums[i]];
            curr[target] = pick + notPick;
        }
        prev = curr;
    }
    return prev[tar];
}

int partitionDifference(vector<int> &nums, int d)
{
    int n = nums.size();
    int totalSum = 0;
    for (int n : nums)
        totalSum += n;
    int tot = abs((totalSum - d) / 2); // we have to intitialize the absolute value because vector cannot be given the size as negative
    vector<vector<int>> dp(n, vector<int>(tot + 1, -1));

    if ((totalSum - d) < 0 || (totalSum - d) % 2 != 0)
        return 0;
    // else return func(n-1,nums,(totalSum-d)/2,dp);
    // else return funcTab5(nums,tot);
    else
        return funcTabSpace(nums, tot);
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int d = 3;
    int ans = partitionDifference(nums, d);
    cout << "ans is:" << ans << endl;
    return 0;
}