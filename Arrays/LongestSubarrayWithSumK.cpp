#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
// method one of o(n^2)
int methodOne(vector<int>&nums,int k)
{
 
    int len = 0;
    for(int i=0;i<nums.size();i++)
    {
        int sum = 0;
        for(int j=i;j<nums.size();j++)
        {
            sum+=nums[j];
            if(sum == k)
            {
                len = max(len,j-i+1);
            }
        }
    }
    return len;
}
// method two a Better solution which works for both negative,zeroes and positive numbers 
// with a TC:O(nlogn) SC:O(n)
int methodTwo(vector<int>&nums,int k)
{
    map<int,int>mpp;
    int sum = 0;
    int len = 0;
    for(int i=0;i<nums.size();i++)
    {
        sum+= nums[i];
        if(sum == k)
        {
            len = max(len ,i+1);
        }
        if(mpp.find(sum-k) != mpp.end())
        {
            len = max(len,i-mpp[sum-k]);
        }
        mpp[sum] = i;
    }
    return len;

}

// method Three is the optimal solution which works only if array has positive and zeroes 
// TC:O(2n) SC:O(1)
int methodThree(vector<int>&nums,int k)
{
    int left = 0;
    int right = 0;
    int sum = nums[0];
    int maxLen = 0;
    
    while(right < nums.size())
    {
        while(left<=right and sum > k)
        {
            sum -= nums[left];
            left++;
        }
        if(sum == k)
        {
            maxLen = max(maxLen,right-left+1);
        }
        right++;
        if(right<nums.size())sum+=nums[right];
    }
    return maxLen;
}


int main()
{
    vector<int>nums = {1,1,2,3,1,1,1,1,4};
    int k = 4;
    // int ans = methodOne(nums,k);
    // int ans = methodTwo(nums,k);
    int ans = methodThree(nums,k);
    cout<<"The longest subarray with sum k is "<<ans<<endl;
    return 0;
}