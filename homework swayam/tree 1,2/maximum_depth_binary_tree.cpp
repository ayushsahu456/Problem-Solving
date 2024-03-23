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
    int maxDepth(TreeNode* root) {
        //base condition if root == null
        if(root==NULL){
            return 0;
        }
        //get maximum from both the subtree and add 1 as root is there
        //root ko hum count kr lete h baaki recursion krega left,right tree me
        int ans= 1 + max(maxDepth(root->left) , maxDepth(root->right));
        return ans;
    }
};