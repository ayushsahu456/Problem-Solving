#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
}; 

class Solution{
  public:
    /*You are required to complete this function*/
    int getLevelDiff(Node *root)
    {
       //Your code here
       //use level order traversal
       if(root==NULL){
           return 0;
       }
       int sumeven=0;
       int sumodd=0;
       queue<Node*>q;
       //hum pehle sari nodes ki value ko level wise arrange krde ek vector me
       //then us vector ko traverse krke summ nikal lege even and odd index pr
       vector<vector<int>> levelorder;
       q.push(root);
       while(!q.empty()){
           int n=q.size();
           vector<int> temp;
           //get sum of all value
           for(int i=0;i<n;i++){
               Node* curr=q.front();
               q.pop();
               temp.push_back(curr->data);
               //go to left node if exist
               if(curr->left){
                   q.push(curr->left);
               }
               //go to right node if it exist
               if(curr->right){
                   q.push(curr->right);
               }
           }
           levelorder.push_back(temp);
       }
       //now calculate sum of nodes
       //asumming that first level is 0 jo ki even hai
       for(int i=0;i<levelorder.size();i++){
           if(i%2==0){
               sumeven+=accumulate(levelorder[i].begin() , levelorder[i].end(),0);
           }
           else{
               sumodd+=accumulate(levelorder[i].begin() , levelorder[i].end(),0);
           }
       }
       return sumeven-sumodd;
    }
};