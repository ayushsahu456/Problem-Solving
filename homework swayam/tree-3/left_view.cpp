#include<bits/stdc++.h>
using namespace std;
// using recursion
void getleftview(BinaryTreeNode<int>* root , vector<int>&ans,int level){
    if(root==NULL){
        return;
    }
    if(ans.size()<level){
        //value daldo ans me 
        ans.push_back(root->data);
        //goto left node then right
    }
    getleftview(root->left, ans, level+1);
    getleftview(root->right, ans, level+1);
}
vector<int> printLeftView(BinaryTreeNode<int>* root) {
    // Write your code here.
    vector<int> ans;//left view ko store krne ke liye
    getleftview(root,ans,1);//pass root , ans vector , level
    return ans;
}

// using level order traversal
void getleftview(vector<vector<int>> ans , vector<int>&leftview){
    int n=ans.size();
    for(auto i:ans){
        //get the first level and store its first value to leftview
        vector<int>temp=i;
        leftview.push_back(temp[0]);
    }
}
vector<int> printLeftView(BinaryTreeNode<int>* root) {
    // Write your code here.
    vector<vector<int>> ans;//to store level order traversal
    vector<int>leftview;//to store left view
   if(root==NULL)
   return leftview;

        queue<BinaryTreeNode<int>*>q;
        q.push(root);
        
        while(!q.empty()){
            int n=q.size();
            vector<int>temp;
            for(int i=0;i<n;i++){
                BinaryTreeNode<int>*curr=q.front();
                q.pop();
                temp.push_back(curr->data);

                if(curr->left!=NULL)
                 q.push(curr->left);
                if(curr->right!=NULL)
                 q.push(curr->right);
            }
            ans.push_back(temp);
        }
        //call function to get all value at first index(left value) values from ans vector
        
        getleftview(ans,leftview);
        return leftview;
}