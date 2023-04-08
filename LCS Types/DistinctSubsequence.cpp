#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int func(int i, int j, string &s1, string &s2)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;

    if (s1[i] == s2[j])
        return func(i - 1, j - 1, s1, s2) + func(i - 1, j, s1, s2);
    return func(i - 1, j, s1, s2);
}

int DistinctSequence(string &s1, string &s2)
{
    int m = s1.size();
    int n = s2.size();
    return func(m - 1, n - 1, s1, s2);
}

int main()

{

    string s1 = "rabbbit";
    string s2 = "rabbit";
    cout << DistinctSequence(s1, s2) << endl;
    return 0;
}