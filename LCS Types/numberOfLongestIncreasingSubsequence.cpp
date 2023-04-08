#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
// Given an integer array nums,
//  return the number of longest increasing subsequences.

// Notice that the sequence has to be strictly increasing
// Input: nums = [1,3,5,4,7]
// Output: 2
// Explanation: The two longest

// increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

int timeOptimizedAndPrint(vector<int> &nums)
{
    int n = nums.size();
    int maxLen = 1;
    int maxi = 0;
    vector<int> dp(n, 1), count(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j] and dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                count[i] = count[j];
            }
            else if (nums[i] > nums[j] and dp[i] == dp[j] + 1)
                count[i] += count[j];
        }
        maxLen = max(maxLen, dp[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxLen)
            maxi += count[i];
    }
    return maxi;
}

int main()
{
    vector<int> nums = {1, 3, 5, 4, 7};
    cout << timeOptimizedAndPrint(nums) << endl;

    return 0;
}