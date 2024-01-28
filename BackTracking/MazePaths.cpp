#include <bits/stdc++.h>
using namespace std;

void func(int i, int j, int n, int m, string s, vector<string> &ans,vector<vector<int>>&vis)
{
    if ( i < 0 || j < 0 || i >= n || j >= m)
        return;
    
    if (i == n - 1 and j == m - 1)
    {
        ans.push_back(s);
        return;
    }

    func(i + 1, j, n, m, s + "h", ans,vis);
    func(i, j + 1, n, m, s + "v", ans,vis);
    
}

void generate(int n, int m, vector<string> &ans)
{
    string s = "";
    vector<vector<int>>vis(n,vector<int>(m));
    func(0, 0, n, m, s, ans,vis);
}

void display(vector<string> &ans)
{
    for (auto s : ans)
        cout << s << " ";
    cout << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> ans;
    generate(n, m, ans);
    display(ans);
    return 0;
}