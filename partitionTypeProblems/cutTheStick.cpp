// Given a wooden stick of length n units.
//  The stick is labelled from 0 to n.
//  For example, a stick of length 6 is labelled as follows:

// Given an integer array cuts where cuts[i]
// denotes a position you should perform a cut at.

// You should perform the cuts in order,
//  you can change the order of the cuts as you wish.

// The cost of one cut is the length of the stick to be cut,
// the total cost is the sum of costs of all cuts.
//  When you cut a stick, it will be split into two smaller sticks
//  (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

// Return the minimum total cost of the cuts.

// Input: n = 7, cuts = [1,3,4,5]
// Output: 16
// Explanation: Using cuts order = [1, 3, 4, 5]
//  as in the input leads to the following scenario:
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int func(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    long long mini = 1e9;
    for (int k = i; k <= j; k++)
    {
        long long cost = cuts[j + 1] - cuts[i - 1] + func(i, k - 1, cuts, dp) + func(k + 1, j, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}

int getMinCost(int n, vector<int> &cuts)
{
    int N = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));

    return func(1, N, cuts, dp);
}

int main()
{

    vector<int> cuts = {1, 3, 4, 5};
    int n = 7;
    cout << getMinCost(n, cuts) << endl;

    return 0;
}