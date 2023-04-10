#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;

int missing(vector<int>&nums)
{
    // int n = nums.size()+1;
    // int tot = n*(n+1)/2;
   
    // int sum = 0;
    // for(auto n:nums)
    // {
    //     sum+= n;
    // }
  
    // return tot-sum;
    int xor1 = 0;
    int xor2 = 0;
    for(int i=1;i<=nums.size()+1;i++)
    {
        xor1 = xor1 ^ i;
    }
    for(auto n:nums)
    {
        xor2 = xor2 ^ n;
    }
    return xor1 ^ xor2;
}
int main()
{
    vector<int>nums = {1,2,4,5};
    cout<<"The missing number is "<<missing(nums)<<endl;
   
    return 0;
}