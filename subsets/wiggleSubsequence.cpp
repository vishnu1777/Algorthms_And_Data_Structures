#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

// int func(int idx, bool positive, vector<int> &nums, vector<vector<int>> &dp)
// {
//     if (idx == 0)
//         return 1;

//     if (dp[idx][positive] != -1)
//         return dp[idx][positive];
//     int notTake= func(idx - 1, positive, nums, dp);
//     int take =0;
//     if (nums[idx] - nums[idx - 1] > 0 and positive || nums[idx] - nums[idx - 1] < 0 and !positive)
//     {
//        take =  1 + func(idx - 1, !positive, nums, dp);
//     }
//     return dp[idx][positive] = max(take,notTake);
// }
int func(int idx, bool positive, vector<int> &nums, vector<vector<int>> &dp)
{
    if (idx == nums.size())
        return 0;

    if (dp[idx][positive] != -1)
        return dp[idx][positive];
    int notTake = func(idx + 1, positive, nums, dp);
    int take = 0;
    if (nums[idx] > nums[idx + 1] and positive || nums[idx] < nums[idx + 1] and !positive)
    {
        take = 1 + func(idx + 1, !positive, nums, dp);
    }
    return dp[idx][positive] = max(take, notTake);
}
int wiggleSequenceMemo(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return 1;

    vector<vector<int>> dp(n, vector<int>(2, -1));
    //     // if 1 7 2 9 4 5
    //     //  5-4 = 1 then order is in 4 5 increasing order so we have to find next element which is bigger than 4
    //     // return (nums[n - 1] - nums[n - 2] > 0) ? func(n - 1, true, nums) : func(n - 1, false, nums);
    // return max(func(n - 1, 1, nums, dp), func(n - 1, 0, nums, dp));
    return 1 + max(func(0, 1, nums, dp), func(0, 0, nums, dp));
}
int wiggleSequenceTab(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return 1;

    vector<vector<int>> dp(n + 1, vector<int>(2));

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int increasing = 0;
            int decreasing = 0;
            if (nums[i] > nums[j])
            {
                increasing = max(dp[i][0], dp[j][1] + 1);
            }
            else if (nums[i] < nums[j])
            {
                decreasing = max(dp[i][1], dp[j][0] + 1);
            }
            dp[i][0] = increasing;
            dp[i][1] = decreasing;
        }
    }

    return 1 + max(dp[n - 1][0], dp[n - 1][1]);
}
int wiggle(vector<int> &nums)
{

    int n = nums.size();
    int increasing = 1;
    int decreasing = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[i - 1])
        {
            increasing = decreasing + 1;
        }
        else if (nums[i] < nums[i - 1])
        {
            decreasing = increasing + 1;
        }
    }
    return max(increasing, decreasing);
}
int main()
{

    vector<int> nums = {1, 7, 4, 9, 2, 5};
    int len = wiggleSequenceMemo(nums);
    cout << "the max len is :" << len << endl;

    len = wiggleSequenceTab(nums);
    cout << "the max in tabulation form is:" << len << endl;
    len = wiggle(nums);
    cout << "tries sequence lengthP:" << len << endl;
    return 0;
}