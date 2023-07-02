#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;


void merge(vector<int>&nums,vector<int>&temp,int low ,int mid, int high)
{
    int i = low;
    int j = mid+1;
    int k = low;
    int cnt = 0;

    while((i<= mid) and j<=high)
    {
        if(nums[i]<=nums[j])
        {
            temp[k] = nums[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = nums[j];
           
            j++;k++;
        }
    }
    while(i<=mid)
    {
        temp[k] = nums[i];
        i++;k++;
    }
    while(j<=high)
    {
        temp[k] = nums[j];
        j++;k++;
    }
    for(int i=low;i<=high;i++)
    {
        nums[i] = temp[i];
    }
  
}

int revPairs(vector<int>&nums,int low,int mid,int high)
{
    int right = mid+1;
    int count = 0;
    int middd = mid+1;
    for(int i=0;i<=mid;i++)
    {   
        while(right <= high and nums[i] > 2*nums[right])right++;
        count+= right - middd;
       
    }
    return count;
}


int mergeSort(vector<int>&nums,vector<int>&temp,int low,int high)
{
    int count = 0;
    if(low < high)
    {
    int mid = (low+high)/2;
    count += mergeSort(nums,temp,low,mid);
    count += mergeSort(nums,temp,mid+1,high);
    count+= revPairs(nums,low,mid,high);
    merge(nums,temp,low,mid,high);
    }
  
    return count;
}


int getPairs(vector<int>&nums)
{
    int n = nums.size();
     vector<int>temp(n);
    return mergeSort(nums,temp,0,n-1);
}




int main()
{
    vector<int>nums = {2,4,3,5,1};
    cout<<getPairs(nums)<<endl;
}