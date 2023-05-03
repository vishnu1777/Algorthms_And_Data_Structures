#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

// Given an array nums of n integers, return an array of all the 
// unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.


// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]


// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]



vector<vector<int>>getQuadTripletesBetter(vector<int>&nums,int tar)
{
    set<vector<int>>st;
    int n = nums.size();

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            set<int>s;
            for(int k=j+1;k<n;k++)
            {
                int sum = nums[i] + nums[k] + nums[j];
                int fourth = tar - sum;
                
                if(s.count(fourth))
                {
                    vector<int>temp = {nums[i],nums[j],nums[k],fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                s.insert(nums[k]);
            }
        }
    }   
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;

}

vector<vector<int>>getQuadTripletesOptimal(vector<int>&nums,int tar)
{
    sort(nums.begin(),nums.end());
    int n = nums.size();
    vector<vector<int>>ans;
    for(int i=0;i<n;i++)
    {
        int tar3 = tar - nums[i];
        for(int j= i+1 ;j<n;j++)
        {
            int tar2 = tar3 - nums[j];
            int front = j+1;
            int back = n-1;

            while(front < back)
            {
                int sum = nums[front] + nums[back];
                if(sum < tar2)front++;
                else if(sum > tar2)back--;
                else
                {
                    vector<int>temp = {nums[i],nums[j],nums[front],nums[back]};
                    ans.push_back(temp);

                    while(front < back and nums[front] == temp[2])front++;
                    while(front < back and nums[back] == temp[3])back--;
                }
            }
            while(j+1 < n and nums[j] == nums[j+1])j++;
            
        }
        while(i+1 < n and nums[i+1] == nums[i])i++;
    }
    return ans;
}

void display(vector<vector<int>>&nums)
{
    for(auto it:nums)
    {
        cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<" "<<it[3]<<endl;
    }
}




int main()
{
    vector<int>nums = {1,0,-1,0,-2,2};
    int tar = 0;

    // vector<vector<int>>ans = getQuadTripletesBetter(nums,tar);
    vector<vector<int>>ans = getQuadTripletesOptimal(nums,tar);

    display(ans);
    return 0;
}