#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void LDS(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> dp(n, 1);
    vector<int> hash(n);
    int maxLen = 0;
    int lastIndex = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {

            if (nums[i] % nums[j] == 0 and 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
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

    vector<int> nums = {1,2,4,9};
    LDS(nums);
    return 0;
}