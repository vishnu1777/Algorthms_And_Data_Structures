#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool func(int i, int j, string s1, string s2, vector<vector<int>> &dp)
{
    if (i < 0 and j < 0)
        return true;

    if (i < 0 and j >= 0)
        return false;
    if (j < 0 and i >= 0)
    {
        for (int idx = 0; idx <= i; idx++)
            if (s1[idx] != '*')
                return false;
        return true;
    }
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j] || s1[i] == '?')
    {
        return dp[i][j] = func(i - 1, j - 1, s1, s2, dp);
    }
    if (s1[i] == '*')
    {
        return dp[i][j] = func(i - 1, j, s1, s2, dp) || func(i, j - 1, s1, s2, dp);
    }
    return dp[i][j] = false;
}

void tabulation(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
    dp[0][0] = true;
    for (int j = 1; j <= m; j++)
        dp[0][j] = false;
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int idx = 1; idx <= i; idx++)
        {
            if (s1[idx - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[i][0] = flag;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (s1[i - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else
                dp[i][j] = false;
        }
    }
    if (dp[n][m])
        cout << "string is matched in tabulation" << endl;
    else
        cout << "strings are not matching in tabulation" << endl;
}
void spaceOptimized(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<bool> prev(m + 1), curr(m + 1);
    prev[0] = true;
    for (int j = 1; j <= m; j++)
        prev[j] = false;

    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int idx = 1; idx <= i; idx++)
        {

            if (s1[idx - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        curr[0] = flag;
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
            {
                curr[j] = prev[j - 1];
            }
            else if (s1[i - 1] == '*')
            {
                curr[j] = prev[j] || curr[j - 1];
            }
            else
                curr[j] = false;
        }
        prev = curr;
    }
    if (prev[m])
        cout << "string is matched in tabulation space optmized" << endl;
    else
        cout << "strings are not matching in tabulation optimized" << endl;
}

void match(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    if (func(n - 1, m - 1, s1, s2, dp))
        cout << "strings are matching" << endl;
    else
        cout << "string are not matching" << endl;
}

int main()
{
    string s1 = "*";
    string s2 = "abc";
    match(s1, s2);
    tabulation(s1, s2);
    spaceOptimized(s1,s2);
    return 0;
}