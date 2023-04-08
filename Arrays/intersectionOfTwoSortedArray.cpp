#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
using namespace std;


void optimal(vector<int>num1,vector<int>num2,vector<int>&ans)
{
    int i=0,j=0;
    int n= num1.size();
    int m = num2.size();

    while(i<n and j<m)
    {
        if(num1[i] < num2[j])
        {
            i++;
        }
        else if(num2[j]<num1[i])
        {
            j++;
        }
        else
        {
            ans.push_back(num1[i]);
            i++;
            j++;
        }
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


void brute(vector<int>num1,vector<int>num2,vector<int>&ans)
{
    int n = num1.size();
    int m = num2.size();
    
    vector<int>vis(m);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(num1[i] == num2[j] and !vis[j])
            {
                ans.push_back(num1[i]);
                vis[j] =1;
                break;
            }
            if(num2[j]>num1[i])break;
        }
    }

}



int main()
{
    vector<int>num1 = {1,1,2,3,4,5};
    vector<int>num2 = {2,3,4,4,5,6};
    vector<int>ans;
    brute(num1,num2,ans);
    // optimal(num1,num2,ans);
    display(ans);
    
   
    return 0;
}