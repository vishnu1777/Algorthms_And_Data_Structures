// Given an array of integers heights representing the histogram's
//  bar height where the width of each bar is 1,
//  return the area of the largest rectangle in the histogram.
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int getArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> s;
    vector<int> leftSmall(n), rightSmall(n);
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() and heights[s.top()] >= heights[i])
        {
            s.pop();
        }
        if (s.empty())
            leftSmall[i] = 0;
        else
            leftSmall[i] = s.top() + 1;
        s.push(i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() and heights[s.top()] >= heights[i])
        {
            s.pop();
        }
        if (s.empty())
            rightSmall[i] = n - 1;
        else
            rightSmall[i] = s.top() - 1;
        s.push(i);
    }
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, heights[i] * (rightSmall[i] - leftSmall[i] + 1));
    }
    return maxi;
}
int getMax(vector<int> &heights)
{
    int n = heights.size();
    stack<int> s;
    int maxArea = 0;
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
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }
    return maxArea;
}

int main()
{

    vector<int> heights = {2, 1, 5, 6, 2, 3};
    // cout << getArea(heights) << endl;
    cout << getMax(heights) << endl;
    return 0;
}