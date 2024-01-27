#include<bits/stdc++.h>
using namespace std;

void func(int idx,vector<string>&ans,string s,string input,string map[]){
    if(idx == input.size()){
        ans.push_back(s);
        return;
    }

    char number = input[idx];
    string word = map[number-'0'];

    for(int i=0;i<word.size();i++){
        s+= word[i];
        func(idx+1,ans,s,input,map);
        s.pop_back();
    }
}

void generate(vector<string>&ans,string& input){
    if(input.size() == 0)return;
    string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    string s = "";
    func(0,ans,s,input,map);
}

void display(vector<string>&ans){
   for(auto s:ans)cout<<s<<" ";
   cout<<endl;
}

int main(){
    string numberCombo;
    cin>>numberCombo;
    vector<string>ans;
    generate(ans,numberCombo);
    display(ans);
    return 0;
}