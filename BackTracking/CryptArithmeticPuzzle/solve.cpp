#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void mapStrings(string &s1, string &s2, string &s3, string &uniqueString, unordered_map<char, int> &map)
    {
        for (auto c : s1)
        {
            if (map.find(c) == map.end())
            {
                map[c] = -1;
                uniqueString += c;
            }
        }
        for (auto c : s2)
        {
            if (map.find(c) == map.end())
            {
                map[c] = -1;
                uniqueString += c;
            }
        }
        for (auto c : s3)
        {
            if (map.find(c) == map.end())
            {
                map[c] = -1;
                uniqueString += c;
            }
        }
    }
    int getNumber(string s,unordered_map<char,int>&map){
        int num = 0;
        for(auto c:s){
            num = num*10 + map[c];
        }
        return num;
    }
    string generateSequence(unordered_map<char, int> &map)
    {
       string ans = "";

       for(int i=0;i<26;i++){
            char current = char('a'+i);
            if(map.find(current) != map.end()){
                ans+=current;
                ans+="->";
                char num = '0'+map[current];
                ans+=num;
            }
       }
       return ans;
    }
    void findAns(int idx, string &s, unordered_map<char, int> map, vector<string> &ans, vector<int> vis)
    {
        if (idx == s.size())
        {
            int n1 = getNumber("send",map);
            int n2 = getNumber("more",map);
            int n3 = getNumber("money",map);
            if(n1+n2 == n3){
                ans.push_back(generateSequence(map));
            }
            return;
        }
        char current = s[idx];
        for (int num = 0; num <= 9; num++)
        {
            if (vis[num] == 0)
            {
                map[current] = num;
                vis[num] = 1;
                findAns(idx + 1, s, map, ans, vis);
                vis[num] = 0;
                map[current] = -1;
            }
        }
    }

    vector<string> solve(string &s1, string &s2, string &s3)
    {
        int n = s1.size(), n2 = s2.size(), n3 = s3.size();
        string uniqueString = "";
        unordered_map<char, int> map;
        mapStrings(s1, s2, s3, uniqueString, map);
        vector<int> vis(11);
        vector<string> ans;
        findAns(0, uniqueString, map, ans, vis);
        return ans;
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
        string s1, s2, s3;
        cin >> s1;
        cin >> s2;
        cin >> s3;

        Solution ob;
        vector<string> ans = ob.solve(s1, s2, s3);
        ob.display(ans);
    }
    return 0;
}