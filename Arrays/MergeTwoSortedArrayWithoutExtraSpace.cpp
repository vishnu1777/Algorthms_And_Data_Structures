#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// TC:0(n+m)+0(n+m) SC:0(n+m)
void mergeTwoSortedArraysWithoutExtraSpace1(vector<long long> &a, vector<long long> &b){

    vector<long long>temp(a.size()+b.size());
	int left = 0;
	int right = 0;
	int ind = 0;
	int n = a.size();
	int m = b.size();

	while(left < n and right < m)
	{
		if(a[left] <= b[right])
		{
			temp[ind] = a[left];
			left++,ind++;
		}
		else
		{
			temp[ind] = b[right];
			right++,ind++;
		}
	}
	while(left < n)
	{
		temp[ind] = a[left];
		left++;
		ind++;
	}

	while(right < m)
	{
		temp[ind] = b[right];
		right++;
		ind++;
	}

	for(int i=0;i<temp.size();i++)
	{
		if(i<n)a[i] = temp[i];
		else b[i-n] = temp[i];
	}

}




void display(vector<long long>&num1,vector<long long>&num2)
{
    for(auto n:num1)
    {
        cout<<n<<" ";
    }
    for(auto n:num2)cout<<n<<" ";
}


//TC: 0(min(n,m))+0(nlongN) + 0(mlongM)
void mergeTwoSortedArraysWithoutExtraSpace2(vector<long long>&arr1,vector<long long>&arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    int left = n-1;
    int right = 0;

    while(left >= 0 and right < m)
    {
        if(arr1[left] > arr2[right])
        {
            swap(arr1[left],arr2[right]);
            left--,right++;
        }
        else break;
    }

    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
}

// TC:0(log2(n+m))+0(n+m)
void swapIfGreater(vector<long long>&arr1,vector<long long>&arr2,int ind1,int ind2)
{
	if(arr1[ind1] > arr2[ind2])
	{
		swap(arr1[ind1],arr2[ind2]);
	}
}


void mergeTwoSortedArraysWithoutExtraSpace3(vector<long long>&arr1,vector<long long>&arr2)
{
    int n = arr1.size();
    int m = arr2.size();

    int len = n+m;
    int gap = (len/2)+(len%2);

    while (gap>0)
    {
        int left = 0;
        int right = left + gap;

        while(right < len)
        {
            if(left < n and  right >=n)
            {
                swapIfGreater(arr1,arr2,left,right-n);

            }
            else if(left >=n)
            {
                swapIfGreater(arr2,arr2,left-n,right-n);
            }
            else
            {
                swapIfGreater(arr1,arr1,left,right);
            }
            left++,right++;
        }
        if(gap == 1)break;
        gap = (gap/2) + (gap%2);
    }
    
}

int main()
{
    vector<long long>num1 = {1,4,5,7};
    vector<long long>num2 = {2,3,6};
    mergeTwoSortedArraysWithoutExtraSpace1(num1,num2);
    display(num1,num2);
    
}