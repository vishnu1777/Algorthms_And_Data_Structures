#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

class ListNode{
public:
    int val;
    ListNode*next;
    ListNode(int val)
    {
        this->val = val;
    }
};
ListNode* head = NULL;
ListNode* curr = NULL;

void createNode(int val)
{
    if(!head)
    {
        head = new ListNode(val);
        head->next = NULL;
        curr = head;
    }
    else
    {
       curr->next = new ListNode(val);
       curr = curr->next;
       curr->next = NULL;
    }
}

void revLinkedList()
{
    ListNode* prev = NULL,*next = NULL;
    while(head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;

    }
    head = prev;

   
}


void display()
{
    ListNode*temp = head;
    while(temp)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{      
    int n;
    cout<<"Give the no of  nodes to insert:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int ele;
        cout<<"Enter the value to insert:"<<endl;
        cin>>ele;
        createNode(ele);
    }
    display();
    revLinkedList();
    display();
    
    return 0;
}