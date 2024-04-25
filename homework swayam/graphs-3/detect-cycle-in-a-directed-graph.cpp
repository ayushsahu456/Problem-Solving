#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    bool dfs(int node,vector<int>adj[],int vis[],int pathvis[]){
        vis[node]=1;
        pathvis[node]=1;
        //traverse
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathvis)==true)
                return true;
            }
            //if the node has visited previosly
            //but it has to be visited on same path
            else if(pathvis[it]){
                return true;
            }
        }
        pathvis[node]=0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int pathvis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis)==true){
                    return true;
                }
            }
        }
        return false;
    }
};

