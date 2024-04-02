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
   bool validateBst(TreeNode* root, long min, long max) {
        if (root == NULL)
            return true;

        if (root->val <= min || root->val >= max)
            return false;

        return validateBst(root->left, min, root->val) &&
               validateBst(root->right, root->val, max);
    }
    bool isValidBST(TreeNode* root) {
        //approach 1: we use inorder traversal and and if it is sorted or not
        //approach 2: below code
        return validateBst(root, LONG_MIN , LONG_MAX);
    }
};