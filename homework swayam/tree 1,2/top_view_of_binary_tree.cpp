#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};

//Back-end Complete function template for C++

class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        // base case
        if(root == NULL){
            return ans;
        }
        Node *temp = NULL;
        //creating queue for level order traversal.
        queue<pair<Node *, int>> q;
        //creating a map to store nodes at a particular horizontal distance.
        //map banayege jo nodes ko horizontal distance ke hisab se rakhega
        map<int, int> mp;
        //root ko 0 horizontal distance dege and root ke left walo ko -1,-2,-3... and so on
        //root ke right walo ko 1,2,3....
        q.push({root, 0});
        while(!q.empty())
        {
            temp = q.front().first;
            //d me distance(horizontal) store krlege
            int d = q.front().second;
            q.pop();   
            //store temp->data in map.
            if(mp.find(d) == mp.end()){
                mp[d] = temp->data;
            }
            //if left child of temp exists, pushing it in queue
            if(temp->left){
                q.push({temp->left, d-1});
            }
            //if right child of temp exists, pushing it in queue
            if(temp->right){
                q.push({temp->right, d+1});
            }
        }
        //har horizontal distance se nodes ko store krlege
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};