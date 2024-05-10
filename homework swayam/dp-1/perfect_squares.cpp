#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//approach 1:
    int numSquares(int n) {
        int dp[n+1];
        for(int i=0;i<n+1;i++){
            dp[i] = 1e9;
        }
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i],1+dp[i-j*j]);
            }
        }
        return dp[n];
    }

    //approach 2:
    int arr[10001];
    int solve(int n){
        if(n==0)
        return 0;
        if(arr[n]!=-1){
            return arr[n];
        }
        int minC=INT_MAX;
        for(int i=1; i*i <= n ;i++){
            int result=1+solve(n-i*i);
            minC= min(minC,result);
        }
        return arr[n] = minC;
    }
    int numSquares(int n) {
        memset(arr, -1, sizeof(arr));
        return solve(n);
    }
};