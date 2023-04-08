#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

vector<int>getRow(int n)
{
    int ans = 1;
    vector<int>ansRow;
    ansRow.push_back(1);
    for(int i=1;i<n;i++)
    {
        ans = ans* (n-i);
        ans = ans/i;
        ansRow.push_back(ans);
    }
    return ansRow;
}
// To calculate this use the formula nCr combination formula
void givenRandC(int r,int c){
    int ans = 1;
    for(int i=0;i<c;i++)
    {
        ans = ans*(r-i);
        ans = ans/(i+1);
    }
    cout<<ans<<endl;
}

void printGivenN(int n)
{
    int ans = 1;
    cout<<ans<<" ";
    for(int i=1;i<n;i++)
    {
        ans = ans*(n-i);
        ans = ans/(i);
        cout<<ans<<" ";
    }
}


void printAll(int n)
{
    vector<vector<int>>ans;
    for(int i=1;i<=n;i++)
    {
        ans.push_back(getRow(i));
    }

    for(auto it:ans)
    {
        for(auto n:it)
        {
            cout<<n<<" ";
        }
        cout<<endl;
    }
}


int main()
{   
    givenRandC(5,4);
    printGivenN(5);
    cout<<endl;
    printAll(6);
    return 0;
}