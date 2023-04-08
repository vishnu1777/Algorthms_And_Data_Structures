#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
// babad
string LPS(string &s)
{

    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    string ans;
    int maxLen = 0;
    for (int diff = 0; diff < n; diff++)
    {
        for (int i = 0, j = i + diff; j < n; i++, j++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
            }
            else if (diff == 1)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = 2;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
            else
            {
                if (s[i] == s[j] and dp[i + 1][j - 1])
                {
                    dp[i][j] = dp[i + 1][j + 1] + 2;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
            if (dp[i][j])
            {
                if (j - i + 1 > maxLen)
                {
                    maxLen = j - i + 1;
                    ans = s.substr(i, maxLen);
                }
            }
        }
    }
    return ans;
}

int main()
{

    string s;
    cout << "enter the string:" << endl;

    cin >> s;

    string ans = LPS(s);
    cout << "the longest palindromic substring is:" << ans << endl;

    return 0;
}