#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

struct mycmp{
    int operator()(Node *&a,Node *&b){
        return a->data > b->data;
    }
};

Node *mergeKSortedList(Node *head[] ,int k)
{
    priority_queue<Node *,vector<Node*>,mycmp>pq;

    for(int i=0;i<k;i++)
    {
        pq.push(head[i]);
    }
    Node *s=new Node(-1);
    Node *t=s;
    while(!pq.empty())
    {
        t->next=pq.top();
        t=t->next;
        pq.pop();

        if(t->next!=NULL)
            pq.push(t->next);
    }

    t->next=NULL;
    return s->next;
}

Node *insertAtTail(Node *head, int d)
{
    if (head == NULL)
    {
        return new Node(d);
    }

    Node *tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = new Node(d);

    return head;
}

Node *create(vector<int> &arr)
{
    Node *head = NULL;

    for (int i = 0; i < arr.size(); i++)
    {
        head = insertAtTail(head, arr[i]);
    }

    return head;
}

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr[n];
    Node *head[n];

    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        for(int i=0;i<m;i++){
            int val;
            cin>>val;
            arr[i].push_back(val);
        }
        head[i]=create(arr[i]);
        print(head[i]);
    }
   
   Node *head1=mergeKSortedList(head ,n);

    print(head1);
}