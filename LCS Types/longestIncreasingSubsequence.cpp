#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int func(int idx, int prev, vector<int> &nums, vector<vector<int>> &dp)
{
    cout << "index:" << idx << " prev:" << prev << endl;
    if (idx == nums.size())
        return 0;
    if (dp[idx][prev + 1] != -1)
        return dp[idx][prev + 1];

    int notTake = 0 + func(idx + 1, prev, nums, dp);
    int take = 0;
    cout << "the length if we not take is :" << notTake << endl;
    if (prev == -1 || nums[idx] > nums[prev])
    {
        if (prev == -1)
        {
            cout << "idx val inside the if:" << nums[idx] << " prev val inside loop "
                 << "-1" << endl;
        }
        else
        {
            cout << "idx val inside the if:" << nums[idx] << " prev val inside loop " << nums[prev] << endl;
        }

        take = 1 + func(idx + 1, idx, nums, dp);
        cout << "the length if we take is:" << take << endl;
    }

    cout << "the max value that is chosen is " << max(take, notTake) << endl;
    return dp[idx][prev + 1] = max(take, notTake);
}

int LISMemo(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return func(0, -1, nums, dp);
}
int LisTab(vector<int> &nums)
{
    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {
            int len = 0 + dp[i + 1][j + 1];
            if (j == -1 || nums[i] > nums[j])
            {
                len = max(len, 1 + dp[i + 1][i + 1]);
            }
            dp[i][j + 1] = len;
        }
    }

    return dp[0][0];
}
int lisSpaceOptimized(vector<int> &nums)
{
    int n = nums.size();

    vector<int> next(n + 1, 0), curr(n + 1);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {
            int len = 0 + next[j + 1];
            if (j == -1 || nums[i] > nums[j])
            {
                len = max(len, 1 + next[i + 1]);
            }
            curr[j + 1] = len;
        }
        next = curr;
    }
    return next[0]; // we can also return curr[0] at last curr and next will be same
}
int timeOptimizedAndPrint(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n, 1);
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}
void printLongestIS(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> dp(n, 1);
    int maxLen = 0;
    int lastIndex = 0;
    vector<int> hash(n);
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j] and 1 + dp[j] > dp[i])
            {
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }
        if (dp[i] > maxLen)
        {
            maxLen = dp[i];
            lastIndex = i;
        }
    }
    vector<int> temp;
    temp.push_back(nums[lastIndex]);
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        temp.push_back(nums[lastIndex]);
    }
    reverse(temp.begin(), temp.end());
    for (int n : temp)
        cout << n << " ";
    cout << endl;
}
int main()
{

    vector<int> nums = {3, 4, 16, 8};
    // int ans = LISMemo(nums);
    // cout << endl;
    // cout << "the longest increasing subsequence is:" << ans << endl;
    // ans = LisTab(nums);
    // cout << endl;
    // cout << "the longest increasing subsequence in tabulation is:" << ans << endl;
    // cout << endl;
    // ans = lisSpaceOptimized(nums);
    // cout << "the longest increasing subsequence in space optimized tabulation  is:" << ans << endl;
    // int ans = timeOptimizedAndPrint(nums);
    // cout << "the longest increasing subsequence in time optmized tabulation  is:" << ans << endl;
    printLongestIS(nums);
    return 0;
}