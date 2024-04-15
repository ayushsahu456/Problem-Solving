#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<int>adj[]) {
        vis[node] = 1;
        // iterate in adjacency list
        for (auto it : adj[node]) {
            if (!vis[it])
                dfs(it, vis, adj);
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // vector to store visited nodes
        vector<int> vis(n+1, 0);
        // make adjacency list
        vector<int> adj[n + 1];
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[0].size(); j++) {
                if (isConnected[i][j]) {
                    adj[i + 1].push_back(j + 1);
                }
            }
        }
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                // jaha se unvisited node hogi waha se naya province chalu hoga
                count++;
                dfs(i, vis, adj);
            }
        }
        return count;
    }
};