#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string multiply(string &s1, string &s2)
{
    string res = "";
    vector<int> store(s1.length() + s2.length(), 0);
    for (int i = s1.length() - 1; i >= 0; i--)
    {
        for (int j = s2.length() - 1; j >= 0; j--)
        {
            store[i + j + 1] += (s1[i] - '0') * (s2[j] - '0');
            store[i + j]+= store[i + j + 1] / 10;
            store[i + j + 1] %= 10;
        }
    }
    int i = 0;
    while (store[i] == 0)
        i++;
    while (i < store.size())
    {
        res += to_string(store[i]);
        i++;
    }

    return res;
}

int main()
{

    string s1;
    string s2;

    cout << "enter the first string to multiply:" << endl;
    cin >> s1;
    cout << "enter the second string to multiply:" << endl;
    cin >> s2;
    string ans = multiply(s1, s2);
    cout << "the final multiplied string is:" << ans << endl;
    return 0;
}