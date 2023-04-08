#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>&nums)
{
    int j=-1;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i] == 0)
        {
            j = i;
            break;
        }
    }

    for(int i=j+1;i<nums.size();i++)
    {
        if(nums[i]!=0)
        {
            nums[j] = nums[i];
            j++;
        }
    }
    for(int i=j;i<nums.size();i++)
    {
        nums[i] = 0;
    }
}

void display(vector<int>nums)
{
    for(auto n:nums)
    {
        cout<<n<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int>nums = {1,0,2,3,2,0,0,4,5,1};
    solve(nums);
    display(nums);
    return 0;
}