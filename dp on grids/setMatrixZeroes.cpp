#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void setZeroesNew(vector<vector<int>> &grid)
{
    int col0 = 0;

    for (int i = 0; i < grid.size(); i++)
    {
        if (grid[i][0] == 0)
            col0 = 1;
        for (int j = 1; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 0)
            {
                grid[i][0] = 0;
                grid[0][j] = 0;
            }
        }
    }

    for (int i = grid.size() - 1; i >= 0; i--)

    {
        for (int j = grid[0].size() - 1; j >= 1; j--)
        {
            if (grid[i][0] == 0 || grid[0][j] == 0)
            {
                grid[i][j] = 0;
            }
        }
        if (col0)
            grid[i][0] = 0;
    }
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void setZeroes(vector<vector<int>> grid)
{
    int row = grid.size();
    int col = grid[0].size();

    vector<int> forRow(row, 1);
    vector<int> forCol(col, 1);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 0)
            {

                forRow[i] = 0;
                forCol[j] = 0;
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (forRow[i] == 0 || forCol[j] == 0)
            {
                grid[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    vector<vector<int>> grid{{1, 1, 1},
                             {1, 0, 1},
                             {1, 1, 1}};

    setZeroes(grid);
    cout << endl;
    setZeroesNew(grid);

    return 0;
}