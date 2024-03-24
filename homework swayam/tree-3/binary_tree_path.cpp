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

void solve(TreeNode* root,vector<string> &ans,string s)
{
     if(root==NULL)
         return;
    //node ko string me convert krke "->" sath add krdo
    s = s+to_string(root->val);
    s = s+"->";
    if(root->left==NULL && root->right==NULL)
    {
        //agar wo leaf node hai to -> erase krdo last se
       s.erase(s.length()-2);
       ans.push_back(s);
       return;
    }
    //go to left and right
        solve(root->left,ans,s);
        solve(root->right,ans,s);
    
}
vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s="";
        // getpath(ans,root,s);
        solve(root,ans,s);
        return ans;    
}
