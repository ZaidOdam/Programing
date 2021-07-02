#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
map<int,vector<int>>mp;
void digonal(Node *root,int slopeLevel){
    if(root==NULL)return;

    mp[slopeLevel].push_back(root->data);

    digonal(root->left,slopeLevel+1);
    digonal(root->right,slopeLevel);
}
void digonalTraversal(Node *root){
    //recursive using maps->

    cout<<"Using maps (Recursion) -> ";
    mp.clear();
    if(root==NULL)
        return;
    digonal(root,0);
    for(auto p : mp){
        for(auto x : p.second){
            cout<<x<<" ";
        }
    }
    cout<<"\n\nUsing queue (iterative) -> ";

    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();

        while(temp!=NULL){
            cout<<temp->data<<" ";

            if(temp->left!=NULL)
            q.push(temp->left);

            temp=temp->right;
        }
    }
}
int main()
{
    struct Node *root,*target;
    //level 0
    root = new Node(1);
    //level 1
    root->left = new Node(2);
    target=root->right = new Node(3);
    //level 2
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    //level 3
    root->right->right->left = new Node(8);
    root->right->left->left=new Node(9);

    /*
            1
           /\
          2  3
          /\  /\
        4  5 6   7
            /  /
           9   8 
    */

    digonalTraversal(root);
    return 0;
}