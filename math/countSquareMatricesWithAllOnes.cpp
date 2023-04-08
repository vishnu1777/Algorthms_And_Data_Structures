#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
// Given a m * n matrix of ones and zeros, return how many square submatrices have

// Input: matrix =
// [
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
// ]
// Output: 15
// Explanation:
// There are 10 squares of side 1.
// There are 4 squares of side 2.
// There is  1 square of side 3.
// Total number of squares = 10 + 4 + 1 = 15.

int countSquare(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col));
    for (int i = 0; i < row; i++)
    {
        if (grid[i][0] == 1)
            dp[i][0] = 1;
    }
    for (int j = 0; j < col; j++)
    {
        if (grid[0][j] == 1)
            dp[0][j] = 1;
    }

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (grid[i][j] == 1)
            {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += dp[i][j];
        }
    }
    return sum;
}

int main()
{

    vector<vector<int>> grid{{0, 1, 1, 1},
                             {1, 1, 1, 1},
                             {0, 1, 1, 1}};
    cout << countSquare(grid) << endl;
    return 0;
}