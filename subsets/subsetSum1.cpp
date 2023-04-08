#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void func(int idx, vector<int> &nums, vector<int> &ans, int sum)
{
    if (idx < 0)
    {
        ans.push_back(sum);
        return;
    }

    sum += nums[idx];
    func(idx - 1, nums, ans, sum);
    sum -= nums[idx];
    func(idx - 1, nums, ans, sum);
}
void func1(int idx, vector<int> &nums, vector<int> &ans, int sum)
{
    ans.push_back(sum);

    for (int i = idx; i >= 0; i--)
    {
        sum += nums[i];
        func1(i - 1, nums, ans, sum);
        sum -= nums[i];
    }
}

void subset(int idx, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans)
{

    ans.push_back(temp);

    for (int i = idx; i < nums.size(); i++)
    {
        if (i != idx and nums[i] == nums[i - 1])
            continue;
        temp.push_back(nums[i]);
        subset(i + 1, nums, temp, ans);
        temp.pop_back();
    }
}

void generateSubsetSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    int sum = 0;
    vector<vector<int>> res;
    // func1(n-1,nums,ans,sum);
    subset(0, nums, ans, res);
    // for(int n:ans)
    // {
    //     cout<<n<<" ";
    // }
    for (vector<int> n : res)
    {
        for (int num : n)
        {
            cout << num << "  ";
        }
        cout << endl;
    }
}

int main()
{

    vector<int> nums = {1, 2, 2};
    generateSubsetSum(nums);
    return 0;
}