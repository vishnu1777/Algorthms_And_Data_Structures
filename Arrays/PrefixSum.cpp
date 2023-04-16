#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int getSum(vector<int>&nums,int l,int r)
{
    for(int i=1;i<nums.size();i++)
    {
        nums[i] = nums[i]+nums[i-1];
    }

    return nums[r] - nums[l];
}



int main()
{
    vector<int>nums = {1,2,3,4,5};
    cout<<getSum(nums,0,2)<<endl;;
    return 0;
}