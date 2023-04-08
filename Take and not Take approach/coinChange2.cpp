#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
// You are given an integer array coins representing coins of

// different denominations and an integer amount representing a
// total amount of money.

// Return the number of combinations that make up that amount.
//  If that amount of money cannot be made up by any combination of the coins, return 0.

// You may assume that you have an infinite number of each kind of coin.

// The answer is guaranteed to fit into a signed 32-bit integer.

int func(int idx, vector<int> &coins, int amount)
{
    if (idx == 0)
    {
        if (amount % coins[idx] == 0)
            return 1;
        else
            return 0;
    }

    int notTake = func(idx - 1, coins, amount);
    int take = 0;
    if (coins[idx] <= amount)
    {
        take = func(idx, coins, amount - coins[idx]);
    }

    return take + notTake;
}

int NoOfCombos(vector<int> &coins, int amount)
{
    int n = coins.size();
    return func(n - 1, coins, amount);
}

int main()
{

    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << NoOfCombos(coins, amount) << endl;

    return 0;
}