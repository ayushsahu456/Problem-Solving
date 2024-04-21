#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int,set<pair<int,int>>> mp;
    int n,m;
    bool dfs(vector<vector<int>>& v, int r, int c, vector<vector<int>>&vis){
        vis[r][c]=1;
        if(r==n-1 && c==m-1) return true;
        
        for(auto i:mp[v[r][c]]){
            int nr=r+i.first;
            int nc=c+i.second;
            if(nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc]==0 && mp[v[nr][nc]].find({-1*i.first,-1*i.second})!=mp[v[nr][nc]].end()){
                //if current node has right than its child must have left and so on
                if(dfs(v,nr,nc,vis)) return true;
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        //map all possible 6 directions given 
        mp[1]={{0,-1},{0,1}};
        mp[2]={{-1,0},{1,0}};
        mp[3]={{0,-1},{1,0}};
        mp[4]={{0,1},{1,0}};
        mp[5]={{0,-1},{-1,0}};
        mp[6]={{0,1},{-1,0}};
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        return dfs(grid,0,0,vis);
    }
    
};