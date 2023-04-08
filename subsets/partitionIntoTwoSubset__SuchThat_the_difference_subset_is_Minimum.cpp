#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int funcTab(vector<int> &nums)
{
    int n = nums.size();
    int totalSum = 0;
    for (int i = 0; i < nums.size(); i++)
        totalSum += nums[i];
    // Write your code here.
    vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, 0));

    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (nums[0] <= totalSum)
        dp[0][nums[0]] = true;

    for (int i = 1; i < n; i++)
    {

        for (int target = 1; target <= totalSum; target++)
        {
            bool notTake = dp[i - 1][target];
            bool take = false;
            if (nums[i] <= target)
                take = dp[i - 1][target - nums[i]];
            dp[i][target] = take | notTake;
        }
    }

    for (vector<bool> n : dp)
    {
        for (bool a : n)
        {
            cout << a << " ";
        }
        cout << endl;
    }

    int mini = 1e8;
    for (int target = 0; target <= totalSum / 2; target++)
    {
        if (dp[n - 1][target])
            mini = min(mini, abs((totalSum - target) - target));
    }
    return mini;
}

int main()
{

    vector<int> nums = {8, 7, 5};
    int ans = funcTab(nums);
    cout << "the minimum difference is:" << ans << endl;
    cout << endl;

    return 0;
}