#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(string &s1, string &s2)
{
    if (s1.size() != s2.size() + 1)
        return false;
    int first = 0;
    int second = 0;

    while (first < s1.size())
    {
        if (second < s2.size() and s1[first] == s2[second])
        {
            first++;
            second++;
        }
        else
        {
            first++;
        }
    }
    if (first == s1.size() and second == s2.size())
        return true;
    return false;
}

bool comp(string &s1, string &s2) { return s1.size() < s2.size(); }
int timeOptimizedAndPrint(vector<string> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end(), comp);

    vector<int> dp(n, 1);
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (compare(nums[i], nums[j]))
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}

int main()
{

    vector<string> words = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
    cout << timeOptimizedAndPrint(words) << endl;
    return 0;
}