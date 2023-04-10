#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

void display(vector<int>nums)
{
    for(auto n : nums)
    {
        cout<<n<<" ";
    }
    cout<<endl;
}

void removeDup(vector<int>&nums)
{
    int j = 0;
    for(int i=1;i<nums.size();i++)
    {
        if(nums[j]!=nums[i])
        {
            nums[j+1] = nums[i];
            j++;
        }
    }
}

int main()
{
    vector<int>nums = {1,1,2,3,3,4,4};
    removeDup(nums);
    display(nums);
    return 0;
}