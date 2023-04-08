// You are a professional robber planning to rob houses along a street. 
// Each house has a certain amount of money stashed, 
// the only constraint stopping you from robbing each of them is that adjacent 
// houses have security systems connected and it will automatically contact the police
//  if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house,
//  return the maximum amount of money you can rob tonight without alerting the police.
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int func(int idx,vector<int>&nums,vector<int>&dp)
{
    if(idx<0)return 0;
    if(idx == 0 )return nums[idx];
    if(dp[idx]!=-1)return dp[idx];

    int notTake = 0+func(idx-1,nums,dp);
    int take = nums[idx]+func(idx-2,nums,dp);
    return dp[idx]= max(notTake,take);
}
int tabulation(vector<int>&nums)
{
    int n  = nums.size();
    vector<int>dp(n+1);
    dp[0] = nums[0];

    for(int i=1;i<nums.size();i++)
    {
        int notTake = 0+dp[i-1];
        int take = nums[i];
        if(i>1)take += dp[i-2];
        dp[i] = max(notTake,take);
    }
    return dp[n-1];
}
int tabulationSpace(vector<int>&nums)
{
    int n= nums.size();
    int prev = nums[0];
    int prev2 =0;
    for(int i=1;i<nums.size();i++)
    {
        int curr= max(nums[i]+prev2,prev);
        prev2 = prev;
        prev = curr;
    }
    return prev;

}
int maxMoney(vector<int>&nums)
{
    int n= nums.size();
    vector<int>dp(n,-1);
    // return func(n-1,nums,dp);
    // return tabulation(nums);
    return tabulationSpace(nums);
}


int main()
{

    vector<int>nums = {1,2,3,1};
    cout<<maxMoney(nums)<<endl;
    return 0;
}