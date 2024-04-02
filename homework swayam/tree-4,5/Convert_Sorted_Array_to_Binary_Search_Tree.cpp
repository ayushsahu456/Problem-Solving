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
    TreeNode* constructbst(vector<int>& nums,int start,int end){
        //if start>end
        if(start>end){
            return NULL;
        }
        //mid element will be our root element
        int middle=(start+end)/2;
        TreeNode* root=new TreeNode(nums[middle]);
        //same construct left and right subtree recursively
        root->left=constructbst(nums,start,middle-1);
        root->right=constructbst(nums,middle+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            //we have null vector
            return NULL;
        }
        //otherwise create a function by passing start and end index of the nums
        int start=0;
        int end=n-1;
        return constructbst(nums,start,end);
    }
};