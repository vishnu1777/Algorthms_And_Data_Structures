#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int throughMap(vector<int>&nums)
{
    map<int,int>maps;
    for(auto n:nums)
    {
        maps[n]++;
    }
    for(auto it:maps)
    {
        if(it.second == 1)return it.first;
    }
    return -1;
}

int throughXor(vector<int>&nums)
{
    int xor1 = 0;
    for(auto n:nums)
    {
        xor1 = xor1 ^ n;
    }
    return xor1;
}

int main()
{
    vector<int>nums = {1,1,2,3,3,4,4};
    // int ans = throughMap(nums);
    int ans = throughXor(nums);
    cout<<"The number appear once is "<<ans<<endl;
    return 0;
}