#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int mod = 1000000007;
int func(int i, int j, string s, int isTrue, vector<vector<vector<long long>>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    long long ways = 0;
    for (int idx = i + 1; idx < j; idx += 2)
    {
        long long LT = func(i, idx - 1, s, 1, dp);
        long long LF = func(i, idx - 1, s, 0, dp);
        long long RT = func(idx + 1, j, s, 1, dp);
        long long RF = func(idx + 1, j, s, 0, dp);

        if (s[idx] == '&')
        {
            if (isTrue)
                ways = (ways + (LT * RT) % mod) % mod;
            else
                ways = (ways + (LT * RF) % mod + (LF * RT) % mod + (LF * RF) % mod) % mod;
        }
        else if (s[idx] == '|')
        {
            if (isTrue)
                ways = (ways + (LT * RT) % mod + (LT * RF) % mod + (LF * RT) % mod) % mod;
            else
                ways = (ways + (LF * RF)) % mod;
        }
        else
        {
            if (isTrue)
                ways = (ways + (LT * RF) % mod + (RT * LF) % mod) % mod;
            else
                ways = (ways + (LT * RT) % mod + (LF * RF) % mod) % mod;
        }
    }
    return dp[i][j][isTrue] = ways;
}

int noOfWays(string &s)
{
    int n = s.size();
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
    return func(0, n - 1, s, 1, dp);
}

int main()
{

    string s = "F|T^F";
    cout << noOfWays(s) << endl;
    return 0;
}