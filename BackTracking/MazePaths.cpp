#include <bits/stdc++.h>
using namespace std;

void func(int i, int j, int n, int m, string s, unordered_set<string> &ans)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
        return;

    if (i == n - 1 and j == m - 1)
    {
        ans.insert(s);
        cout << s << endl;
        return;
    }

    func(i + 1, j, n, m, s + "h", ans);

    func(i, j + 1, n, m, s + "v", ans);
}

void generate(int n, int m, unordered_set<string> &ans)
{
    string s = "";
    func(0, 0, n, m, s, ans);
}

void display(unordered_set<string> &ans)
{
    for (auto s : ans)
        cout << s << " ";
    cout << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    unordered_set<string> ans;
    generate(n, m, ans);
    display(ans);
    return 0;
}