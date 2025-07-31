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


void insert_at_head(Node* &head, Node* &tail, int val)
{
    Node* newNode = new Node(val);

    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}


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


void insert_at_any_pos(Node* &head, Node* &tail, int idx, int val)
{
    Node* newNode = new Node(val);

    Node* tmp = head;

    for(int i=1; i<idx; i++)
    {
        tmp = tmp->next;
    }

    newNode->next = tmp->next;

    tmp->next->prev = newNode;

    tmp->next = newNode;

    newNode->prev = tmp;
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


void print_backward(Node* tail)
{
    Node* tmp = tail;

    while(tmp != NULL)
    {
        cout << tmp->val << " ";

        tmp = tmp->prev;
    }

    cout << "\n";
}

int main()
{
    Node* head = NULL;

    Node* tail = NULL;

    int q;

    cin >> q;

    while(q--)
    {
        int x, v;

        cin >> x >> v;

        int sz = size_of_list(head);

        if(x == 0)
        {
            insert_at_head(head, tail, v);

            cout << "L -> ";

            print_forward(head);

            cout << "R -> ";

            print_backward(tail);
        }

        else if(x == sz)
        {
            insert_at_tail(head, tail, v);

            cout << "L -> ";

            print_forward(head);

            cout << "R -> ";

            print_backward(tail);
        }

        else
        {
            if(x < 0 || x > sz)
            {
                cout << "Invalid\n";
            }

            else
            {
                insert_at_any_pos(head, tail, x, v);

                cout << "L -> ";

                print_forward(head);

                cout << "R -> ";

                print_backward(tail);
            }
        }
    }

    return 0;
}
