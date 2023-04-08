#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

void brute(vector<int>num1,vector<int>num2,vector<int>&ans)
{
    set<int>s;
    for(auto n:num1)
    {
        s.insert(n);
    }
    for(auto n:num2)
    {
        s.insert(n);
    }
    for(auto it:s)
    {
        ans.push_back(it);
    }

}

void optimal(vector<int>num1,vector<int>num2,vector<int>&ans)
{
    int n = num1.size();
    int m = num2.size();
    int i=0,j=0;
    while(i<n and j<m)
    {
        if(num1[i]<=num2[j])
        {
            if(ans.size() == 0 || ans.back()!=num1[i])
            {
                ans.push_back(num1[i]);
            }
            i++;
        }
        else
        {
            if(ans.size() == 0 || ans.back()!=num2[j])
            {
                ans.push_back(num2[j]);
            }
            j++;
        }
    }
    while(i<n)
    {
        if(ans.size() == 0 || ans.back()!=num1[i])
            {
                ans.push_back(num1[i]);
            }
            i++;     
    }
    while(j<m)
    {
        if(ans.size() == 0 || ans.back()!=num2[j])
            {
                ans.push_back(num2[j]);
            }
            j++;     
    }
}

void display(vector<int>&ans)
{
    for(auto n :ans)
    {
        cout<<n<<" ";
    }
    cout<<endl;
}



int main()
{
    vector<int>num1 = {1,1,2,3,4,5};
    vector<int>num2 = {2,3,4,4,5,6};
    vector<int>ans;
    // brute(num1,num2,ans);
    optimal(num1,num2,ans);
    display(ans);
    return 0;
}