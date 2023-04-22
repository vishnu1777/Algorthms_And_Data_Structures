#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;


// takes 0(2n) TC
void sort1(vector<int>&arr)
{
    int n = arr.size();
    
   int cnt1 = 0;
   int cnt2 = 0;
   int cnt3 = 0;

   for(auto n:arr)
   {
       if(n == 0)cnt1++;
       else if(n == 1)cnt2++;
       else cnt3++;
   }

  for(int i=0;i<cnt1;i++)
  {
      arr[i] = 0;
  }

  for(int i= cnt1;i<cnt1+cnt2;i++)
  {
      arr[i] = 1;
  }

  for (int i = cnt1 + cnt2; i < n; i++) {
      arr[i] = 2;
  }
}

// Dutch National Flag Algorithm
void sort2(vector<int>&nums)
{
    int low = 0;
    int mid = 0;
    int high = nums.size()-1;

    while(mid<=high)
    {
        if(nums[mid] == 0)
        {
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid],nums[high]);
            high--;
        }
    }

}


void display(vector<int>&nums)
{
    for(auto n:nums)
    {
        cout<<n<<" ";
    }
    cout<<endl;
}


int main()
{
    vector<int> nums = {0,1,1,1,2,1,0,0,0,2};
    // sort1(nums);
    // display(nums);
    sort2(nums);
    display(nums);

    return 0;
}