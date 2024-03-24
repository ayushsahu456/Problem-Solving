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
    TreeNode* invertTree(TreeNode* root) {
        // base case
        if(root==NULL)
            return NULL;
    // use post order traversal
    // go to left node then right node then swap them
        invertTree(root->left);
        invertTree(root->right);
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        return root;
    }
};