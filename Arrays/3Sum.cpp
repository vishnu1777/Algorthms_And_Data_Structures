#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;


// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
// such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// ex 1 :Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.


vector<vector<int>>getTripletesBetter(vector<int>&nums)
{
   // TC:0(n^2)+0(logn)
   // SC:0(n)
    int n = nums.size();
    set<vector<int>>st;

    for(int i=0;i<n;i++)
    {
        set<int>s;
        for(int j=i+1;j<n;j++)
        {
            int rem = -(nums[i]+nums[j]);
            if(s.count(rem))
            {
                vector<int>temp = {nums[i],nums[j],rem};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            s.insert(nums[j]);
        }
    }
     vector<vector<int>>ans(st.begin(),st.end());



    return ans;
}

vector<vector<int>>getTripletesOptimal(vector<int>&nums){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>>ans;

    for(int i=0;i<n;i++)
    {
        int tar = -nums[i];
        int front = i+1;
        int back = n-1;

        while(front < back)
        {
            int sum = nums[front] + nums[back];
            if(sum < tar)
            {
                front++;
            }
            else if(sum > tar) 
            {
                back--;
            }
            else
            {
                vector<int>temp = {nums[i],nums[front],nums[back]};
                ans.push_back(temp);
                while(front < back and nums[front] == temp[1])front++;
                while(front < back and nums[back] == temp[2])back--;
            }
        }
        while(i+1 < n and nums[i] == nums[i+1])i++;
    }
    return ans;

}







void display(vector<vector<int>>&nums)
{
    for(auto it:nums)
    {
        cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
    }
}



int main()
{
    vector<int>nums = {-1,0,1,2,-1,-4};
    // vector<vector<int>>ans = getTripletesBetter(nums);
    vector<vector<int>>ans = getTripletesOptimal(nums);

    display(ans);
    return 0;
}