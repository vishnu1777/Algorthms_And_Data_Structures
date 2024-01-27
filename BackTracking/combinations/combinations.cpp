// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
// You may return the answer in any order.

// Input: n = 4, k = 2
// Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
// Explanation: There are 4 choose 2 = 6 total combinations.
// Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
#include <stdio.h>

#include <iostream>
#include <vector>
using namespace std;
void func(int idx, int curr, int n, int k, vector<vector<int>> &res, vector<int> &temp)
{
    if (curr == k)
    {
        res.push_back(temp);
        return;
    }

    for (int i = idx; i < n; i++)
    {
        temp.push_back(i + 1);
        func(i + 1, curr + 1, n, k, res, temp);
        temp.pop_back();
    }
}

void combinations(int &n, int &k)
{
    vector<int> temp;
    vector<vector<int>> res;
    func(0, 0, n, k, res, temp);

    for (int i = 0; i < k + n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << res[i][j];
        }
        cout << " ";
    }
}

int main()
{

    int n, k;
    cout << "enter the range:" << endl;
    cin >> n;
    cout << "enter the combination range k:" << endl;
    cin >> k;
    combinations(n, k);

    return 0;
}