#include<bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };
int heightOfBinaryTree(TreeNode<int> *root)
{
	// Write your code here.
    if(root==NULL){
        return 0;
    }
    //get maximum from both the subtree and add 1 as root is there
    //root ko hum count kr lete h baaki recursion krega left,right tree me
    int ans=1+max(heightOfBinaryTree(root->left),heightOfBinaryTree(root->right));
    return ans;
}