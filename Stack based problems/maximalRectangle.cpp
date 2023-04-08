// Given a rows x cols binary matrix filled with 0's and 1's,
// find the largest rectangle containing only 1's and return its area.
// Input: matrix = [["1","0","1","0","0"],
// ["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.

#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int findArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> s;
    int maxi = 0;
    for (int i = 0; i <= n; i++)
    {
        while (!s.empty() and (i == n || heights[s.top()] >= heights[i]))
        {
            int height = heights[s.top()];
            s.pop();
            int width;
            if (s.empty())
                width = i;
            else
                width = i - s.top() - 1;
            maxi = max(maxi, height * width);
        }
        s.push(i);
    }
    return maxi;
}

int getArea(vector<vector<string>> &mat)
{
    int row = mat.size();
    int col = mat[0].size();
    vector<int> heights(col);
    int maxArea = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] == "1")
            {
                heights[j]++;
            }
            else
                heights[j] = 0;
        }
        int ans = findArea(heights);
        maxArea = max(maxArea, ans);
    }
    return maxArea;
}

int main()
{

    vector<vector<string>> mat{{"1", "0", "1", "0", "0"},

                               {"1", "0", "1", "1", "1"},
                               {"1", "1", "1", "1", "1"},
                               {"1", "0", "0", "1", "0"}};
    cout << getArea(mat) << endl;
    return 0;
}