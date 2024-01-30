#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void func(int idx,vector<int>&nums,vector<int>temp,vector<vector<int>>&ans){
        ans.push_back(temp);

        for(int i=idx;i<nums.size();i++){
            temp.push_back(nums[i]);
            func(i+1,nums,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>>generateSubsets(vector<int>&nums){
        vector<vector<int>>ans;
        vector<int>temp;
        func(0,nums,temp,ans);
        return ans;
    }

    void display(auto ans){
        for(auto it:ans){
            for(auto n:it)cout<<n<<" ";
        cout<<endl;
        }
    }

};







int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        vector<int>nums;
        for(int i=0;i<n;i++){
            int ele;
            cin>>ele;
            nums.push_back(ele);
        }
        Solution ob;
        vector<vector<int>>ans = ob.generateSubsets(nums);
        ob.display(ans);
    }
    return 0;
}