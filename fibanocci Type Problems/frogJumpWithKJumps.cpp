#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
// Problem Statement
// There are N stones, numbered 1,2,…,N. For each i (1≤i≤N),
//  the height of Stone i is h
// i
// ​
//  .

// There is a frog who is initially on Stone 1.
// He will repeat the following action some number of times to reach Stone N:

// If the frog is currently on Stone i, jump to one of the following:
//  Stone i+1,i+2,…,i+K. Here, a cost of energy
// i
// ​
//  −h
// j
// ​
//  ∣ is incurred, where j is the stone to land on.
// Find the minimum possible total cost incurred before the frog reaches Stone N.

int func(int i, vector<int> &nums, int k)
{
    if (i == 0)
        return 0;
    int minJumps = INT_MAX;

    for (int j = 1; j <= k; j++)
    {
        if (i - j >= 0)
        { // abs(num[i]+abs(num[i] - nums[i-j]))
            // this means if the frog is jumping then the energy consumed by the frog is nums[i] - nums[i-j]
            minJumps = min(minJumps, func(i - j, nums, k) + abs(nums[i] - nums[i - j]));
        }
    }
    return minJumps;
}

int minJumps(vector<int> &nums, int k)
{
    int n = nums.size();
    // return func(n - 1, nums, k);
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int minJumps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                minJumps = min(minJumps, dp[i - j] + abs(nums[i] - nums[i - j]));
            }
        }
        dp[i] = minJumps;
    }
    return dp[n - 1];
}

int main()
{

    vector<int> array = {30, 10, 60, 10, 60, 50};
    int k;
    cout << "enter the number of jumps can a frog make:" << endl;
    cin >> k;
    int ans = minJumps(array, k);
    cout << "the min jump the frog can make is:" << ans << endl;

    return 0;
}