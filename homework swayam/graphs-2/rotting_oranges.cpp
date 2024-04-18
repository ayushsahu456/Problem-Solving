#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        // {{row,col},time}
        queue<pair<pair<int, int>, int>> q;
        // make a visited matrix
        int vis[n][m];
        int countfresh = 0; // to keep count of fresh oranges in initial grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    // {{row,col},time}
                    q.push({{i, j}, 0});
                    // mark visited
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
                // mark fresh oranges
                if (grid[i][j] == 1) {
                    countfresh++;
                }
            }
        }

        int time = 0;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, 1, 0, -1};
        int count = 0; // to check for fresh oranges

        //do bfs traversal to mark all neighbours oranges as visited(rotten)
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();

            // check in all 4 possible directions
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                // check if all conditions are true
                // if yes then push it in queue and mark them as visited
                // and increase the count of fresh oranges
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    count++;
                }
            }
        }
        // check if any fresh oranges is remaining
        if (count != countfresh) {
            return -1;
        }

        return time;
    }
};