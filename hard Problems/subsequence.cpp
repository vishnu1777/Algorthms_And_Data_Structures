#include <stdio.h>
#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

void func(int idx, vector<int> &nums, vector<vector<int>> &res, vector<int> &temp)
{

    // temp.push_back(nums[idx]);
    // func(idx + 1, nums, res, temp);
    // temp.pop_back();
    // func(idx + 1, nums, res, temp);
    res.push_back(temp);

    for(int i=idx;i<nums.size();i++)
    {
        if(i!=idx and nums[i]==nums[i-1])continue;
        temp.push_back(nums[i]);
        func(i+1,nums,res,temp);
        temp.pop_back();
    }
    return;
}

void subsequence(vector<int> &nums)
{

    vector<vector<int>> res;
    vector<int> temp;
    sort(nums.begin(),nums.end());
    func(0, nums, res, temp);

    for (vector<int> num : res)
    {
        for (int n : num)
            cout << n << " ";
        cout << endl;
    }
}

int main()
{
    vector<int> nums = {3, 1,1, 2};
    subsequence(nums);
    return 0;
}