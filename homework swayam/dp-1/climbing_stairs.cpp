#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//approach 1:
    int solver(int n,vector<int>&dp){
        if(n==0 || n==1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        dp[n]=solver(n-1,dp)+solver(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solver(n,dp);
    }

    //approach 2:
    int climbStairs(int n) {
        if(n <= 2)
            return n;
        vector<int> dp(n + 1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i = 3; i <= n; i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }

    //approach 3:
    int climbStairs(int n) {
        //fibbonacci
        int x=1;
        int y=1;
        for(int i=2; i<= n ; i++){
          int temp=x;
            x=y;
            y=y+temp;
        }
       return y;
    }
};