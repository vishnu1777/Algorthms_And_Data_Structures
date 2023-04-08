// You are a professional robber planning to rob houses along a street.
// Each house has a certain amount of money stashed. All houses at
//  this place are arranged in a circle. That means the first house is the neighbor of the last one.
//  Meanwhile, adjacent houses have a security system connected,
//   and it will automatically contact the police
//    if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house,
// // return the maximum amount of money you can rob tonight without alerting the police
// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
// because they are adjacent houses.
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int func(int idx, int n, vector<int> &nums, vector<int> &dp)
{
    if (idx == n)
        return 0;
    if (idx == n - 1)
        return nums[idx];
    if (dp[idx] != -1)
        return dp[idx];

    int notTake = 0 + func(idx + 1, n, nums, dp);

    int take = nums[idx] + func(idx + 2, n, nums, dp);

    return dp[idx] = max(notTake, take);
}
int tabulation(vector<int> &nums, int l, int r)
{
    int prev = nums[l];
    int prev2 = 0;
    for (int i = l + 1; i < r; i++)
    {
        int curr = max(prev, nums[i] + prev2);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    // return max(func(1, n, nums,dp), func(0, n - 1, nums,dp));
    return max(tabulation(nums, 0, n - 1), tabulation(nums, 1, n));
}

int main()
{

    vector<int> nums = {1, 2, 3, 1};
    cout << rob(nums) << endl;
    return 0;
}