#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        //make an adjacency list
        for(auto x:prerequisites){
            adj[x[1]].push_back(x[0]);
        }
        //get all indegrees
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        //jis jis ki indegree 1 hai unko queue me push krdo
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //apply bfs (toposort)
        int count=0;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            count++;
            for(auto it:adj[front]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        //if cycle hogi to count n ke equal nai hoga
        return count==n;
    }
};