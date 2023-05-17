#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int>&nums,vector<int>&temp,int low ,int mid, int high)
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
            cnt+= mid -i +1;
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
    return cnt;
}


int mergeSort(vector<int>&nums,vector<int>&temp,int low,int high)
{
    int count = 0;
    if(low < high)
    {
    int mid = (low+high)/2;
    count += mergeSort(nums,temp,low,mid);
    count += mergeSort(nums,temp,mid+1,high);
    count+= merge(nums,temp,low,mid,high);
    }
  
    return count;
}


int getInversion(vector<int>&nums)
{
    int n = nums.size();
    vector<int>temp(n);
    return mergeSort(nums,temp,0,n-1);
}






int main()
{
    vector<int>nums ={5,3,2,1,4};
    cout<<getInversion(nums)<<endl;
}
