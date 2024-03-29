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
    int height(TreeNode* root, int& ans)
    {
        if(root == NULL)
        return 0;
        //traverse left and right
        int left = height(root->left, ans);
        int right = height(root->right, ans);
        //get diameter =left height+ right height
        ans = max(ans, left + right);
        //return maximum of all diameter
        return 1 + max(left, right);  
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if(root == NULL)
        return 0;
        height(root, ans);
        return ans ;
    }
};