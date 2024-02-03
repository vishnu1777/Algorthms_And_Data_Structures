#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void func(int idx, string key, string s, unordered_map<char, string> map, vector<string> &ans)
    {
        if (key.size() == 0)
        {
            if (s.size() != 0)
                return;
            unordered_set<string> st;
            for (auto it : map)
            {
                string res = "";
                res += it.first;
                res += "->";
                res += it.second;
                st.insert(res);
            }
            for (auto it : st)
                cout << it << " ";
            cout << endl;
            return;
        }
        char temp = key[idx];
        string rk = key.substr(1);

        if (map.find(temp) != map.end())
        {
            string previousMappedString = map[temp];
            if (s.size() >= previousMappedString.size())
            {
                string left = s.substr(0, previousMappedString.size());
                string right = s.substr(previousMappedString.size());

                if (left == previousMappedString)
                {
                    func(idx + 1, rk, right, map, ans);
                }
            }
        }
        else
        {
            for (int i = 0; i < s.size(); i++)
            {

                string left = s.substr(0, i + 1);
                string right = s.substr(i + 1);
                map[temp] = left;
                func(idx + 1, key, right, map, ans);
                map.erase(temp);
            }
        }
    }
    vector<string> solve(string &key, string &s)
    {
        vector<string> ans;
        unordered_map<char, string> map;
        func(0, key, s, map, ans);
        return ans;
    }

    void display(auto ans)
    {
        for (auto it : ans)
        {
            cout << it << endl;
        }
    }
};

int main()
{

    int tc;
    cin >> tc;
    while (tc--)
    {
        string key;
        cin >> key;
        string s;
        cin >> s;
        Solution ob;
        vector<string> ans = ob.solve(key, s);
        ob.display(ans);
    }
    return 0;
}