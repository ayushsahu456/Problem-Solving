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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(root==NULL){
            return NULL;
        }
        //agar root either p or q hai to root return krdo
        if(root==p || root==q){
            return root;
        }
       // goto left and right nodes till we get p or q
        TreeNode* leftans=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightans=lowestCommonAncestor(root->right,p,q);
        //if both left and right is null it is answer return root
        if(leftans!=NULL && rightans!=NULL){
            return root;
        }
        //if right is null return left
        else if(leftans!=NULL && rightans==NULL){
            return leftans;
        }
        //if left is null return right
        else if(leftans==NULL && rightans!=NULL){
            return rightans;
        }
        else
            return NULL;
    }
};