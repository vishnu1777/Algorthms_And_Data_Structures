#include <stdio.h>
#include <iostream>

#include <algorithm>
#include <vector>
using namespace std;

// Given a collection of candidate numbers (candidates) and a target number (target),
// find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output:
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
void func(int idx, vector<int> &nums, int tar, vector<vector<int>> &res, vector<int> &temp)
{
    if (tar == 0)
    {
        res.push_back(temp);
        return;
    }

    for (int i = idx; i < nums.size(); i++)

    {
        if (i != idx and nums[i] == nums[i - 1])
            continue;
        if (nums[i] <= tar)
        {
            temp.push_back(nums[i]);
            func(i + 1, nums, tar - nums[i], res, temp);
            temp.pop_back();
        }
    }
}
void combo2(int idx,vector<int>&nums,int tar,vector<vector<int>>&res,vector<int>&temp)
{

    if(idx<0)return;
    if(tar == 0){
        res.push_back(temp);
        return;
    }

    int i = idx;
    combo2(idx+1,nums,tar,res,temp);
    if(nums[idx]<=tar)
    {
        if(nums[idx]== nums[idx-1] and idx>0)
        {
            temp.push_back(nums[idx]);
            combo2(idx+1,nums,tar,res,temp);
            temp.pop_back();
        }
    }

}

void combination(vector<int> &nums, int tar)
{
    vector<vector<int>> res;
    vector<int> temp;
    sort(nums.begin(), nums.end());

    // func(0, nums, tar, res, temp);
    combo2(0,nums,tar,res,temp);

    for (vector<int> num : res)
    {
        for (int n : num)
        {
            cout << n << " ";
        }
        cout << "  ";
    }
}

int main()
{

    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    int tar;
    cout << "enter the target for the combination:" << endl;
    cin >> tar;
    combination(nums, tar);

    return 0;
}