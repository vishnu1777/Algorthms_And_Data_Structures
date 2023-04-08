#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int func(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = 1 + func(i - 1, j - 1, s1, s2, dp);
    return dp[i][j] = max(func(i - 1, j, s1, s2, dp), func(i, j - 1, s1, s2, dp));
}
int tabulation(string &s1, string &s2)
{
    int n = s1.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}
int tabSpace(string &s1, string &s2)
{
    int n = s1.size();
    vector<int> prev(n + 1), curr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                prev[j] = 1 + prev[j - 1];
            }
            else
            {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }
    return prev[n];
}

int longestSubsequence(string &s)
{

    int n = s.size();
    string s2 = s;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    reverse(s.begin(), s.end());

    // return func(n - 1, n - 1, s2, s, dp);
    return tabulation(s2, s);
}

int main()
{

    string s = "bbbab";
    cout << longestSubsequence(s) << endl;

    return 0;
}