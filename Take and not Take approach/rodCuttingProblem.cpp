#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int func(int idx, vector<int> &prices, int n)
{
    if (idx == 0)
    {
        if (1 <= n)
            return n * prices[0];
        else
            return 0;
    }

    int notTake = 0 + func(idx - 1, prices, n);
    int take = INT_MIN;
    int rodLength = idx + 1;
    if (rodLength <= n)
        take = prices[idx] + func(idx, prices, n - rodLength);
    return max(take, notTake);
}
int tabulation(vector<int> &prices)
{
    int N = prices.size();
    vector<vector<int>> dp(N, vector<int>(N + 1));
    for (int i = 0; i <= N; i++)
    {
        if (1 <= i)
            dp[0][i] = i * prices[0];
    }

    for (int i = 1; i < N; i++)
    {
        for (int length = 0; length <= N; length++)
        {
            int notTake = 0 + dp[i - 1][length];
            int take = INT_MIN;
            int rodlength = i + 1;
            if (rodlength <= length)
                take = prices[i] + dp[i][length - rodlength];
            dp[i][length] = max(take, notTake);
        }
    }
    return dp[N - 1][N];
}

int maxCost(vector<int> &prices)
{
    int n = prices.size();
    // return func(n - 1, prices, n);
    return tabulation(prices);
}

int main()
{
    vector<int> prices = {3, 5, 6, 7, 10, 12};
    cout << maxCost(prices) << endl;
    return 0;
}