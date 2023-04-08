#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int get(int i, int j, vector<vector<int>> &prefix)
{
    // to handle the edge cases
    if (i < 0)
        i = 0;
    if (i >= prefix.size())
        i = prefix.size() - 1;
    if (j < 0)
        j = 0;
    if (j >= prefix[0].size())
        j = prefix[0].size() - 1;
    return prefix[i][j];
}

vector<vector<int>> BlockSum(vector<vector<int>> &grid, int k)
{
    int m = grid.size();
    int n = grid[0].size();
    // find the prefix sum
    vector<vector<int>> temp(grid.size() + 1, vector<int>(grid[0].size() + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            temp[i][j] = temp[i - 1][j] + temp[i][j - 1] - temp[i - 1][j - 1] + grid[i - 1][j - 1];
        }
    }
    for (int i = 0; i <= m; i++)
    {

        for (int j = 0; j <= n; j++)
        {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    vector<vector<int>> ans = grid;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {

            ans[i][j] = get(i + k + 1, j + k + 1, temp) - get(i - k, j + k + 1, temp) - get(i + k + 1, j - k, temp) + get(i - k, j - k, temp);
        }
    }
    return ans;
}

int main()
{
    int row;
    int col;
    cout << "enter the number of row for the matrix:" << endl;
    cin >> row;
    cout << "enter the number of col for the matrix:" << endl;
    cin >> col;

    vector<vector<int>> matrix(row, vector<int>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int temp;
            cout << "enter the element for the:" << i << " th row" << endl;
            cin >> temp;
            matrix[i][j] = temp;
        }
    }

    cout << "enter the k val to get the block sum:" << endl;
    int k;
    cin >> k;
    vector<vector<int>> ans(row, vector<int>(col));

    ans = BlockSum(matrix, k);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}