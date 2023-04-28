// Majority Elements(>N/3 times) | Find the elements that appears more than N/3 times in the array
// Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.


// Example 1:

// Input: N = 5, array[] = {1,2,2,3,2}

// Ouput: 2

// Explanation: Here we can see that the Count(1) = 1, Count(2) = 3 and Count(3) = 1.
// Therefore, the count of 2 is greater than N/3 times. Hence, 2 is the answer.

#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

vector < int > majorityElement(vector<int>&arr, int n) {

 // TC:0(n) SC:0(n) for map
//  unordered_map<int,int>map;
 vector<int>ans;
 int minPresent = (n/3) + 1;
//  for(auto n:arr)
//  {
//     map[n]++;
//     if(map[n] == minPresent)
//     {
//         ans.push_back(n);
//     }
//     if(ans.size() == 2)break;
//  }
// solution 1 ends here

  // TC:0(2n) SC:0(1)
  int cnt1 = 0,cnt2 =0;
  int ele1,ele2;

  for(auto n:arr)
  {
    if(cnt1 == 0 and n != ele2)
    {
        cnt1 = 1;
        ele1 = n;
    }
    else if(cnt2 == 0 and n != ele1)
    {
        cnt2 =1 ;
        ele2 = n;
    }
    else if(ele1 == n)
    {
        cnt1 ++;
    }
    else if(ele2 == n)
    {
        cnt2++;
    }
    else 
    {
        cnt1--;
        cnt2--;
    }
  }

  int c1 = 0,c2 = 0;

  for(auto n:arr)
  {
    if(ele1 == n)c1++;
    if(ele2 == n)c2++;
  }
 if(c1 >= minPresent)ans.push_back(ele1);
 if(c2 >= minPresent)ans.push_back(ele2);
 
    

 return ans;

}


int main() {
  vector<int> arr = {1,2,2,3,2};
  vector<int> majority;
  majority = majorityElement(arr, 5);
  cout << "The majority element is" << endl;
  set < int > s(majority.begin(), majority.end());
  for (auto it: s) {
    cout << it << " ";
  }
}