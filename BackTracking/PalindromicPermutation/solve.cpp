#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool isPalindrome(int start,int end,string&s){
        while(start<=end){
            if(s[start++] != s[end--])return false;
        }
        return true;
    }
    void func(int idx,string &s,int n,vector<vector<string>>&ans,vector<string>  temp){
        if(idx == s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=idx;i<s.size();i++){
            if(isPalindrome(idx,i,s)){
                temp.push_back(s.substr(idx,i-idx+1));
                func(i+1,s,n,ans,temp);
                temp.pop_back();
                

            }
        }
    }
    vector<vector<string>> solve(string&s){
        int n = s.size();
        vector<vector<string>>ans;
        vector<string> temp;
        func(0,s,n,ans,temp);
        return ans;
    }
    pair<bool,pair<bool,char>> createFrequencyAndHasMultipleOdds(string &s,vector<int>&freq){
        int oddCnt = 0;
        char oddChar;
        for(auto c:s){
            freq[c-'a']++;
        }
        // make half of freq array
        for(int i=0;i<26;i++){
            if(freq[i] % 2 != 0){
                oddChar = char('a'+i);
                oddCnt++;
            }
            freq[i] = freq[i]/2;
        }
        return {oddCnt <= 1,{oddCnt > 0,oddChar}};
    }
    string createString(vector<int>&freq){
        string s = "";
        for(int i=0;i<26;i++){
            if(freq[i] == 0)continue;
            for(int j=0;j<freq[i];j++){
                s+= char('a'+i);
            }
        }
        return s;
    }
    void func(int i,string &s,int n,pair<bool,char> &hasOdd,vector<string>&ans){
        if(i == s.size()){
            string res = s;
            if(hasOdd.first){
                res+= hasOdd.second;
            }
            reverse(s.begin(),s.end());
            res+= s;
            ans.push_back(res);
            reverse(s.begin(),s.end());
            return;
        }

        for(int j=i;j<s.size();j++){
            swap(s[i],s[j]);
            func(i+1,s,n,hasOdd,ans);
            swap(s[i],s[j]);
        }
    }
    vector<string>createPalindromicPermutation(string&s){
        vector<int>freq(26);
        pair<bool,pair<bool,char>>get =createFrequencyAndHasMultipleOdds(s,freq);
        if(!get.first){
            return {};
        }
        pair<bool,char>hasOdd = get.second;
        string halfString = createString(freq);
        int n = halfString.size();
        vector<string>ans;
        func(0,halfString,n,hasOdd,ans);
        return ans;
    }   

    void display(auto ans)
    {
        for (auto it : ans)
        {
            cout<<it<<endl;
        }

    }
};

int main()
{
     
    int tc;
    cin >> tc;
    while (tc--)
    {   
        string s;
        cin>>s;
        Solution ob;
        // vector<vector<string>>ans = ob.solve(s);
        vector<string>ans = ob.createPalindromicPermutation(s);
        ob.display(ans);
    }

    return 0;
}