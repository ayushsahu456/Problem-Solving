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
    int findBottomLeftValue(TreeNode* root) {
        //we use level order traversal
        queue<TreeNode*> q;
        //first insert root node in the queue;
        q.push(root);
        // create a ans node tht stores the ans
        TreeNode* ans=NULL;
        while(!q.empty()){
            // assign queue front to ans
            ans=q.front();
            // pop it
            q.pop();
            // if ans right exists put it in queue same for left
            if(ans->right){
                q.push(ans->right);
            }
            // check left after right so tht left node will be the last node
            if(ans->left){
                q.push(ans->left);
            }
        }
        // return ans value
        return ans->val;
    }
};