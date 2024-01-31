#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void findFreq(string &chars, vector<int> &freq)
    {
        for (auto c : chars)
        {
            freq[c - 'a']++;
        }
    }

    int findMax(int idx, vector<string> &words,  int n, vector<int> freq, int score[])
    {
        if(idx == n)return 0;

        int notTake = findMax(idx+1,words,n,freq,score);
        bool flag = true;
        int val = 0;
        for(int i=0;i<words[idx].size();i++){
            freq[words[idx][i]-'a']--;
            if(freq[words[idx][i]-'a'] < 0){
                flag = false;
                break;
            }
            val+= score[words[idx][i]-'a'];
        }
        int take = 0;
        if(flag)take = val+ findMax(idx+1,words,n,freq,score);
        return max(take,notTake);
    }

    int getScore(vector<string> &words, int n, string chars, int score[])
    {
        vector<int> freq(26);
        findFreq(chars, freq);
        vector<string> temp;
        return findMax(0, words, n, freq, score);
        
    }

    void display(vector<vector<string>> &ans)
    {
        for (auto subset : ans)
        {
            for (auto n : subset)
            {
                cout << n << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
     
    int tc;
    cin >> tc;
    while (tc--)
    {
       
        vector<string> words;
        int noOfWords;
        cin >> noOfWords;
        for (int i = 0; i < noOfWords; i++)
        {
            string str;
            cin >> str;
            words.push_back(str);
        }
        string str;
        cin>>str;

        int score[26];
        for(int i=0;i<26;i++){
            int num;
            cin>>num;
            score[i] = num;
        }
        Solution ob;
        int ans = ob.getScore(words, noOfWords, str, score);
        cout<<ans<<"\n";
    }
    return 0;
}