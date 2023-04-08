#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int timeOptimizedAndPrint(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp1(n, 1);
    vector<int> dp2(n, 1);
    int maxi = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] and 1 + dp1[j] > dp1[i])
            {
                dp1[i] = 1 + dp1[j];
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[i] > arr[j] and 1 + dp2[j] > dp2[i])
            {
                dp2[i] = 1 + dp2[j];
            }
        }
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }

    return maxi;
}
int main()
{

    vector<int> nums = {1, 2, 1, 2, 1};
    cout << timeOptimizedAndPrint(nums) << endl;
    return 0;
}