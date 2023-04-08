#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
// You are given an m x n integer array grid.
// There is a robot initially located at the top-left corner (i.e., grid[0][0]).
//  The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]).
//   The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid.
// A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The testcases are generated so that the answer will be less than or equal to 2 * 109.
// Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// Output: 2
// Explanation: There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right
int func(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0 || grid[i][j] == 1)
        return 0;
    if (i == 0 and j == 0)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];

    int left = func(i, j - 1, grid, dp);
    int up = func(i - 1, j, grid, dp);
    return dp[i][j] = left + up;
}
int tabulation(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col));

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int left = 0;
            int up = 0;
            if (i >= 0 and j >= 0 and grid[i][j] == 1)
                dp[i][j] = 0;
            else if (i == 0 and j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                if (j > 0)
                    left = dp[i][j - 1];
                if (i > 0)
                    up = dp[i - 1][j];
                dp[i][j] = left + up;
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
            int left = 0;
            int up = 0;
            if (i >= 0 and j >= 0 and grid[i][j] == 1)
                curr[j] = 0;
            else if (i == 0 and j == 0)
            {
                curr[j] = 1;
            }
            else
            {
                if (j > 0)
                    left = curr[j - 1];
                if (i > 0)
                    up = prev[j];
                curr[j] = left + up;
            }
        }
        prev = curr;
    }
    return prev[col - 1];
}
int ways(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();
    // vector<vector<int>>dp(row,vector<int>(col,-1));
    // return func(row - 1, col - 1, grid,dp);

    // return tabulation(grid);
    return tabulationSpace(grid);
}
int main()
{

    vector<vector<int>> grid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << ways(grid) << endl;
    return 0;
}