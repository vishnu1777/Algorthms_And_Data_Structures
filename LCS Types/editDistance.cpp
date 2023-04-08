#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
// Given two strings word1 and word2,
// return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character
// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation:
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')

int func(int i, int j, string &s1, string &s2)
{
    if (j < 0)
        return i + 1;
    if (i < 0)
        return j + 1;
    if (s1[i] == s2[j])
        return func(i - 1, j - 1, s1, s2);
    int insert = 1 + func(i - 1, j, s1, s2);
    int delet = 1 + func(i, j - 1, s1, s2);
    int replace = 1 + func(i - 1, j - 1, s1, s2);
    return min(insert, min(delet, replace));
}
int Distance(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();

    return func(n - 1, m - 1, s1, s2);
}

int main()
{

    string s1 = "intention";
    string s2 = "execution";
    cout << Distance(s1, s2) << endl;

    return 0;
}