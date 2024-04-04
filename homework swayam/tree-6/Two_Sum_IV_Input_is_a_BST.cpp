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
    //function for inorder
    void inorder(TreeNode* root,vector<int>&arr){
        if(root==NULL){
            return;
        }
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    //function for getting sum
    bool getsum(TreeNode* root, int k,vector<int>&arr){
        int n=arr.size();
        int low=0;
        int high=n-1;
        while(low<high){
            int sum=arr[low]+arr[high];
            if(sum==k){
                return true;
            }
            //if sum is less i.e. we need some bigger value so update low
            else if(sum<k){
                low++;
            }
            //if sum is high it means we need less value so decrease high
            else{
                high--;
            }
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        //first inorder traverse then store nodes value in a vector
        //then find the sum of nodes
        vector<int>nodes;
        inorder(root,nodes);
        return getsum(root,k,nodes);
    }
};