#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void dfs(int num,int n,vector<int>&ans){
        if(num > n )return;

        for(int i=0;i<10;i++){
            num =( num*10)+i;
            if(num == 0)continue;
            else{
                ans.push_back(num);
                dfs(num,n,ans);
            }
        }
    }
    vector<int> solve(int n){
        vector<int>ans;
        dfs(1,n,ans);
    }

    void display(auto ans)
    {
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
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