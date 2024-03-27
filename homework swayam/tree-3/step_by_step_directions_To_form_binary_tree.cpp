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
    bool getpath(TreeNode* root, int tar, string& path){

        if(root==NULL) 
            return false;
        if(root->val==tar)
            return true;
        //left jao agar left exist krta hai to L ko append krdo
        bool left = getpath(root->left,tar,path);
        if(left){
            path += 'L';
            return true;
        }
        //same for right append R
        bool right = getpath(root->right,tar,path);
        if(right){
            path += 'R';
            return true;
        }

        return false;

    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        //root to startvalue ka path nikal lege
        //path reversed order me hoge mtlb startvalue to root hoge
        string pathstart = "";
        getpath(root,startValue,pathstart);
        //root to destination value ka path nikal lege
        string pathdest = "";
        getpath(root,destValue,pathdest);
        //dono ke path me se common elements alag krdege as wo start to dest ka hissa nai hai
        int i=pathstart.size()-1;
        int j=pathdest.size()-1;
        while(i>=0 && j>=0 && pathstart[i]==pathdest[j]){
            pathstart.pop_back();
            pathdest.pop_back();
            i--;
            j--;
        }
        //ab start value se lca tk jaane ke liye U operation krna padega to sare value U krdo
        i = pathstart.size();
        for(int j=0; j<i; j++){
            pathstart[j] = 'U';
        }
        //lca se destination wali value reverse krdo kyuki pathdest me value dest to lca tak hai
        reverse(pathdest.begin(),pathdest.end());
        //start to lca ki value + lca se destination ki value equal answer
        return pathstart + pathdest;
    }
};