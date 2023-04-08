#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int lcs(string &s1, string &s2)
{
    int m = s1.length();
    int n = s2.length();
    int ans = 0;

    // vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    // for(int i=1;i<=m;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         if(s1[i-1] == s2[j-1])
    //         {
    //             dp[i][j] = 1+dp[i-1][j-1];
    //         }
    //         else
    //         {
    //             dp[i][j] =0;
    //         }
    //         ans = max(ans,dp[i][j]);
    //     }
    // }
    vector<int> prev(n + 1, 0), curr(n + 1);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
            }
            else
            {
                curr[j] = 0;
            }
            ans = max(ans, curr[j]);
        }
        prev = curr;
    }

    return ans;
}

int func(int i,int j,string&s1,string& s2,vector<vector<int>>&dp)
{
  if(i<0 || j<0)return 0;

 if(dp[i][j]!=-1)return dp[i][j];

  if(s1[i] == s2[j])
  {
    return dp[i][j] = 1+func(i-1,j-1,s1,s2,dp);
  }
  return dp[i][j] = 0+max(func(i-1,j,s1,s2,dp),func(i,j-1,s1,s2,dp));

}


int LCS(string&s1,string&s2)
{
    // return lcs(s1,s2);
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return func(n-1,m-1,s1,s2,dp);
} 

int main()
{
    string s1;
    string s2;
    cout << "enter the string one:" << endl;

    cin >> s1;
    cout << "enter the string two:" << endl;
    cin >> s2;

    int ans = LCS(s1, s2);
    cout << "the longest common substring is:" << ans << endl;

    return 0;
}