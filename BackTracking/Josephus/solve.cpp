#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int solve(int n,int k){
        if(n == 1)return 0;
        int x = solve(n-1,k);
        int y = (x+k)%n;
        // cout<<x<<" "<<y<<" "<<n<<endl;
        return y;
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
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.solve(n,k)<<"\n";
    }
    return 0;
}