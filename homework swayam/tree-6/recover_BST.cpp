#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    void inorder(TreeNode* root,vector<int>&arr){
        if(root==NULL){
            return;
        }
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    int index=0;
    void validate(TreeNode* root,vector<int>&arr){
        if(root==NULL){
            return;
        }
        validate(root->left,arr);
        //if value not same then swap it
        if(root->val!=arr[index]){
            swap(root->val,arr[index]);
        }
        //update the index
        index++;
        validate(root->right,arr);
    }
    void recoverTree(TreeNode* root) {
        //first store inorder traversal in a vector
        //then sort tht vector to get the correct sequence
        //now check the vector values with the tree nodes by again traversing inorder in a tree
        vector<int>nodes;
        inorder(root,nodes);
        sort(nodes.begin(),nodes.end());
        validate(root,nodes);
    }
};