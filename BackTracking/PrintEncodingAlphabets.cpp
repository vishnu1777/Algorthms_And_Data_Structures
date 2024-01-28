#include <bits/stdc++.h>
using namespace std;

int decode(int idx, string s, vector<string> &ans, string temp)
{
    if (s[idx] == '0')
        return 0;
    if (idx >= s.size() - 1)
    {
        ans.push_back(temp);
        return 1;
    }

    if (s[idx] == '1' || (s[idx] == '2' and idx + 1 < s.size() and s[idx + 1] >= '0' and s[idx + 1] <= '6'))
    {
        int n1 = s[idx] - '0';
        int n2 = s[idx + 1] - '0';
        return decode(idx + 1, s, ans, temp + char('A' + n1)) + decode(idx + 2, s, ans, temp + char('A' + n1) + char('A' + n2));
    }

    return decode(idx + 1, s, ans, temp);
}

void func(int idx, string s, vector<string> &ans, string temp)
{
    if (s[idx] == '0')
        return;
    if (idx >= s.size())
    {
        ans.push_back(temp);
        return;
    }
    int n1 = s[idx] - '0';
    if (s[idx] == '1' || (s[idx] == '2' and idx + 1 < s.size() and s[idx + 1] >= '0' and s[idx + 1] <= '6'))
    {
        int n2 = s[idx + 1] - '0';
        int both = n1 * 10 + n2;
        func(idx + 2, s, ans, temp + char('A' + both - 1));
    }
    func(idx + 1, s, ans, temp + char('A' + n1 - 1));
}

void generate(string &digits, vector<string> &ans)
{
    string temp = "";
    func(0, digits, ans, temp);
    // cout<<decode(0,digits,ans,temp)<<endl;
}

void display(vector<string> &ans)
{
    for (auto s : ans)
        cout << s << " ";
    cout << endl;
}

int main()
{
    string num;
    getline(cin, num);
    vector<string> ans;
    generate(num, ans);
    display(ans);
    return 0;
}