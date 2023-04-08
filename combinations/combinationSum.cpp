#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

// Given an array of distinct integers candidates and a target integer target,
// return a list of all unique combinations of  candidates where the chosen numbers sum to target.
//  You may return the combinations in any order.

// // The same number may be chosen from candidates an unlimited number of times.
// Two combinations are unique  if the frequency of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations
// that sum up to target is less than 150 combinations for the given input.

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.
bool ans = false;
void func(int idx, vector<int> &nums, int target, vector<vector<int>> &res, vector<int> &temp)
{
    if (target == 0)
    {
        ans = true;
        res.push_back(temp);
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        if (nums[i] <= target)
        {
            temp.push_back(nums[i]);
            func(i, nums, target - nums[i], res, temp);
            temp.pop_back();
        }
    }
}
void combo(int idx,vector<int>&nums,int tar,vector<vector<int>>&res,vector<int>&temp)
{
     if(tar == 0)
        {
            res.push_back(temp);
            return;
        }

       if(idx<0)return;
        
    
   
       
       
    

   
    combo(idx-1,nums,tar,res,temp);
    if(nums[idx]<=tar)
    {
         temp.push_back(nums[idx]);
         combo(idx-1,nums,tar-nums[idx],res,temp);
         temp.pop_back();
    }



}

void combinationSum(vector<int> &nums, int &target)
{
    int n =nums.size();
    vector<vector<int>> res;

    vector<int> temp;
    // func(0, nums, target, res, temp);
    combo(n-1,nums,target,res,temp);
    for (vector<int> &n : res)
    {
        for (int num : n)
        {
            cout << num << " ";
        }
        cout << " ";
    }
    if (ans)
        cout << "the sum is present" << endl;
    else
        cout << "the sum is not present" << endl;
}


int main()
{
    vector<int> nums = {2, 3, 6, 7};
    int tar;
    cout << "enter the target sum:" << endl;
    cin >> tar;
    combinationSum(nums, tar);

    return 0;
}