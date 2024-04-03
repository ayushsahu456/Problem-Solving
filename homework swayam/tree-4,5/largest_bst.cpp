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
class Solution{
    public:
    /*You are required to complete this method */
    bool isvalidate(Node *root, int min, int max){
        if (root == NULL){
            return true;
        }  
        if (min >= root->data || root->data >= max){
            return false;
        }
        return isvalidate(root->left, min, root->data) && isvalidate(root->right, root->data, max);
    }
    //function to count number of nodes
    int count(Node *root){
        if (root == NULL){
            return 0;
        }  
        return 1+count(root->left)+count(root->right);
    }
    int largestBst(Node *root) {
        if (root == NULL){
            return 0;
        }  
        //check if bst starts from root only
        if(isvalidate(root, INT_MIN, INT_MAX)){
            //if it is a valid bst then return its count
            return count(root);
        } 
        //if not in root check in left and right subtree
        int check_left=largestBst(root->left);
        int check_right=largestBst(root->right);
        //return largest from left and right
        return max(check_left, check_right);
    }
};