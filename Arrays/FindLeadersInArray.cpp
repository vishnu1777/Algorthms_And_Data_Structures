#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;


vector<int>getLeaders(vector<int>&nums)
{
    int maxi = -1e9;
    int n = nums.size();
    vector<int>ans;
    for(int i=n-1;i>=0;i--)
    {
        if(nums[i]>maxi)
        {
            maxi = nums[i];
            ans.push_back(nums[i]);
        }
    }
    return ans;
}



void display(vector<int>&nums)
{
    for(auto n:nums)
    {
        cout<<n<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> nums = {10,22,12,3,0,6};
    vector<int>ans = getLeaders(nums);
    display(ans);

    return 0;
}