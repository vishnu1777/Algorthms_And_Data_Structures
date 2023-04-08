#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int func(int i, int j, string &s1, string &s2)
{
    if (i < 0 || j < 0)
        return 0;

    if (s1[i] == s2[j])
        return 1 + func(i - 1, j - 1, s1, s2);
    return max(func(i - 1, j, s1, s2), func(i, j - 1, s1, s2));
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
int minInsertion(string &s1)
{

    int n = s1.size();
    string temp = s1;
    reverse(s1.begin(), s1.end());
    // return n - func(n - 1, n - 1, temp, s1);
    return n - tabulation(temp, s1);
}

int main()
{

    string s = "zzazz";
    cout << minInsertion(s) << endl;
    return 0;
}