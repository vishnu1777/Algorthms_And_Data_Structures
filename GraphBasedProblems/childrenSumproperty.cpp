
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    int num_of_nodes;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
        num_of_nodes = 0;
    }
};

void getTree(Node *root)
{
    if (!root)
    {
        return;
    }
    int child = 0;
    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;

    if (child >= root->data)
        root->data = child;
    else
    {
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }

    getTree(root->left);
    getTree(root->right);
    int tot = 0;
    if (root->left)
        tot += root->left->data;
    if (root->right)
        tot += root->right->data;
    if (root->left or root->right)
        root->data = tot;
}

void traverse(Node *root)
{
    if (!root)
    {
        return;
    }
    traverse(root->left);
    cout << root->data << " ";
    traverse(root->right);
}

int main()
{
    // binary tree formation
    Node *root = new Node(2);         /*           2            */
    root->left = new Node(1);         /*        /     \         */
    root->right = new Node(3);        /*       1       3        */
    root->left->left = new Node(4);   /*      / \     /  \      */
    root->left->right = new Node(10); /*     4   10  8    5     */
    root->right->left = new Node(8);  /*        /               */
    root->right->right = new Node(5); /*       6                */
    root->left->right->left = new Node(6);
    traverse(root);
    getTree(root);
    cout << endl;
    traverse(root);

    return 0;
}