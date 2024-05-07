#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        unordered_map<int, vector<pair<int,int>>> adj;
        
        // make adjacency list adjacency list
        for(auto &vec: edges){
            int u= vec[0];
            int v= vec[1];
            int w= vec[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // Priority queue  {weight, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        
        vector<int> ans(n, -1);
        vector<int> visited(n,0);
        
        // node 0 ko pq me daldo
        pq.push({0, 0});
        ans[0]= 0;
        
        //  apply Dijkstra's algorithm
        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            
            int currWt= it.first;
            int currNode= it.second;
            
            // Skip if already visited with a lower weight
            if (visited[currNode]==1) continue;
            visited[currNode] = 1;
            
            // travrse to its adjacent nodes
            for(auto &iter: adj[currNode]){
                int newWt = currWt + iter.second;
                // Update minimum time to reach node if it's not disappeared
                if (newWt < disappear[iter.first] && (ans[iter.first] == -1 || newWt < ans[iter.first])) {
                    pq.push({newWt, iter.first});
                    ans[iter.first]= newWt;
                }
            }
        }
        
        return ans;
    }
};