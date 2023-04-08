#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
// Given an array nums of distinct integers,
// return all the possible permutations. You can return the answer in any order.

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
void func(vector<int> &nums, vector<vector<int>> &res, vector<int> &vis, vector<int> &temp)
{
    if (temp.size() == nums.size())
    {
        res.push_back(temp);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (vis[i] == 0)
        {
            temp.push_back(nums[i]);

            vis[i] = 1;
            func(nums, res, vis, temp);
            temp.pop_back();
            vis[i] = 0;
        }
    }
}

void funcOptimized(int idx, vector<int> &nums, vector<vector<int>> &res)
{

    if (idx == nums.size())
    {
        res.push_back(nums);
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[i], nums[idx]);
        funcOptimized(idx + 1, nums, res);
        swap(nums[i], nums[idx]);
    }
}

void possiblePermutations(vector<int> &nums)
{
    int n = nums.size();
    vector<int> vis(n, 0);
    vector<vector<int>> res;
    vector<int> temp;
    // func(nums, res, vis, temp);
    funcOptimized(0, nums, res);

    for (vector<int> num : res)
    {
        for (int n : num)
            cout << n << " ";
        cout << endl;
    }
}

int main()
{

    vector<int> nums = {1, 2, 3};
    possiblePermutations(nums);
    return 0;
}