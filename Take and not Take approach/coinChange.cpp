// You are given an integer array coins representing coins of different denominations
// and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount.
// If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.
// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int func(int idx, vector<int> &coins, int amount, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if (amount % coins[0] == 0)
            return amount / coins[idx];
        else
            return 1e8;
    }
    if (dp[idx][amount] != -1)
        return dp[idx][amount];

    int notTake = 0 + func(idx - 1, coins, amount, dp);
    int take = 1e9;
    if (coins[idx] <= amount)
    {
        take = 1 + func(idx, coins, amount - coins[idx], dp);
    }
    return dp[idx][amount] = min(take, notTake);
}
int tabulation(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1));
    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
            dp[0][i] = i / coins[0];
        else
            dp[0][i] = 1e9;
    }

    for (int i = 1; i < n; i++)
    {
        for (int am = 0; am <= amount; am++)
        {
            int notTake = 0 + dp[i - 1][am];
            int take = 1e8;
            if (coins[i] <= am)
            {
                take = 1 + dp[i][am - coins[i]];
            }
            dp[i][am] = min(take, notTake);
        }
    }
    return dp[n - 1][amount];
}
int tabulationSpace(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int> prev(amount + 1), curr(amount + 1);
    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
            prev[i] = i / coins[0];
        else
            prev[i] = 1e9;
    }

    for (int i = 1; i < n; i++)
    {
        for (int am = 0; am <= amount; am++)
        {
            int notTake = 0 + prev[am];
            int take = 1e8;
            if (coins[i] <= am)
            {
                take = 1 + curr[am - coins[i]];
            }
            curr[am] = min(take, notTake);
        }
        prev = curr;
    }
    return prev[amount];
}
int tabulationSpace2Vect(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int> prev(amount + 1), curr(amount + 1);
    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
            prev[i] = i / coins[0];
        else
            prev[i] = 1e9;
    }

    for (int i = 1; i < n; i++)
    {
        for (int am = 0; am <= amount; am++)
        {
            int notTake = 0 + prev[am];
            int take = 1e8;
            if (coins[i] <= am)
            {
                take = 1 + curr[am - coins[i]];
            }
            curr[am] = min(take, notTake);
        }
        prev = curr;
    }
    return prev[amount];
}
int tabulationSpace1Vect(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int> prev(amount + 1);
    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
            prev[i] = i / coins[0];
        else
            prev[i] = 1e9;
    }

    for (int i = 1; i < n; i++)
    {
        for (int am = 0; am <= amount; am++)
        {
            int notTake = 0 + prev[am];
            int take = 1e8;
            if (coins[i] <= am)
            {
                take = 1 + prev[am - coins[i]];
            }
            prev[am] = min(take, notTake);
        }
    }
    return prev[amount];
}
int minimumAmount(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    // return func(n - 1, coins, amount, dp);
    // return tabulation(coins, amount);
    return tabulationSpace1Vect(coins, amount);
}

int main()
{

    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << minimumAmount(coins, amount);
    return 0;
}