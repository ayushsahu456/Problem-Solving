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
class solution{
public:
void solve(TreeNode*root,vector<vector<int>>&ans,vector<int>&v,int target){
        if(root!=nullptr){
            //v me root ka value daldo
            v.push_back(root->val);
            //agr left right node null hai and root ka value sum ke equal hai to (v) ans me daldo
            if(root->left==nullptr && root->right==nullptr && root->val==target){
                ans.push_back(v);
            }
            // right subtree me sum dhundho
            solve(root->left,ans,v,target-root->val);
            // left suntree me sum dhudho
            solve(root->right,ans,v,target-root->val);
            //agar nai milta h sum to v me se last node nikal do 
            v.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>v;
        solve(root,ans,v,targetSum);
        return ans;
    }
};