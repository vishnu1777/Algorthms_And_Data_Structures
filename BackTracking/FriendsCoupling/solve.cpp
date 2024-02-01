#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void func(int idx, vector<string> &ans, vector<int> vis, string temp, int n)
    {
        if (idx == n + 1)
        {
            ans.push_back(temp);
            return;
        }
        // if the current number is already visited then we move to end
        if (vis[idx])
        {

            func(idx + 1, ans, vis, temp, n);
        }
        else
        {
            // else we have 2 choice
            vis[idx] = 1;
            // mark the current num as visited
            string current = to_string(idx);
            // either you can be lonely
            func(idx + 1, ans, vis, temp + "(" + current + ")", n);

            for (int i = idx + 1; i <= n; i++)
            {
                if(vis[i])continue;
                vis[i] = 1;
                // or make a pair with next number
                string next = to_string(idx) + to_string(i);
                // call recursively for the paired answer
                func(idx + 1, ans, vis, temp + "(" + next + ")", n);
                vis[i] = 0;
            }
            vis[idx] = 0;
        }
    }
    vector<string> solve(int n)
    {
        vector<int> vis(n + 1, 0);
        vector<string> ans;
        string temp = "";
        func(1, ans, vis, temp, n);
        return ans;
    }

    void display(vector<string> &ans)
    {
        for (auto s : ans)
        {
            cout << s << endl;
        }
    }
};

int main()
{

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        Solution ob;
        vector<string> ans = ob.solve(n);
        ob.display(ans);
    }
    return 0;
}