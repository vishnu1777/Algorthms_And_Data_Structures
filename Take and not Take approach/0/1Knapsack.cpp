#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int func(int idx, vector<int> &weights, vector<int> &value, int maxWeight, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if (weights[idx] <= maxWeight)
        {
            return value[idx];
        }
        else
            return 0;
    }

    if (dp[idx][maxWeight] != -1)
        return dp[idx][maxWeight];
    int notTake = 0 + func(idx - 1, weights, value, maxWeight, dp);
    int pick = INT_MIN;
    if (weights[idx] <= maxWeight)
    {
        pick = value[idx] + func(idx - 1, weights, value, maxWeight - weights[idx], dp);
    }
    return dp[idx][maxWeight] = max(pick, notTake);
}
int tabulation(vector<int> &weights, vector<int> &value, int maxWeight)
{
    int n = weights.size();

    vector<vector<int>> dp(n, vector<int>(maxWeight + 1));
    for (int w = 0; w <= maxWeight; w++)
        dp[0][w] = value[0];

    for (int i = 1; i < n; i++)
    {
        for (int weight = 0; weight <= maxWeight; weight++)
        {

            int notTake = 0 + dp[i - 1][weight];
            int take = INT_MIN;
            if (weights[i] <= weight)
            {
                take = value[i] + dp[i - 1][weight - weights[i]];
            }
            dp[i][weight] = max(notTake, take);
        }
    }
    return dp[n - 1][maxWeight];
}
int tabulationSpace(vector<int> &weights, vector<int> &value, int maxWeight)
{
    int n = weights.size();
    vector<int> prev(maxWeight + 1), curr(maxWeight + 1);
    for (int w = 0; w <= maxWeight; w++)
        prev[w] = value[0];

    for (int i = 1; i < n; i++)
    {
        for (int weight = 0; weight <= maxWeight; weight++)
        {

            int notTake = 0 + prev[weight];
            int take = INT_MIN;
            if (weights[i] <= weight)
            {
                take = value[i] + prev[weight - weights[i]];
            }
            curr[weight] = max(notTake, take);
        }
        prev = curr;
    }
    return prev[maxWeight];
}
int tabulationSpace1D(vector<int> &weights, vector<int> &value, int maxWeight)
{
    int n = weights.size();
    vector<int> prev(maxWeight + 1);
    for (int w = 0; w <= maxWeight; w++)
        prev[w] = value[0];

    for (int i = 1; i < n; i++)
    {
        for (int weight = maxWeight; weight >= 0; weight--)
        {

            int notTake = 0 + prev[weight];
            int take = INT_MIN;
            if (weights[i] <= weight)
            {
                take = value[i] + prev[weight - weights[i]];
            }
            prev[weight] = max(notTake, take);
        }
    }
    return prev[maxWeight];
}
int maxVal(vector<int> &weights, vector<int> &value, int maxWeight)
{
    int n = weights.size();
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    // return func(n - 1, weights, value, maxWeight, dp);
    return tabulationSpace1D(weights, value, maxWeight);
}

int main()
{

    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};
    int w = 5;

    cout << maxVal(weight, value, w);

    return 0;
}