#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node,vector<int>adj[],vector<int>&visited){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<vector<int>>ans(n);
        //make adjacency list
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
        }

        //apply dfs
        for(int i=0;i<n;i++){
            vector<int>visited(n,0);  //visited vector
            dfs(i,adj,visited);

            for(int j=0;j<n;j++){
                if(i!=j && visited[j]){
                    ans[j].push_back(i);
                }
            }
        }
        return ans;
    }
};