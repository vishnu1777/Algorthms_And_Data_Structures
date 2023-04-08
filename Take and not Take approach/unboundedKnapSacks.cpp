#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int func(int idx, vector<int> &weights, vector<int> &value, int maxWeight, vector<vector<int>> &dp)
{

    if (idx == 0)
    {
        if (maxWeight % weights[idx] == 0)
            return (maxWeight / weights[idx]) * value[0];
        return -1e9;
    }
    if (dp[idx][maxWeight] != -1)
        return dp[idx][maxWeight];

    int notTake = 0 + func(idx - 1, weights, value, maxWeight, dp);
    int take = -1e9;
    if (weights[idx] <= maxWeight)
        take = value[idx] + func(idx, weights, value, maxWeight - weights[idx], dp);
    return dp[idx][maxWeight] = max(take, notTake);
}
int tabulation(vector<int> &weights, vector<int> &value, int maxWeight)
{
    int n = weights.size();
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1));
    for (int i = 0; i <= maxWeight; i++)
    {
        if (i % weights[0] == 0)
            dp[0][i] = (i / weights[0]) * value[0];
        else
            dp[0][i] = -1e8;
    }

    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int notTake = 0 + dp[i - 1][w];
            int take = -1e8;
            if (weights[i] <= w)
                take = value[i] + dp[i][w - weights[i]];
            dp[i][w] = max(take, notTake);
        }
    }
    return dp[n - 1][maxWeight];
}
int tabulationSpace(vector<int> &weights, vector<int> &value, int maxWeight)
{
    int n = weights.size();
    vector<int> prev(maxWeight + 1), curr(maxWeight + 1);
    for (int i = 0; i <= maxWeight; i++)
    {
        if (i % weights[0] == 0)
            prev[i] = (i / weights[0]) * value[0];
        else
            prev[i] = -1e8;
    }

    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int notTake = 0 + prev[w];
            int take = -1e8;
            if (weights[i] <= w)
                take = value[i] + curr[w - weights[i]];
            curr[w] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[maxWeight];
}
int tabulationSpace1D(vector<int> &weights, vector<int> &value, int maxWeight)
{
    int n = weights.size();
    vector<int> prev(maxWeight + 1);
    for (int i = 0; i <= maxWeight; i++)
    {
        if (i % weights[0] == 0)
            prev[i] = (i / weights[0]) * value[0];
        else
            prev[i] = -1e8;
    }

    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int notTake = 0 + prev[w];
            int take = -1e8;
            if (weights[i] <= w)
                take = value[i] + prev[w - weights[i]];
            prev[w] = max(take, notTake);
        }
    }
    return prev[maxWeight];
}

int maxProfit(vector<int> &weights, vector<int> &value, int maxWeight)
{
    int n = weights.size();
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    // return func(n - 1, weights, value, maxWeight, dp);
    // return tabulation(weights, value, maxWeight);
    // return tabulationSpace(weights, value, maxWeight);
    return tabulationSpace1D(weights, value, maxWeight);
}

int main()
{

    vector<int> value = {5, 11, 13};
    vector<int> weights = {2, 4, 6};
    int w = 10;
    cout << maxProfit(weights, value, w) << endl;
    return 0;
}