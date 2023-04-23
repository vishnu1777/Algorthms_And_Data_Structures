#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;


vector<int>alterArray(vector<int>&nums)
{
    int posIndex = 0,negIndex =1;

    vector<int>ans(nums.size());
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]<0)
        {
            ans[negIndex] = nums[i];
            negIndex+=2;
        }
        else
        {
            ans[posIndex] = nums[i];
            posIndex+=2;
        }
    }
    return ans;
}

void alterArrayVariety2(vector<int>&nums)
{
    int n = nums.size();
    vector<int>pos,neg;

    for(int i=0;i<n;i++)
    {
        if(nums[i]<0)
        {
            neg.push_back(nums[i]);
        }
        else
        {
            pos.push_back(nums[i]);
        }
    }

    if(pos.size() > neg.size())
    {
        for(int i=0;i<neg.size();i++)
        {
            nums[2*i] = pos[i];
            nums[2*i+1] = neg[i];
        }
        int lastIndex = 2*neg.size();
        for(int i=neg.size();i<pos.size();i++)
        {
            nums[lastIndex] = pos[i];
            lastIndex++;
        }
    }
    else
    {
          for(int i=0;i<pos.size();i++)
        {
            nums[2*i] = pos[i];
            nums[2*i+1] = neg[i];
        }
        int lastIndex = 2*pos.size();
        for(int i=pos.size();i<neg.size();i++)
        {
            nums[lastIndex] = neg[i];
            lastIndex++;
        }    
    }

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

    // array for all pos and negs
    // vector<int>nums = {3,1,-2,-5,2,-4};
    // array for (pos may > neg) or (neg may >pos)
    vector<int>nums = {-1,2,3,4,-3,1 };
    // vector<int>ans = alterArray(nums);
    alterArrayVariety2(nums);
    display(nums);
    return 0;


}