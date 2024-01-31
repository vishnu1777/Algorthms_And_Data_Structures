#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void dfs(int num,int n,vector<int>&ans){
        if(num > n )return;

        ans.push_back(num);
        dfs(num*10,n,ans);
        if(num % 10 != 9)dfs(num+1,n,ans);
    }
    vector<int> solve(int n){
        vector<int>ans;
        dfs(1,n,ans);
        return ans;
    }

    void display(auto ans)
    {
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << '\n';
    }
};

int main()
{
     
    int tc;
    cin >> tc;
    while (tc--)
    {   
        int n;
        cin>>n;
        Solution ob;
        vector<int>ans = ob.solve(n);
        ob.display(ans);

    }
    return 0;
}