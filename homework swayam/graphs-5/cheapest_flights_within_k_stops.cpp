#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        //make adjacency list
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        //{stops,{node,dist}}
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        dist[src]=0;
        //dijkstra
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            //agar stops k se zada hogye to continue 
            if(stops>k) continue;
            for(auto iter:adj[node]){
                int adjnode=iter.first;
                int edw=iter.second;
                //agar cost + edw prev dist se chota hai and stops k se chota ya barabar hai to update krdege
                if(cost+edw < dist[adjnode] && stops<=k){
                    dist[adjnode]=cost+edw;
                    q.push({stops+1,{adjnode , cost+edw}});
                }
            }
        }
        
        if(dist[dst]==1e9) return -1;
        
        return dist[dst];
    }
};