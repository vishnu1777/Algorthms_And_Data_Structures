#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int func(int idx, vector<int> &nums)
{
    if (idx == 0)//this condition is because when a frog is at destination the energy that costs is 0
        return 0;

    int oneJump = abs(nums[idx] - nums[idx - 1]) + func(idx - 1, nums);
    int twoJump = INT_MAX;
    if (idx > 1)
    {
        twoJump = abs(nums[idx] - nums[idx - 2]) + func(idx - 2, nums);
    }
    return min(oneJump, twoJump);
}

int frogJump(vector<int> &nums)
{
    int n = nums.size();
    return func(n - 1, nums);
}

int main()
{

    vector<int> nums = {10, 20, 30, 10};
    cout << frogJump(nums) << endl;
    return 0;
}