#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int func(int n, vector<int> &dp)
{
    if (n == 0)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    if (n == 1 || n == 2)
        return n;

    return dp[n] = func(n - 1, dp) + func(n - 2, dp);
}
int tabulation(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int fib(int n)
{
    vector<int> dp(n + 1, -1);
    // return func(n, dp);
    return tabulation(n);
}

int main()
{

    int n = 7;
    cout << fib(n) << endl;
    return 0;
}