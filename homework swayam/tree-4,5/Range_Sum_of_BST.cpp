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
    int sum;
    //use preorder traversal to traverse the tree
    void preorder(TreeNode* root, int low, int high){
        if(root==NULL){
            return;
        }
        //if root->val lies in the range add it
        if(root->val>=low && root->val<=high){
            sum+=root->val;
        }
        preorder(root->left,low,high);
        preorder(root->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum=0;
        //call preorder function
        preorder(root,low,high);
        return sum;
    }
};