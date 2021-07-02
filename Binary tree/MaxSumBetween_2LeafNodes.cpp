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

int maxSum;
int findSum(Node*root)
{
    if(root==NULL)
        return 0;

    int ls=findSum(root->left);
    int rs=findSum(root->right);

    if(root->left!=NULL && root->right!=NULL){
        maxSum=max(maxSum,ls+rs+root->data);
        return max(ls,rs)+root->data;
    }
    else if(root->left!=NULL){
        return ls+root->data;
    }
    else{
        return rs+root->data;
    }
}

int findMaxSumInLeaf(Node *root)
{
    maxSum=INT_MIN;
    int ans=findSum(root);
    if(maxSum==INT_MIN){
        return ans;
    }
    return maxSum;

}

int main()
{
    struct Node *root;
    //level 0
    root = new Node(1);
    //level 1
    root->left = new Node(2);
    root->right = new Node(3);
    //level 2
    root->left->left = new Node(-4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(-7);
    //level 3
    root->right->right->left = new Node(-8);
    root->right->left->left=new Node(-9);

    /*
              1
           /    \
          2      3
          /\    /\
       -4  5 -6   -7
              /  /
           -9   -8 
    */

    cout<<findMaxSumInLeaf(root);
    return 0;
}