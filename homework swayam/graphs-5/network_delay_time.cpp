#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // make adjacency list 
        vector<pair<int,int>> adj[n + 1];
        
        // Construct the adjacency list from the given 'times' vector
        for(auto it : times){
            int u = it[0]; 
            int v = it[1]; 
            int wt = it[2]; 
            adj[u].push_back({v, wt});
        }

        // Create a priority queue 
        // {weight,node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // k ko push krdo pq me
        pq.push({0 , k});

        // 
        vector<int> dist(n+1 , INT_MAX);
        dist[k] = 0; 

        // Dijkstra's algorithm
        while(!pq.empty()){
            int time = pq.top().first; 
            int node = pq.top().second; 
            pq.pop();

            // Iterate over all adjacent nodes 
            for(auto it : adj[node]){
                int neighbour = it.first; 
                int wt = it.second; 

                if(time + wt < dist[neighbour]){
                    dist[neighbour] = time + wt;
                    pq.push({dist[neighbour] , neighbour });
                }
            }  
        }
        int ans = *max_element(dist.begin()+1 , dist.end() );
        return ans == INT_MAX ? -1 : ans;
    }
};