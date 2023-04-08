// Find all valid combinations of k numbers that sum up to
// n such that the following conditions are true:

// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations.
// The list must not contain the same combination twice,
// and the combinations may be returned in any order.
// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
void func(int idx, int curr, int k, vector<vector<int>> &res, vector<int> &temp, int n)
{
    if (curr == k)
    {
        if (n == 0)
        {
            res.push_back(temp);
            return;
        }
        return;
    }

    for (int i = idx; i <= 9; i++)
    {
        if (i <= n)
        {
            temp.push_back(i);
            func(i + 1, curr + 1, k, res, temp, n - i);
            temp.pop_back();
        }
    }
}

void combination(int &n, int &k)
{
    vector<vector<int>> res;
    vector<int> temp;
    func(1, 0, k, res, temp, n);

    for (vector<int> num : res)
    {
        for (int n : num)
        {
            cout << n << " ";
        }
        cout << " ";
    }
}

int main()
{

    int n;
    cout << "enter the sum:" << endl;
    cin >> n;
    int k;
    cout << "enter the number of combinations K:" << endl;
    cin >> k;
    combination(n, k);

    return 0;
}