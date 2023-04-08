// // We are given an ‘N*M’ matrix.
// We need to find the maximum path sum from any cell of the first row to any cell of the last row.

// // At every cell we can move in three directions:
// to the bottom cell (↓),
//  to the bottom-right cell(↘),
//  or to the bottom-left cell(↙).

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int dfs(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (j < 0 || j >= m)
        return -1e8;
    if (i == 0)
    {
        return grid[0][j];
    }
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = grid[i][j] + dfs(i - 1, j, n, m, grid, dp);
    int left = grid[i][j] + dfs(i - 1, j - 1, n, m, grid, dp);
    int right = grid[i][j] + dfs(i - 1, j + 1, n, m, grid, dp);

    return dp[i][j] = max(up, max(left, right));
}
int memo(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int ans = INT_MIN;
    vector<vector<int>> dp(n, vector<int>(m, -1));

    for (int j = 0; j < m; j++)
    {
        ans = max(ans, dfs(n - 1, j, n, m, grid, dp));
    }
    return ans;
}
int tabulation(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int ans = INT_MIN;
    // write the base case
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = grid[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = grid[i][j] +  dp[i - 1][j];
            int left = grid[i][j];
            int right = grid[i][j] ;
            if (j > 0) left += dp[i - 1][j - 1];
            else left += -1e8;

            if (j < m - 1)
            {
                right += dp[i - 1][ j + 1] ;
            }
            else
            {
                right += -1e8;
            }
            dp[i][j] = max(up,max(left,right));
        }
    }
    for(int i=0;i<m;i++)ans= max(ans,dp[n-1][i]);
    return ans;
}
int tabSpace(vector<vector<int>>&grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int ans = INT_MIN;
    // write the base case
   vector<int>prev(m,0),curr(m);
    for (int j = 0; j < m; j++)
    {
        prev[j] = grid[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = grid[i][j] +  prev[j];
            int left = grid[i][j];
            int right = grid[i][j] ;
            if (j > 0) left += prev[j - 1];
            else left += -1e8;

            if (j < m - 1)
            {
                right += prev[ j + 1] ;
            }
            else
            {
                right += -1e8;
            }
           curr[j] = max(up,max(left,right));
        }
        prev = curr;
    }
    for(int i=0;i<m;i++)ans= max(ans,prev[i]);
    return ans;

}

int getMaxPathSum(vector<vector<int>> &grid)
{

    // return memo(grid);
    // return tabulation(grid);
    return tabSpace(grid);
}

int main()
{

    vector<vector<int>> matrix{{1, 2, 10, 4},
                               {100, 3, 2, 1},
                               {1, 1, 20, 2},
                               {1, 2, 2, 1}};

    cout << getMaxPathSum(matrix);
}