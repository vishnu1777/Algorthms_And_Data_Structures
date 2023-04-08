#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, string s, vector<string> &ans)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid.size() || grid[i][j] == 0 || vis[i][j])
        return;
    if (i == grid.size() - 1 and j == grid.size() - 1)
    {
        ans.push_back(s);
        return;
    }

    vis[i][j] = 1;
    dfs(i + 1, j, grid, vis, s + "D", ans);
    dfs(i, j - 1, grid, vis, s + "L", ans);
    dfs(i, j + 1, grid, vis, s + "R", ans);
    dfs(i - 1, j, grid, vis, s + "U", ans);
    vis[i][j] = 0;
}

void Maze(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<string> ans;
    string s = "";
    vector<vector<int>> vis(n, vector<int>(n));
    if (grid[0][0] == 1)
        dfs(0, 0, grid, vis, s, ans);
    for (string s : ans)
        cout << s << " ";
}

int main()
{

    vector<vector<int>> grid{{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};
    Maze(grid);
    return 0;
}