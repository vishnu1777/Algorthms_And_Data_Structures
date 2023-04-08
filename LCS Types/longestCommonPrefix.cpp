#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string getPrefix(string s1, string s2)
{
    string res = "";
    int len = s1.length();
    for (int i = 0; i < len; i++)
    {
        if (s1[i] == s2[i])
        {
            res += s1[i];
        }
    }
    return res;
}

string longestPrefix(vector<string> &s)
{
    string prefix = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        prefix = getPrefix(prefix, s[i]);
    }
    return prefix;
}

int main()
{

    
    int n ;
    cout<<"enter the number of strings you want to input:"<<endl;
    cin>>n;
     vector<string> s(n) ;
    for(int i=0;i<n;i++)
    {

        string temp;
        cout<<"enter the strings:"<<endl;
        cin>>temp;
        s[i]  = temp;

    }
   

    string prefix = longestPrefix(s);
    cout << "the longest prefix is:" << prefix << endl;

    return 0;
}