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
    int findScore(vector<vector<string>> &ans, int score[])
    {
        int maxi = -1e9;
        for (auto it : ans)
        {
            for (auto subset : it)
            {
                int sum = 0;
                for (auto c : subset)
                {
                    sum += score[c - 'a'];
                    maxi = max(maxi, sum);
                }
            }
        }
        return maxi;
    }
    void findMax(int idx, vector<string> &words, vector<string> temp, int n, vector<int> freq, int score[], int &maxi, vector<vector<string>> &ans)
    {
        ans.push_back(temp);

        for (int i = idx; i < n; i++)
        {
            bool flag = true;
            for (int j = 0; j < words[i].size(); j++)
            {

                if (freq[words[i][j]] == 0)
                {
                    flag = false;
                    break;
                }
                freq[words[i][j] - 'a']--;
            }
            if (flag)
            {
                temp.push_back(words[i]);
                findMax(i + 1, words, temp, n, freq, score, maxi, ans);
                temp.pop_back();
            }
        }
    }

    int getScore(vector<string> &words, int n, string chars, int score[])
    {
        int maxi = -1e9;
        vector<vector<string>> ans;
        vector<int> freq(26);
        findFreq(chars, freq);
        vector<string> temp;
        findMax(0, words, temp, n, freq, score, maxi, ans);
        // display(ans);
        return findScore(ans, score);
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