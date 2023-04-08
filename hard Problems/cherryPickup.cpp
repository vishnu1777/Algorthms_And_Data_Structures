#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


// You are given a rows x cols matrix grid representing a field of 
// cherries where grid[i][j] represents the number of cherries that you 
// can collect from the (i, j) cell.

// You have two robots that can collect cherries for you:

// Robot #1 is located at the top-left corner (0, 0), and
// Robot #2 is located at the top-right corner (0, cols - 1).
// Return the maximum number of cherries collection using both robots by following the rules below:

// From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
// When any robot passes through a cell, It picks up all cherries,
// and the cell becomes an empty cell.
// When both robots stay in the same cell, only one takes the cherries.
// Both robots cannot move outside of the grid at any moment.
// Both robots should reach the bottom row in grid.

// Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
// Output: 24
// Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
// Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
// Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.l
// Total of cherries: 12 + 12 = 24.

int func(int i, int a, int b, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (a < 0 || a >= m || b < 0 || b >= m)
        return -1e8;
    if (i == grid.size() - 1)
    {
        if (a == b)
        {
            return grid[i][a];
        }
        else
        {
            return grid[i][a] + grid[i][b];
        }
    }
    if (dp[i][a][b] != -1)
        return dp[i][a][b];

    int maxi = INT_MIN;

    for (int j1 = -1; j1 <= 1; j1++)
    {
        for (int j2 = -1; j2 <= 1; j2++)
        {
            int val;
            if (a == b)
                val = grid[i][a];
            else
            {
                val = grid[i][a] + grid[i][b];
            }
            val += func(i + 1, a + j1, b + j2, m, grid, dp);
            maxi = max(maxi, val);
        }
    }
    return dp[i][a][b] = maxi;
}

int funcTab(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
    // write the base case
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
            {
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            }
            else
            {
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int a = 0; a < m; a++)
        {
            for (int b = 0; b < m; b++)
            {

                int maxi = INT_MIN;

                for (int j1 = -1; j1 <= 1; j1++)
                {
                    for (int j2 = -1; j2 <= 1; j2++)
                    {
                        int val;
                        if (a == b)
                            val = grid[i][a];
                        else
                        {
                            val = grid[i][a] + grid[i][b];
                        }
                        if (a + j1 >= 0 and a + j1 < m and b + j2 >= 0 and b + j2 < m)
                        {
                            val += dp[i + 1][a + j1][b + j2];
                        }
                        else
                            val += -1e8;

                        maxi = max(maxi, val);
                    }
                }
                dp[i][a][b] = maxi;
            }
        }
    }
    return dp[0][0][m - 1];
}
int funcTabSpace(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>> next(m, vector<int>(m, 0));
    vector<vector<int>> curr(m, vector<int>(m, 0));

    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
            {
                next[j1][j2] = grid[n - 1][j1];
            }
            else
            {
                next[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int a = 0; a < m; a++)
        {
            for (int b = 0; b < m; b++)
            {

                int maxi = INT_MIN;

                for (int j1 = -1; j1 <= 1; j1++)
                {
                    for (int j2 = -1; j2 <= 1; j2++)
                    {
                        int val;
                        if (a == b)
                            val = grid[i][a];
                        else
                        {
                            val = grid[i][a] + grid[i][b];
                        }
                        if (a + j1 >= 0 and a + j1 < m and b + j2 >= 0 and b + j2 < m)
                        {
                             val += next[a + j1][b + j2];
                        }
                        else
                            val += -1e8;

                        maxi = max(maxi, val);
                    }
                }
                curr[a][b] = maxi;
            }
        }
        next = curr;
    }
    return curr[0][m - 1];
}

int maxiChocolates(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    // return func(0, 0, m - 1, m, grid,dp);

    // return funcTab(n, m, grid);
    return funcTabSpace(n, m, grid);
}

int main()
{

    vector<vector<int>> matrix = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };

    int n = matrix.size();
    int m = matrix[0].size();

    cout << maxiChocolates(n, m, matrix);
    return 0;
}