#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

class node{
public:  node*left;
    node*right;
    int val;
    node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};


vector<int>ans;
void leftView(node*root,int level)
{
    if(!root)return;

    if(level == ans.size())
    {
        ans.push_back(root->val);
    }
    leftView(root->left,level+1);
    leftView(root->right,level+1);
}

void rightView(node*root,int level)
{
    if(!root)return;

    if(level == ans.size())
    {
        ans.push_back(root->val);
    }
    rightView(root->right,level+1);
    rightView(root->left,level+1);
}

void display(vector<int>&ans)
{
    for(auto n:ans)
    {
        cout<<n<<" ";
    }
    cout<<endl;
}

int main()
{
  node* root = new node(1);
  root->left = new node(2);
  root->right = new node(5);

//   leftView(root,0);
  rightView(root,0);         
  display(ans);
}