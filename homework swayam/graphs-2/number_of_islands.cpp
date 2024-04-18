#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>&vis,int row,int col){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        //get all possible 4 directions
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            //check all conditions
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1'){
                dfs(grid,vis,nrow,ncol);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0; //to store number of islands
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    count++;
                    dfs(grid,vis,i,j);
                }
            }
        }

        return count;
    }
};