#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    void func(int idx,int cnt,string &s,int n,string temp,vector<string>&ans){
        if(idx == n){
            if(cnt == 0)
                ans.push_back(temp);
            else {
                temp+=to_string(cnt);
                ans.push_back(temp);
            }
            return;
        }
        if(cnt > 0)
            func(idx+1,0,s,n,temp+to_string(cnt)+s[idx] ,ans);
        else func(idx+1,0,s,n,temp+s[idx],ans);
        func(idx+1,cnt+1,s,n,temp,ans);

    }
    
    vector<string>generateAbbrevation(string&s){
        vector<string>ans;
        string temp = "";
        int n = s.size();
        func(0,0,s,n,temp,ans);
        return ans;
    }

    void display(vector<string>&ans){
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
};







int main(){
    int tc;
    cin>>tc;
    while(tc--){
        string str;
        cin>>str;
        Solution ob;
        vector<string>ans = ob.generateAbbrevation(str);
        ob.display(ans);
        cout<<"\n";
    }
    return 0; 
}