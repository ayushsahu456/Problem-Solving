#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*left;
    Node*right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void inorder(Node*root,vector<int>&nodes){
    if(root==NULL){
        return;
    }
    inorder(root->left,nodes);
    nodes.push_back(root->data);
    inorder(root->right,nodes);
}
// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {
    // Your code here
    if (root == NULL)
    return -1;
    // as inorder traversal will give us nodes in sorted order we can easily apply binary search
    vector<int>nodes;
    inorder(root,nodes);
    int n=nodes.size();
    int low=0;
    int high=n-1;
    int ans=-1;
    //apply binary search
    while(low<=high){
        int mid=(low+high)/2;
        if(nodes[mid]==input){
            return nodes[mid];
        }
        //if mid > input store it in ans ans search for more optimum result
        //go to left part
        else if(nodes[mid]>input){
            ans=nodes[mid];
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}