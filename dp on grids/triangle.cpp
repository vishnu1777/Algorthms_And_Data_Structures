// Given a triangle array,
// return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below.
//  More formally, if you are on index i on the current row,
// you may move to either index i or index i + 1 on the next row.
// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int func(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i > grid.size() || j > grid[0].size())
        return 1e8;
    if (i == grid.size() - 1)
        return grid[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int down = grid[i][j] + func(i + 1, j, grid, dp);
    int diagonal = grid[i][j] + func(i + 1, j + 1, grid, dp);

    return dp[i][j] = min(down, diagonal);
}
int tabulation(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int j = 0; j < n; j++)
        dp[n - 1][j] = grid[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = grid[i][j] + dp[i + 1][j];
            int diagonal = grid[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, diagonal);
        }
    }
    return dp[0][0];
}

int tabulationSpace(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<int> next(n), curr(n);
    for (int j = 0; j < n; j++)
        next[j] = grid[n - 1][j];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = grid[i][j] + next[j];
            int diagonal = grid[i][j] + next[j + 1];
            curr[j] = min(down, diagonal);
        }
        next = curr;
    }
    return next[0];
}

int triangle(vector<vector<int>> &grid)
{
    vector<vector<int>> dp(grid.size(), vector<int>(grid.size(), -1));
    // return func(0, 0, grid, dp);
    // return tabulation(grid);
    return tabulationSpace(grid);
}

int main()
{

    vector<vector<int>> grid{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << triangle(grid) << endl;
    return 0;
}