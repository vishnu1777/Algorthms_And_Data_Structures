#include <bits/stdc++.h>
using namespace std;

class Solution
{

    void display(auto ans)
    {
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }
};

int main()
{
    ifstream input_file("your_input_folder/test1.txt");
    ofstream output_file("your_output_folder/test1.txt");

    if (!input_file.is_open())
    {
        cerr << "Error opening input file" << endl;
        return 1; // Exit with an error code
    }

    if (!output_file.is_open())
    {
        cerr << "Error opening output file" << endl;
        return 1; // Exit with an error code
    }
    int tc;
    input_file >> tc;
    while (tc--)
    {
        string str;
        input_file >> str;
        Solution ob;
    }
    return 0;
}