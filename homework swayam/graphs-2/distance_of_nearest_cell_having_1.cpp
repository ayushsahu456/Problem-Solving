#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    
	    vector<vector<int>>vis(n,vector<int>(m,0)); //visited matrix
	    vector<vector<int>>dist(n,vector<int>(m,0)); //matrix to store ans or say distance
	    // {{row,col},step}
	    queue<pair<pair<int,int>,int>>q;
	    //get all starting positions
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            //push all starting nodes in a queue (starting nodes i.e. all 1)
	            if(grid[i][j]==1){
	               // {{row,col},steps}
	                q.push({{ i,j } , 0});
	                vis[i][j]=1;
	            }
	            else{
	                vis[i][j]=0;
	            }
	        }
	    }
	    
	    int delrow[]={-1,0,+1,0};
	    int delcol[]={0,+1,0,-1};
	    while(!q.empty()){
	        int row=q.front().first.first;
	        int col=q.front().first.second;
	        int steps=q.front().second;
	        q.pop();
	        //now insert the steps of row,col in the dist
	        dist[row][col]=steps;
	        
	        for(int i=0;i<4;i++){
	            int nrow=row+delrow[i];
	            int ncol=col+delcol[i];
	            //check all conditions and agar visited nrow,ncol 0 hai to step+1 krke push krdo
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
	                vis[nrow][ncol]=1;
	                q.push({{ nrow,ncol } , steps+1 });
	            }
	        }
	    }
	    return dist;
	}
};