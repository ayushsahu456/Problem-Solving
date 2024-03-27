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
    void solve(TreeNode* root, int k, int &count, vector<int> path) {
        //base case
        if(root == NULL)
            return ;
        
        path.push_back(root->val);
        
        //left
        solve(root->left, k, count, path);
        //right
        solve(root->right, k, count, path);
        //sum check krege kya wo k ke equal hai
        
        int size = path.size();
        long long sum = 0;
        for(int i = size-1; i>=0; i--)  {
            sum += path[i];
            //agar equal hai to count bada dege as ek path mil gya hai
            if(sum == k)
                count++;
        }
        //path vector ko khali krdege agle path ke liye
        path.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        int count = 0;
        solve(root, targetSum, count, path);
        return count;
    }
};