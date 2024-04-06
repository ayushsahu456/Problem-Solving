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
    TreeNode* solve(vector<int>& preorder , int maxi, int&i){
         // base case - 1
        if(i >= preorder.size())
            return NULL;
        
        // base case - 2
        if(preorder[i] > maxi) // = ki jaroorat nhi hai, as All the values of preorder are unique
            return NULL;

        TreeNode* root = new TreeNode(preorder[i++]);

        // left aur right ke liye call kardo
        root->left = solve(preorder, root->val, i);
        root->right = solve(preorder, maxi, i);

        // root ko return kardo
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(preorder,INT_MAX,i);
    }
};