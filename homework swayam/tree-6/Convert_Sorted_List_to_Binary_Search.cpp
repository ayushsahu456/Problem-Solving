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
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        //get the mid element from the list and make it as root of bst
        //then recursively for left and right subpart of list for left and right nodes
        if(head==NULL){
            return NULL;
        }
        ListNode* prev=NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        //get mid element
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        //make mid as our root for bst
        TreeNode* root=new TreeNode(slow->val);
        //if there is only one element in list
        if(slow==head){
            return root;
        }
        //make prev ka next as NULL to get the left subpart of the list
        prev->next=NULL;
        //make left and right node of bst by recursively getting mid from left and right subpart
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(slow->next);

        return root;
    }
};