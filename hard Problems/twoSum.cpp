#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

bool func(int i,vector<int>&nums,int sum)
{

   if(sum == 0)return true;
   if(i== nums.size())return false;
    bool notTake = func(i+1,nums,sum);
    bool take = false;
   if(nums[i]<=sum)
   {
    take = func(i+1,nums,sum-nums[i]);
    
   }
   return take | notTake;

}

void twoSum(vector<int>&nums,int sum)
{
    int n = nums.size();
    
    if(func(0,nums,sum))cout<<"true"<<endl;
    else cout<<"false";

}





int main()
{

    int sum = 6;
    vector<int>nums = {1,1,3};
    twoSum(nums,sum);
    return 0;
}