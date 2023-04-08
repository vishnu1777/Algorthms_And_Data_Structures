#include <stdio.h>
#include <iostream>
#include <algorithm>

#include <vector>
using namespace std;

string shortestSupresequence(string &s1, string &s2)
{
    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    int len = dp[m][n];
    cout << "the longest commons subsequence length is:" << len << endl;

    int i = m;
    int j = n;
    string s = "";
    while (i > 0 and j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            s += s1[i - 1];

            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            s += s1[i - 1];
            i--;
        }
        else
        {
            s += s2[j - 1];
            j--;
        }
    }
    while (i > 0)
    {
        s += s1[i - 1];
        i--;
    }
    while (j > 0)
    {
        s += s2[j - 1];
        j--;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main()
{

    string s1 = "abac";
    string s2 = "cab";
    cout << shortestSupresequence(s1, s2) << endl;
    return 0;
}