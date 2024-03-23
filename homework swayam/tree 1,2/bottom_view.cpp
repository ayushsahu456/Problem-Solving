// C++ Program to print Bottom View of Binary Tree
#include<bits/stdc++.h>
using namespace std;

// Tree node class
struct Node
{
	int data; //data of the node
	int hd; //horizontal distance of the node
	Node *left, *right; //left and right references

	// Constructor of tree node
	Node(int key)
	{
		data = key;
		hd = INT_MAX;
		left = right = NULL;
	}
};

// Method that prints the bottom view.

//everything same as the top view
//bas map me baar baar update krdege horizontal distance pr jo value h usko 
void bottomView(Node *root)
{
	vector<int> ans;
        // base case
        if(root == NULL){
            return ;
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
            //dist me distance(horizontal) store krlege
            int dist = q.front().second;
            q.pop();   
            //store temp->data in map.
            //keep updating map value whenever we get a new value at tht distance
            //this is the only diff in bottom view and top view
                mp[dist] = temp->data;
            //if left child of temp exists, pushing it in queue
            if(temp->left){
                q.push({temp->left, dist-1});
            }
            //if right child of temp exists, pushing it in queue
            if(temp->right){
                q.push({temp->right, dist+1});
            }
        }
        //har horizontal distance se nodes ko store krlege
        for(auto i:mp){
            cout<<i.second<<" ";
        }
}

// Driver Code
int main()
{
	Node *root = new Node(20);
	root->left = new Node(8);
	root->right = new Node(22);
	root->left->left = new Node(5);
	root->left->right = new Node(3);
	root->right->left = new Node(4);
	root->right->right = new Node(25);
	root->left->right->left = new Node(10);
	root->left->right->right = new Node(14);
	cout << "Bottom view of the given binary tree :\n";
	bottomView(root);
	return 0;
}
