#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool solve(int i,int j,int m,int n,vector<vector<char>>&grid,string&word,int k)
{

if(k == word.length())return true;

if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!= word[k])return false;

char c = grid[i][j];
grid[i][j] = '.';
bool status = solve(i+1,j,m,n,grid,word,k+1) || solve(i-1,j,m,n,grid,word,k+1) || solve(i,j+1,m,n,grid,word,k+1) || solve(i,j-1,m,n,grid,word,k+1);

grid[i][j] = c;
return status;

}


bool wordSearch(string &word,vector<vector<char>>&grid)
{
    if(word=="")return false;

    int row = grid.size();
    int col = grid[0].size();
    for (int  i = 0; i < row; i++)
    {
        for(int j=0;j<col;j++)
        {
            if(grid[i][j] == word[0])
            {
                if(solve(i,j,row,col,grid,word,0)){
                    return true;
                }
            }
        }
    }
    return false;
    


}


int main()
{


vector<vector<char>>grid ;
cout<<"enter the matrix row size:"<<endl;
int row;
cin>>row;
cout<<"enter the matrix col size:"<<endl;
int col;
cin>>col;
grid = vector<vector<char>>(row,vector<char>(col));
for (int  i = 0; i < row; i++)
{
    for (int  j= 0; j < col; j++)
    {
        char c;
        cout<<"enter the character for the i:"<<i<<" row"<<endl;
        cin>>c;
        grid[i][j] = c;
    }
    cout<<endl;
}


string s ;
cout<<"enter the string you want to search:"<<endl;

cin>>s;

bool isThere = wordSearch(s,grid);
if(isThere)
{
    cout<<"the given string is present in the grid:"<<endl;
}
else{
    cout<<"the string is not present:"<<endl;
}
    return 0;
}