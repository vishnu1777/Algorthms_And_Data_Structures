#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

// Given an array of intervals where intervals[i] = [starti, endi], 
// merge all overlapping intervals, and return an array of the non-overlapping intervals 
// that cover all the intervals in the input.

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

vector<vector<int>>mergetIntervalBetter(vector<vector<int>>&arr)
{
    //TC:0(2n) + nlogn 
    int n = arr.size();
	sort(arr.begin(),arr.end());
	vector<vector<int>>ans;
        for (int i = 0; i < n; i++) {
          int start = arr[i][0];
          int end = arr[i][1];

          if (!ans.empty() and end <= ans.back()[1])continue;

            for (int j = i + 1; j < n; j++)
			{
				if(arr[j][0] <= end)
				{
					end = max(end,arr[j][1]);
					
				}
				else
				{
					break;
				}
			}
			ans.push_back({start,end});
        }
	return ans;
}


vector<vector<int>>mergetIntervalOptimal(vector<vector<int>>&arr)
{
    // TC:0(n) + nlogn
    int n = arr.size();
	sort(arr.begin(),arr.end());
	vector<vector<int>>ans;
    
    for(int i=0;i<n;i++)
    {
        if(ans.empty() || ans.back()[1] < arr[i][0])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1],arr[i][1]);
        }
    }

	return ans;
}

void display(vector<vector<int>>&nums)
{
    for(auto it:nums)
    {
        cout<<it[0]<<" "<<it[1]<<endl;
    }
}


int main()
{

    vector<vector<int>>interval =  {{1,4},{4,5}};
    // vector<vector<int>>ans = mergetIntervalBetter(interval);
    vector<vector<int>>ans = mergetIntervalOptimal(interval);

    display(ans);
    return 0;
}