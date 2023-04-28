// Count Subarray sum Equals K
// Problem Statement: Given an array of integers and an integer k,
// return the total number of subarrays whose sum equals k.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Examples:

// Example 1:
// Input Format: N = 4, array[] = {3, 1, 2, 4}, k = 6
// Result: 2
// Explanation: The subarrays that sum up to 6 are [3, 1, 2] and [2, 4].

// Example 2:
// Input Format: N = 3, array[] = {1,2,3}, k = 3
// Result: 2
// Explanation: The subarrays that sum up to 3 are [1, 2], and [3].
#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;


int findAllSubarraysWithGivenSum(vector<int>&nums,int k)
{
    // TC:0(n^2) SC:0(1)
    int cnt = 0;

    // for(int i=0;i<nums.size();i++)
    // {
    //     int sum = 0;
    //     for(int j=i;j<nums.size();j++)
    //     {
    //         sum+= nums[j];
    //         if(sum == k)cnt++;
    //     }
        
    // }
    // Solution 1 ends here
    // TC:0(n) SC:0(n)
    unordered_map<int,int>map;
    int pSum = 0;
    map[0] = 1;
    for(int i=0;i<nums.size();i++)
    {
        pSum += nums[i];
        int remove = pSum - k;
        cnt += map[remove];
        map[pSum] += 1;
    }


    return cnt;

}


int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}