#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


void insert_at_tail(Node* &head, Node* &tail, int val)
{
    Node* newNode = new Node(val);

    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}


void print_forward(Node* head)
{
    Node* tmp = head;

    while(tmp != NULL)
    {
        cout << tmp->val << " ";

        tmp = tmp->next;
    }

    cout << "\n";
}


int size_of_list(Node* head)
{
    int cnt = 0;

    Node* tmp = head;

    while(tmp != NULL)
    {
        cnt++;

        tmp = tmp->next;
    }

    return cnt;
}


int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int val;

    while(true)
    {
        cin >> val;

        if(val == -1)
        {
            break;
        }

        insert_at_tail(head, tail, val);
    }

    int sz = size_of_list(head);

    if(sz == 1)
    {
        cout << "YES\n";
        return 0;
    }

    int flag = 1;

    Node* i = head;

    Node* j = tail;

    while(i != j && j != i->prev)
    {
        if(i->val != j->val)
        {
            flag = 0;
            break;
        }

        i = i->next;

        j = j->prev;
    }

    if(flag == 1)
    {
        cout << "YES\n";
    }

    else
    {
        cout << "NO\n";
    }

    return 0;
}
