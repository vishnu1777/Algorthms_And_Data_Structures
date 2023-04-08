#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// rotate array by one place
void rotateOnePlace(vector<int>&arr)
{
    int temp = arr[0];
    for(int i=1;i<arr.size();i++)
    {
        arr[i-1] = arr[i];
    }
    arr[arr.size()-1] = temp;
    
}



// display
void display(vector<int>&arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}



// rotate array by k place
void rotateKPlace(vector<int>&nums,int k)
{
    // brute
    vector<int>temp;
    for(int i=0;i<k;i++)
    {
        temp.push_back(nums[i]);
    }
    for(int i=k;i<nums.size();i++)
    {
        nums[i-k] = nums[i];
    }

    for(int i= nums.size()-k;i<nums.size();i++)
    {
        nums[i] = temp[i-(nums.size()-k)];
        
    }
    

    // optimal 
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
    reverse(nums.begin(),nums.end());
}


int main()
{
    vector<int>arr  = {1,2,3,4,5,6,7,8};
    // rotateOnePlace(arr);
    // display(arr);
    // arr = {1,2,3,4,5,6,7,8};
    rotateKPlace(arr,3);
    display(arr);

    return 0;

}