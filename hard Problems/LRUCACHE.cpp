#include <stdio.h>
#include <iostream>
#include <unordered_map>
using namespace std;

class LRU
{
public:
    class node
    {
    public:
        int key;
        int val;
        node *next;
        node *prev;

        node(int key, int val)
        {
            this->key = key;
            this->val = val;
        }
    };

    int cap;
    unordered_map<int, node *> map;
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    LRU(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(node *delNode)
    {
        node *prev_node = delNode->prev;
        node *next_node = delNode->next;
        prev_node->next = next_node;
        next_node->prev = prev_node;
    }
    void addNode(node *newNode)
    {
        node *temp = head->next;
        newNode->next = temp;
        temp->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
    }

    void display()
    {
        cout << endl;
        cout << ":::::::The items remaining in our cache is:::::::" << endl;
        for (auto it : map)
        {
            cout << "Key:" << it.first << "\tValue:" << it.second->val << endl;
        }
    }

    void get()
    {

        cout << "enter the key to get the item:";
        int key;
        cin >> key;

        if (map.find(key) != map.end())
        {
            node *temp = map[key];
            map.erase(key);
            int res = temp->val;
            deleteNode(temp);
            addNode(temp);
            map[key] = head->next;
            cout << "The value associated to the given key is:" << res << endl;
        }
        else
        {
            cout << "There is no value associated to the given key in our cache" << endl;
        }
    }

    void put()
    {
        int key;
        int value;
        cout << "enter the key and value to insert in cache " << endl;
        cout << "enter the key:";
        cin >> key;
        cout << "enter the value:";
        cin >> value;
        cout << endl;
        if (map.find(key) != map.end())
        {
            node *temp = map[key];
            map.erase(key);
            deleteNode(temp);
        }
        if (map.size() == cap)
        {
            map.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key, value));
        map[key] = head->next;
        cout << ":::::::Succesfully inserted in our cache!!!:::::::" << endl;
        display();
    }
};

int main()
{
    int n;
    cout << ":::::::Specify the size of the cache:::::::" << endl;
    cin >> n;
    LRU l(n);
    int initializer = 1;
    do
    {
        int key;
        int value;
        cout << "\n1.To insert put item in the cache\t2.To get the item in our cache\t3.exit" << endl;
        int exp;
        cin >> exp;
        switch (exp)
        {
        case 1:
            l.put();
            break;
        case 2:
            l.get();
            break;
        case 3:
            initializer = 0;
            exit(0);
        }

    } while (initializer);

    return 0;
}