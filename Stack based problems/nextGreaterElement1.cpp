#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
using namespace std;
// The next greater element of some element x in an array is the
//  first greater element that is to the right of x in the same array.

// You are given two distinct 0-indexed integer arrays nums1 and nums2, 
// where nums1 is a subset of nums2.

// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and 
// determine the next greater element of nums2[j] in nums2. If there is no next greater element,
//  then the answer for this query is -1.

// Return an array ans of length nums1.length such that ans[i]

//  is the next greater element as described above.
// Explanation: The next greater element for each value of nums1 is as follows:
// - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
// - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
void nge(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    unordered_map<int, int> map;
    stack<int> s;
    vector<int> ans(n);
    for (int i = 0; i < nums2.size(); i++)
    {
        while (!s.empty() and s.top() <= nums2[i])
        {
            map[s.top()] = nums2[i];
            s.pop();
        }
        s.push(nums2[i]);
    }

    for (int i = 0; i < nums1.size(); i++)
    {
        if (map.find(nums1[i]) != map.end())
            ans[i] = map[nums1[i]];
        else
            ans[i] = -1;
    }
    for (int n : ans)
    {
        cout << n << " ";
    }
}

int main()
{

    vector<int> nums1 = {2, 4};
    vector<int> nums2 = {1, 2, 3, 4};
    nge(nums1, nums2);
    return 0;
}
