// Online C++ compiler to run C++ program online
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> v = {1, 3, 6, 8, 12};
int getTime()
{

    int n;
    int time;
    int items;
    int k = 2;

    if (v.size() == 1)
    {
        cout << v[0];
        return 0;
    }
    if (items == 3)
    {
        int ans = accumulate(v.begin(), v.end(), 0);
        cout << "Min time taken to cross bridge is " << ans << endl;
    }
    else
    {
        int last = v.size() - 1;
        time = v[0] + v[1] + v[last] + v[1];

        while (last - k >= 2)
        {
            time += v[0] + v[last - k];
            k++;
        }
        time = time + v[1];
    }
    return time;
}

bool isTrue(unordered_map<int, bool> &map)
{
    for (auto it : map)
    {
        if (!it.second)
            return false;
    }
    return true;
}

void display(unordered_map<int, bool> &map)
{
    for (auto it : map)
    {
        if (!it.second)
        {
            cout << "Left:" << it.first << endl;
        }
    }
    cout << endl;
    for (auto it : map)
    {
        if (it.second)
        {
            cout << "Right:" << it.first << endl;
        }
    }
}

bool check(unordered_map<int, bool> &map)
{
    for (auto it : map)
    {
        if (!it.second)
            return false;
    }
    return true;
}

int play()
{
    unordered_map<int, bool> map;
    for (auto n : v)
        map[n] = false;
    int maxi = -1e9;
    int timeTaken = 0;
    while (!isTrue(map))
    {
        display(map);
        int A, B;
        cout << "Enter two person to cross bridge:" << endl;
        cin >> A >> B;
        map[A] = true;
        map[B] = true;
        display(map);
        maxi = max(A, B);
        timeTaken += maxi;
        cout << "Time taken to cross bridge is:" << maxi << endl;
        if (check(map))
            break;
        int C;
        cout << "Enter the person to go to left of bridge:" << endl;
        cin >> C;
        timeTaken += C;
        map[C] = false;
    }
    return timeTaken;
}

int main()
{
    int ans = getTime();
    int userPlays = play();
    if (userPlays == ans)
    {
        cout << "You are Winner!!" << endl;
    }
    else
    {
        cout << "Sorry you lose :(" << endl;
    }
    return 0;
}