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
class Solution
{
    public:
    map<int,bool>mp;
    //function to fill map
    void getnodes(Node*root1){
        if(root1==NULL){
            return;
        }
        //inorder 
        getnodes(root1->left);
        //mark node as true
        mp[root1->data]=true;
        getnodes(root1->right);
    }
    
    //function to get answer
    void getans(Node*root2,vector<int>& ans){
        if(root2==NULL){
            return;
        }
        //inorder
        getans(root2->left,ans);
        //if root ki data ki value true hai means it is common then store it in ans
        if(mp[root2->data]==true){
            ans.push_back(root2->data);
        }
        getans(root2->right,ans);
    }
    
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
     vector<int>ans;
     //inorder traversal in bst gives nodes in sorted order
     //store nodes of first trees in a map and mark them as true
     getnodes(root1);
     //now traverse(inorder) in second tree and check if node value in map is true store it in ans
     getans(root2,ans);
     return ans;
    }
};