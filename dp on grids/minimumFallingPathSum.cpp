// Given an n x n array of integers matrix,
//  return the minimum sum of any falling path through matrix.

// A falling path starts at any element in the first row and
// chooses the element in the next row that is either directly below or diagonally left/right.
// Specifically, the next element from
// position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
// Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
// Output: 13
// Explanation: There are two falling paths with a minimum sum as shown
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int dfs(int i, int j, int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i < 0 || i >= m || j < 0 || j >= n)
        return 1e9;
    if (i == m - 1)
        return grid[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int down = grid[i][j] + dfs(i + 1, j, m, n, grid, dp);
    int leftDiagonal = grid[i][j] + dfs(i + 1, j - 1, m, n, grid, dp);
    int rightDiagonal = grid[i][j] + dfs(i + 1, j + 1, m, n, grid, dp);
    return dp[i][j] = min(down, min(leftDiagonal, rightDiagonal));
}
int tabulation(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col));
    for (int j = 0; j < col; j++)
        dp[row - 1][j] = grid[row - 1][j];

    for (int i = row - 2; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            int down = grid[i][j] + dp[i + 1][j];
            int leftDiagonal = grid[i][j];
            int rightDiagonal = grid[i][j];
            if (j > 0)
                leftDiagonal += dp[i + 1][j - 1];
            else
                leftDiagonal = 1e8;
            if (j < col - 1)
                rightDiagonal = grid[i][j] + dp[i + 1][j + 1];
            else
                rightDiagonal = 1e9;
            dp[i][j] = min(down, min(leftDiagonal, rightDiagonal));
        }
    }
    int ans = INT_MAX;
    for (int j = 0; j < col; j++)
    {
        ans = min(ans, dp[0][j]);
    }
    return ans;
}
int tabulationSpace(vector<vector<int>>&grid)
{
     int row = grid.size();
    int col = grid[0].size();
    vector<int>prev(col),curr(col);
    for (int j = 0; j < col; j++)
        prev[j] = grid[row - 1][j];

    for (int i = row - 2; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            int down = grid[i][j] + prev[j];
            int leftDiagonal = grid[i][j];
            int rightDiagonal = grid[i][j];
            if (j > 0)
                leftDiagonal += prev[j - 1];
            else
                leftDiagonal = 1e8;
            if (j < col - 1)
                rightDiagonal = grid[i][j] + prev[j + 1];
            else
                rightDiagonal = 1e9;
           curr[j] = min(down, min(leftDiagonal, rightDiagonal));
        }
        prev = curr;
    }
    int ans = INT_MAX;
    for (int j = 0; j < col; j++)
    {
        ans = min(ans, prev[j]);
    }
    return ans; 
}
int pathSum(vector<vector<int>> &grid)

{
    // int ans = INT_MAX;
    // int row = grid.size();
    // int col = grid[0].size();
    // vector<vector<int>>dp(row,vector<int>(col,-1));

    // for (int j = 0; j < col; j++)
    // {
    //     ans = min(ans, dfs(0, j, row, col, grid,dp));
    // }
    // return ans;
    // return tabulation(grid);
    return tabulationSpace(grid);
}

int main()
{

vector<vector<int>> grid{{-19,57},{-40,-5}};
    cout << pathSum(grid) << endl;
    return 0;
}