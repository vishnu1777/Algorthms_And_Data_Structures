// There is a robot on an m x n grid.
// The robot is initially located at the top-left
// corner (i.e., grid[0][0]). The robot tries to move to the
//  bottom-right corner (i.e., grid[m - 1][n - 1]).
//   The robot can only move either down or right at any point in time.

// Given the two integers m and n,
// return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The test cases are generated so that the answer will be less than or equal to 2 * 109.
// Input: m = 3, n = 7
// Output: 28
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int func(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 and j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    // because we are moving from m-1 and n-1 we can move our robot to upside and left rather than bottom and right
    int left = func(i, j - 1, dp);
    int up = func(i - 1, j, dp);
    return dp[i][j] = left + up;
}
int tabulation(int m, int n)
{
    // vector<vector<int>> dp(m, vector<int>(n, 1));
    // dp[0][0] = 1;
    // for(int i=1;i<m;i++)
    // {
    //     for(int j=1;j<n;j++)
    //     {

    //         int  left = dp[i][j-1];
    //        int  up = dp[i-1][j];
    //         dp[i][j] = left+up;
    //     }
    // }
    // return dp[m-1][n-1];
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 and j == 0)
                dp[i][j] = 1;
            else
            {
                int left = 0;
                int up = 0;
                if (j > 0)
                    left = dp[i][j - 1];
                if (i > 0)
                    up = dp[i - 1][j];
                dp[i][j] = left + up;
            }
        }
    }
    return dp[m - 1][n - 1];
}
int tabulationSpace(int m, int n)
{
    vector<int> prev(n), curr(n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 and j == 0)
               curr[j] = 1;
            else
            {
                int left = 0;
                int up = 0;
                if (j > 0)
                    left = curr[j - 1];
                if (i > 0)
                    up = prev[j];
                curr[j] = left + up;
            }
        }
        prev = curr;
    }
    return prev[n - 1];
}
int paths(int m, int n)
{
    // vector<vector<int>> dp(m, vector<int>(n, -1));
    // return func(m - 1, n - 1, dp);
    // return tabulation(m, n);
    return tabulationSpace(m,n);
}

int main()
{

    int m = 3;
    int n = 7;
    cout << paths(m, n) << endl;
    return 0;
}