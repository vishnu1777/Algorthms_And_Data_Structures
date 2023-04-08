#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
bool isValid(int row, int col, char c, vector<vector<char>> &grid)
{
    for (int i = 0; i < 9; i++)
    {
        if (grid[row][i] == c)
            return false;
        if (grid[i][col] == c)
            return false;
        if (grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}
bool solve(vector<vector<char>> &grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid.size(); j++)
        {
            if (grid[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (isValid(i, j, c, grid))
                    {
                        grid[i][j] = c;
                        if (solve(grid))
                        {
                            return true;
                        }
                        else
                        {
                            grid[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void sudokuSolver(vector<vector<char>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();

    solve(grid);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << grid[i][j] << "  ";
        }

        cout << endl;
        cout << endl;
    }
}

int main()
{

    vector<vector<char>> grid{
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'}};

    sudokuSolver(grid);
    return 0;
}