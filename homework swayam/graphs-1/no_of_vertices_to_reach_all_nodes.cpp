#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>indeg(n,0); //to store indegrees
        for(int i=0;i<edges.size();i++){
            indeg[edges[i][1]]++;
        }
        vector<int>ans; //to store ans
        for(int i=0;i<n;i++){
            if(indeg[i]==0){ //agar indegrees 0 hai to ans me push krdo
                ans.push_back(i);
            }
        }
        return ans;
    }
};