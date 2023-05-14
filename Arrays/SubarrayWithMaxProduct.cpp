#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;




int getMaxProd(vector<int>&nums)
{
    int n = nums.size();
    int prefix = 1;
    int suffix = 1;
    int maxi = -1e9;
    for(int i=0;i<n;i++)
    {
        if(prefix == 0) prefix =1;
        if(suffix == 0)suffix = 1;

        prefix = prefix*nums[i];
        suffix = suffix*nums[n-i-1];

        maxi = max(maxi,max(prefix,suffix));
    }
    return maxi;

}






int main()
{
    vector<int>nums = {-2,3,-4,0};
    cout<<getMaxProd(nums)<<endl;
    return 0;
}