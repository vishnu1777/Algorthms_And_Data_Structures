#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int> &blocks)
{
    // this is naive approach
    int maxLeft = 0;
    int maxRight = 0;
    // set initially maxleft and right as 0;
    vector<int> left(blocks.size());
    vector<int> right(blocks.size());

    for (int i = 0; i < blocks.size(); i++)
    {
        maxLeft = max(maxLeft, blocks[i]);
        left[i] = maxLeft;
    }
    for (int i = blocks.size() - 1; i >= 0; i--)
    {
        maxRight = max(maxRight, blocks[i]);
        right[i] = maxRight;
    }

    int res = 0;
    for (int i = 0; i < blocks.size(); i++)
    {
        res += min(left[i], right[i]) - blocks[i];
    }
    return res;
}
int tapOptimized(vector<int> &blocks)
{
    int maxLeft = 0;
    int maxRight = 0;

    int left = 0;
    int right = blocks.size() - 1;

    int res = 0;
    while (left <= right)
    {
        if (blocks[left] <= blocks[right])
        {
            if (blocks[left] <= maxLeft)
            {
                res += maxLeft - blocks[left];
            }
            else
            {
                maxLeft = blocks[left];
            }
            left++;
        }
        else
        {
            if (blocks[right] <= maxRight)
            {
                res += maxRight - blocks[right];
            }
            else
            {
                maxRight = blocks[right];
            }
            right--;
        }
    }
    return res;
}

int main()
{

    vector<int> blocks = {4, 2, 0, 3, 2, 5};

    int ans = trap(blocks);
    cout << "the number of units of rain water can be collected is:" << ans << endl;
    cout << endl;
    ans = tapOptimized(blocks);
    cout << "the ans is:" << ans << endl;

    return 0;
}