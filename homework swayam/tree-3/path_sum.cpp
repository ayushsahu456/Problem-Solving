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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        //agar root ka left node and right node null hai
        // to check kro kya wo target ke equal hai ya nai
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }
        //(preorder approach)
        
        //left subtree ka sum calculate krlo
        //right subtree ka sum calculate krlo
        bool left_sum = hasPathSum(root->left, targetSum - root->val);
        bool right_sum = hasPathSum(root->right, targetSum - root->val);
        //check krke return krdo ki wo present hai left/right subtree me ya nai
        return left_sum || right_sum;
    }
};
