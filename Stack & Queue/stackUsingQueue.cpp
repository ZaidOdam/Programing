#include <bits/stdc++.h>
using namespace std;

queue<int> q1;
queue<int> q2;

void push(int x) //O(1)
{
    q1.push(x);
}

int pop() 
{
    if (q1.empty() && q2.empty())
        return -1;
  
        while (q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }

    int ans = q1.front();
    q1.pop();
    swap(q1,q2);
    return ans;
}

int front()
{
    if (q1.empty() && q2.empty())
        return -1;

    while (q1.size() != 1)
    {
        q2.push(q1.front());
        q1.pop();
    }

    int ans = q1.front();
    q2.push(q1.front());
    q1.pop();
    swap(q1,q2);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    push(1);
    push(3);
    cout << front() << " ";
    push(4);
    cout << pop() << " ";
    push(5);
    push(6);
    cout << front() << " ";
    cout << pop() << " ";
    cout << pop() << " ";
    cout << front() << " ";

    return 0;
}