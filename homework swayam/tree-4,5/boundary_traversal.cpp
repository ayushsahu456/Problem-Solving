#include<bits/stdc++.h>
using namespace std;
 template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

void traverseleft(TreeNode<int>*root, vector<int>&ans){
    if(root==NULL){
        return ;
    }
    if(root->left==NULL && root->right==NULL){
        return;
    }
    ans.push_back(root->data);
    //root->left exist kre toh wahan jao
    if(root->left){
        traverseleft(root->left,ans);
    }
    //left exist na kre toh right me jao
    else{
        traverseleft(root->right , ans); // otherwise right me jao
    }
}

// leaf nodes ke liye 
void traverseleaf(TreeNode<int>*root , vector<int>&ans){
    //base case
    if(root==NULL){
        return ;
    }
    // left right dono null hai mtlb leaf node hai toh store krlo use
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    //recurssion
    traverseleaf(root->left, ans);
    traverseleaf(root->right, ans);
}

// right part print krne ke liye function
void traverseright(TreeNode<int>*root , vector<int>&ans){
    if((root==NULL)){
        return;
    }
    if(root->right==NULL && root->left==NULL){
        return;
    }
    if(root->right){
        traverseright(root->right,ans);
    }
    else{
        traverseright(root->left,ans );
    }
    ans.push_back(root->data);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    ans.push_back(root->data);

    //left part print
    traverseleft(root->left , ans);

    //leaf node of left subtree
    traverseleaf(root->left,ans);
    //leaf node of right subtree
    traverseleaf(root->right , ans);

    // right part print
    traverseright(root->right,ans);
    return ans;
    
}