
//  * Definition for binary tree
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
#include<bits/stdc++.h>
using namespace std;
 bool path(TreeNode*root, vector<int>&ans, int B){
    if (root==NULL) {
        return false;
    }
    ans.push_back(root->val);
    if (root->val==B) {
        return true;
    }
    if (path(root->left, ans, B) || path(root->right, ans, B)) {
        return true;
    }

    ans.pop_back();
    return false;
     
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    path(A,ans,B);
    return ans;
}