#include <stdio.h>
#include <iostream>
#include <algorithm>

#include <vector>

using namespace std;

// Given a collection of numbers, nums,
// that might contain duplicates, return all possible unique permutations in any order.
// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]

void funcOptimized(int idx, vector<int> &nums, vector<vector<int>> &res)
{

    if (idx == nums.size())
    {
        res.push_back(nums);
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        if (i != idx and nums[i] == nums[i - 1])
            continue;
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
    sort(nums.begin(), nums.end());
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

    vector<int> nums = {1, 1, 2};
    possiblePermutations(nums);
    return 0;
}
