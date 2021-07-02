#include <bits/stdc++.h>
using namespace std;

class LFUCache
{
private:
    int cap,minFreq,count;
    struct Node
    {
        int key, value, frequency;
        Node *next, *prev;
        Node(int k, int v)
        {
            key = k;
            value = v;
            frequency = 1;
            next = prev = NULL;
        }
    };

    struct List
    {
        Node *head,*tail;
        int size;
        List()
        {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size=0;
        }

        void add(Node *node)
        {
            node->next=head->next;
            node->prev=head;
            head->next->prev=node;
            head->next=node;
            size++;
        }

        void remove(Node *node)
        {
            node->next->prev=node->prev;
            node->prev->next=node->next;
            delete node;
            size--;
        }
    };
    map<int, List *> frequencyList;
    unordered_map<int, Node *> mp;

public:

    LFUCache(int capacity)
    {
        cap=capacity;
        minFreq=1;
        frequencyList.clear();
        mp.clear();
    }
    void updateFrequencyList(Node *node)
    {
        int key=node->key;
        mp.erase(key);
        int freq=node->frequency;
        frequencyList[freq]->remove(node);

        if (freq == minFreq && frequencyList[freq]->size == 0)
        minFreq = freq + 1;

        List *nextFrequencyList=new List();

        if(frequencyList.find(freq+1)!=frequencyList.end())
            nextFrequencyList = frequencyList[freq + 1];

        node->frequency++;
        nextFrequencyList->add(node);
        frequencyList[node->frequency]=nextFrequencyList;
        mp[key]=node;
    }

    int get(int key)
    {
        if(mp.find(key)==mp.end())return -1;

        int val=mp[key]->value;
        updateFrequencyList(mp[key]);
        return val;
    }

    void set(int key, int value)
    {
        if(cap==0)
            return;

        if(mp.find(key)!=mp.end())
        {
            Node *node=mp[key];
            node->value=value;
            updateFrequencyList(node);
            return;
        }

        if(cap==count)
        {
            Node *node=frequencyList[minFreq]->tail->prev;
            frequencyList[minFreq]->remove(node);
            mp.erase(node->key);
            count--;
        }

        count++;
        minFreq = 1;
        List *newList = new List();
        Node *node=new Node(key,value);
        if (frequencyList[minFreq]->size != 0)
        {
            newList = frequencyList[minFreq];
        }
        newList->add(node);
        frequencyList[minFreq]=newList;
        mp[key]=node;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}