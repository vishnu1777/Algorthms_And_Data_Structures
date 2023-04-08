#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
bool isPalindrome(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}

int func(int i, string &s, vector<int> &dp)
{

    if (i == s.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int mini = 1e9;
    for (int j = i; j < s.size(); j++)
    {
        if (isPalindrome(i, j, s))
        {
            int cuts = 1 + func(j + 1, s, dp);
            mini = min(mini, cuts);
        }
    }
    return dp[i] = mini;
}

int NoOfPartition(string &s)
{
    int n = s.size();
    vector<int> dp(n, -1);
    return func(0, s, dp) - 1;
}

int main()
{

    string s = "ab";
    cout << NoOfPartition(s) << endl;
    return 0;
}