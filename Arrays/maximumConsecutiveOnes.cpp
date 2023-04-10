#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int consecutive(vector<int>&nums)
{
    int count = 0;
    int maxi = -1;

    for(auto n:nums)
    {
        if(n == 1)
        {
            count++;
            maxi = max(maxi,count);
        }
        else{
            count = 0;
        }
        
    }
    return maxi;
}

int main()
{
    vector<int>nums = {1,1,2,3,3,1,1,1,1};
    cout<<"Max consecutive ones is "<<consecutive(nums)<<endl;
    return 0;
}