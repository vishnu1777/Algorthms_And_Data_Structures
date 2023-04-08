#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order,
// we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

// Input: n = 3, k = 3
// Output: "213"

void permutationSequence(int n, int k)
{
    int fact = 1;
    vector<int> nums;
    for (int i = 1; i < n; i++)
    {
        fact *= i;
        nums.push_back(i);
    }
    nums.push_back(n);

    k = k - 1; // because nums have elements in 0 based indexing
    string ans = "";
    while (true)
    {
        ans += to_string(nums[k / fact]);
        nums.erase(nums.begin() + k / fact);
        if (nums.size() == 0)
            break;
        k %= fact;
        fact /= nums.size();
    }
    cout << ans << endl;
}

int main()
{

    int n = 4;
    int k = 9;
    permutationSequence(n, k);
    return 0;
}