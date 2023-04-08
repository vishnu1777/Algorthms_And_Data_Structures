#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int dfs(int i, int j, int m, int n, vector<vector<int>> &grid)
{
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
        return 0;

    return min(dfs(i - 1, j, m, n, grid), min(dfs(i, j - 1, m, n, grid), dfs(i - 1, j - 1, m, n, grid))) + 1;
}

int MaximalSquare(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    // memoiation
    // for (int i = m-1; i >=0; i--)
    // {
    // for (int j = n-1; j >=0; j--)
    //     {
    //         ans = max(ans, dfs(i, j, m, n, grid));
    //     }
    // }

    // tabulation without space optimization
    //  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    //  for (int i = 1; i <= m; i++)
    //  {
    //      for (int j = 1; j <= n; j++)
    //      {
    //          if (grid[i - 1][j - 1] == 0)
    //          {
    //              dp[i][j] = 0;
    //          }
    //          else
    //          {
    //              dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
    //          }
    //          ans = max(ans, dp[i][j]);
    //      }
    //  }

    // tabulation with space optimization
    vector<int> prev(n + 1, 0), curr(n + 1);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (grid[i - 1][j - 1] == 0)
            {
                curr[j] = 0;
            }
            else
            {
                curr[j] = min(prev[j], min(curr[j - 1], prev[j - 1])) + 1;
            }
            ans = max(ans, curr[j]);
        }
        prev = curr;
    }

    return ans * ans;
}

int main()
{
    int row;
    int col;
    cout << "enter the number of row to the matrix:" << endl;
    cin >> row;
    cout << "enter the number of cols to the matrix:" << endl;
    cin >> col;
    vector<vector<int>> matrix(row, vector<int>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int temp;
            cout << "enter the elements for the:" << i << " th row" << endl;
            cin >> temp;
            matrix[i][j] = temp;
        }
        cout << endl;
    }
    int ans = MaximalSquare(matrix);
    cout << "the maximal square is:" << ans << endl;
    return 0;
}