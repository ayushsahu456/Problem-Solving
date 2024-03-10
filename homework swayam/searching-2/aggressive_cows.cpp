//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool ispossible(vector<int>& position , int gap,int m){
        int prev=position[0];
        m--;
        for(int i=1;i<position.size();i++){
            if(position[i]-prev>=gap){
                m--;
                prev=position[i];
            }
            if(m==0){
                return true;
            }
        }
        return false;
    }
    
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        // min possible distance.. 0 is min possible logically if all balls placed at the same place.
        int l=1; 
        // this is max possible distance 
        int r=stalls[n-1]-stalls[0];
        //we initialize our ans = 0 since it is min possible
        int ans=0;  
        while(l<=r){
            int mid=(l+r)/2;
            // check if it is possible to arrange m balls with keeping atleast 'mid' distance between them
            if(ispossible(stalls,mid,k)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends