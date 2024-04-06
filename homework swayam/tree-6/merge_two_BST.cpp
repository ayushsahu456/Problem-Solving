#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution
{
    public:
    void inorder(Node *root,vector<int>& arr){
        if(root==NULL){
            return;
        }
        inorder(root->left,arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> ans;
       inorder(root1,ans); // get all nodes from tree 1
       inorder(root2,ans); // get all nodes from tree 2
       sort(ans.begin(),ans.end());
       return ans;
    }
};