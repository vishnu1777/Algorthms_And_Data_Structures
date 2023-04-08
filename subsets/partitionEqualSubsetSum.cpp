//code studio problem

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool func(int idx,vector<int>&nums,int tar,vector<vector<int>>&dp)
{
    if(tar ==0)return true;
    if(idx == 0)return (nums[0] == tar);
    if(dp[idx][tar]!=-1)return dp[idx][tar];
    bool notTake = func(idx-1,nums,tar,dp);
    bool take = false;
    if(nums[idx]<=tar)take = func(idx-1,nums,tar-nums[idx],dp);

    return dp[idx][tar] = take | notTake;
}
bool funcTab(vector<int>&nums,int tar)
{

  int n = nums.size();
    vector<vector<bool>>dp(n,vector<bool>(tar+1,0));

   for(int i=0;i<n;i++)dp[i][0] = true;
   if(nums[0]<=tar)dp[0][nums[0]] = true;
   for(int i=1;i<n;i++)
   {
    for(int target=1;target<=tar;target++)
    {
        bool notTake = dp[i-1][target];
        bool take = false;
        if(nums[i]<=target)take = dp[i-1][target-nums[i]];
        dp[i][target] = take or notTake;
    }
   }
   return dp[n-1][tar];

}
bool funcSpace(vector<int>&nums,int tar)
{

  int n = nums.size();
   vector<bool>prev(tar+1),curr(tar+1);

   for(int i=0;i<n;i++)prev[0] = true;
   if(nums[0]<=tar)prev[nums[0]] = true;
   for(int i=1;i<n;i++)
   {
    for(int target=1;target<=tar;target++)
    {
        bool notTake = prev[target];
        bool take = false;
        if(nums[i]<=target)take =prev[target-nums[i]];
      curr[target] = take or notTake;
    }
    prev = curr;
   }
   return prev[tar];

}
bool partition(vector<int>&nums)
{
   int n = nums.size();
   int totalSum =0;
   for(int n :nums)totalSum+=n;
    vector<vector<int>>dp(n,vector<int>(totalSum/2+1,-1));
   if(totalSum%2!=0)return false;
  
//    else return func(n-1,nums,totalSum/2,dp);
    // else return funcTab(nums,totalSum/2);
     else return funcSpace(nums,totalSum/2);
}

int main()
{

    vector<int>nums = {1,5,11,5};
    bool ans = partition(nums);
    if(ans)cout<<"partition can be made"<<endl;
    else cout<<"partition cannot be made"<<endl;
    return 0;
}