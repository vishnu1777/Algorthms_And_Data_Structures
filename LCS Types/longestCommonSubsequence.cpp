#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int func(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
    {
        return dp[i][j] = 1 + func(i - 1, j - 1, s1, s2, dp);
    }

    return dp[i][j] = max(func(i, j - 1, s1, s2, dp), func(i - 1, j, s1, s2, dp));
}

int getSequence(string &s1, string &s2)
{

    int m = s1.length();
    int n = s2.length();
    // vector<vector<int>> dp(i, vector<int>(j, -1));

    // return func(i - 1, j - 1, s1, s2, dp);
    int ans = 0;
    //  vector<vector<int>> dp(m+1, vector<int>(n+1.0));

    //  for (int i = 1; i <= m; i++)
    //  {
    //     for(int j=1;j<=n;j++)
    //     {
    //         if(s1[i-1] == s2[j-1])
    //         {
    //             dp[i][j] =1+ dp[i-1][j-1];
    //         }
    //         else
    //         {
    //             dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
    //         }
    //         ans = max(ans,dp[i][j]);
    //     }
    //  }

    vector<int> prev(n + 1, 0), curr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s2[i - 1] == s1[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
            }
            else
            {
                curr[j] = max(curr[j - 1], prev[j]);
            }
            ans = max(ans, curr[j]);
        }
        prev = curr;
    }

    return ans;
}
void printSequence(string &s1, string &s2)
{

    int m = s1.length();
    int n = s2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1.0));

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
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout<<endl;
    }
    cout << endl;
    cout << "longest subseqeunce is:" << dp[m][n] << endl;
    int i = m;
    int j = n;
    int index = dp[m][n] - 1;
    string s;
    for (int i = 0; i < dp[m][n]; i++)
    {
        s += "#";
    }
    while (i > 0 and j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            s[index] = s1[i - 1];
            index--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout << s << endl;
}
int main()
{

    string s1;
    string s2;

    cout << "enter the first string:" << endl;
    cin >> s1;
    cout << "enter the second string" << endl;
    cin >> s2;
    int ans = getSequence(s1, s2);
    cout << "the final subsequence is:" << ans << endl;
    printSequence(s1, s2);

    return 0;
}