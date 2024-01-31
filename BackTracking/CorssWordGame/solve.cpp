#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<char>> traverseVertical(int i, int j, int nn, int m, vector<vector<char>> &grid,  string &word)
    {
        int n = word.size();
        for (int jj = 0; jj < n; jj++)
        {
            if (grid[i + jj][j] == '-' || grid[i + jj][j] == word[jj])
            {
                grid[i + jj][j] = word[jj];
            }
            else{
                grid[0][0] = '@';
                return grid;
            }
        }
        return grid;
    }
    vector<vector<char>>  traverseHorizontal(int i, int j, int nn, int m, vector<vector<char>> grid, string &word)
    {
        int n = word.size();
        for (int jj = 0; jj < n; jj++)
        {
            if (grid[i][j + jj] == '-' || grid[i][jj + j] == word[jj])
            {
                grid[i][j + jj] = word[jj];
            }
            else{
                grid[0][0] = '@';
                return grid;
            }
        }
        return grid;
    }

    void func(vector<string> &words, int noOfWords, int n, int m, vector<vector<char>> grid, int level)
    {
        if(level > noOfWords)return;
        if (level == noOfWords)
        {
            display(grid);
            return;
        }
        string word = words[level];
        int maxLen = n - word.size();
        for (int i = 0; i < maxLen; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vector<vector<char>>temp = traverseVertical(i,j,n,m,grid,word);
                if(temp[0][0] != '@')
                {
                    func(words, noOfWords, n, m, temp, level + 1);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < maxLen; j++)
            {
                vector<vector<char>>temp =  traverseHorizontal(i, j, n, m, grid, word);
                if(temp[0][0] != '@'){
                    func(words, noOfWords, n, m, temp, level + 1);
                }
            }
        }
    }
    void solve(vector<string> &words, int noOfWords, int n, int m, vector<vector<char>> &grid)
    {
        func(words, noOfWords, n, m, grid, 0);
    }

    void display(auto ans)
    {
        for (auto it : ans)
        {
            for (auto c : it)
                cout << c << " ";
            cout << endl;
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
        int noOfWords;
        vector<string> words;
        cin >> noOfWords;
        for (int i = 0; i < noOfWords; i++)
        {
            string word;
            cin >> word;
            words.push_back(word);
        }
        int n, m;
        cin >> n;
        cin >> m;
        vector<vector<char>> grid(n, vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char c;
                cin >> c;
                grid[i][j] = c;
            }
        }
        Solution ob;
        ob.solve(words, noOfWords, n, m, grid);
    }
    return 0;
}