#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
// Given a m x n grid filled with non-negative numbers,
// find a path from top left to bottom right,
// which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
int func(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 and j == 0)
        return grid[0][0];
    if (i < 0 || j < 0)
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];

    int left = grid[i][j] + func(i, j - 1, grid, dp);
    int up = grid[i][j] + func(i - 1, j, grid, dp);
    return dp[i][j] = min(left, up);
}
int tabulation(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col));
    dp[0][0] = grid[0][0];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            if (i == 0 and j == 0)
                dp[i][j] = grid[i][j];
            else
            {
                int left = grid[i][j];
                int up = grid[i][j];
                if (i > 0)
                    up += dp[i - 1][j];
                else
                    up = 1e9;
                if (j > 0)
                    left += dp[i][j - 1];
                else
                    left = 1e9;

                dp[i][j] = min(left, up);
            }
        }
    }
    return dp[row - 1][col - 1];
}
int tabulationSpace(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();
    vector<int> prev(col), curr(col);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            if (i == 0 and j == 0)
                curr[j] = grid[i][j];
            else
            {
                int left = grid[i][j];
                int up = grid[i][j];
                if (i > 0)
                    up += prev[j];
                else
                    up = 1e9;
                if (j > 0)
                    left += curr[j - 1];
                else
                    left = 1e9;

                curr[j] = min(left, up);
            }
        }
        prev = curr;
    }
    return prev[col - 1];
}
int minimumPath(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col, -1));
    // return func(row - 1, col - 1, grid, dp);
    // return tabulation(grid);
    return tabulationSpace(grid);
}

int main()
{

    vector<vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << minimumPath(grid) << endl;
    return 0;
}