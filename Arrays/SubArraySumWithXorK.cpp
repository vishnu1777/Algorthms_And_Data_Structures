#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int getCount(vector<int>&nums,int k)
{
    // TC:0(N) SC:0(N)
    map<int,int>mpp;
    mpp[0] = 1;
    int xo = 0;
    int cnt = 0;
    for(int i=0;i<nums.size();i++)
    {
        xo = xo ^ nums[i];
        int x = xo ^ k;
        cnt += mpp[x];
        mpp[xo]++;
    }
    return cnt;
}



int main()
{

    vector<int>nums = {4,2,2,6,4};
    int k = 6;
    cout<<"No of subarrays are:"<<getCount(nums,k)<<endl;
    return 0;

}