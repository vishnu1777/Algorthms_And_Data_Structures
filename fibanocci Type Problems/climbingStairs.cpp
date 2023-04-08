#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int func(int n,vector<int>&dp)
{
    if(n == 0)return 1;
    if(n<0)return 0;
    if(dp[n]!=-1)return dp[n];

    return dp[n]= func(n-1,dp)+func(n-2,dp);
}
int tabulation(int n)
{
    vector<int>dp(n+1);
    dp[0] =1;
    for(int i=1;i<=n;i++)
    {
        if(i==1)dp[i] = 1;
        else dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int variableApproach(int n)
{
    if(n == 0)return 1;
    if(n==1 || n==2)return n;
    int prev2 = 1;
    int prev = 2;
    for(int i=3;i<=n;i++)
    {
        int curr = prev2+prev;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
int climbingStairs(int n)
{
    vector<int>dp(n+1,-1);
    // return func(n,dp);
    // return tabulation(n);
    return variableApproach(n);
}


int main()
{

    int n = 4;
    int ans  = climbingStairs(n);
    cout<<ans<<endl;
    return 0;
}