#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>vis(n,0);
        //make adjacency list
        map<int,vector<int>>mp;
        for(auto i:edges){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        //apply bfs traversal
        queue<int>q;
        vis[source]=1;
        q.push(source);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            vis[node]=1;

            for(auto it:mp[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        if(vis[destination]==0){
            return false;
        }
        return true;
    }
};