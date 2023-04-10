#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int secLargest(vector<int>&nums)
{
    int secLargest = -1;
    int largest = nums[0];
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]>largest)
        {
            secLargest = largest;
            largest = nums[i];
        }
        else if(nums[i]<largest and  nums[i] > secLargest)
        {
            secLargest = nums[i];
        }
    }
    return secLargest;
}



int main()
{
    vector<int>nums = {1,2,3,4,5};
    cout<<"The second largest is "<<secLargest(nums)<<endl;
    return 0;
}