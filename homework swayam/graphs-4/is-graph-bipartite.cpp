#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node,int col,vector<vector<int>>& graph,int color[]){
        color[node]=col;
        //traverse adjacent nodes
        for(auto it:graph[node]){
            // if uncoloured
            if(color[it] == -1) {
                if(dfs(it,!col,graph,color)==false) return false; 
            }
            // if previously coloured and have the same colour
            else if(color[it] == col) {
                return false; 
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int color[n];
        for(int i=0;i<n;i++){
            color[i]=-1;
        }
        //traverse and mark using dfs
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,graph,color)==false){
                    return false;
                }
            }
        }
        return true;
    }
};