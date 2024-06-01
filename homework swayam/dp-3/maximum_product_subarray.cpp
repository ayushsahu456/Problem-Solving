#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int mini=1;
        int maxi=1;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                swap(maxi,mini);
            }
            maxi=max(maxi*nums[i] , nums[i]);
            mini=min(mini*nums[i] , nums[i]);
            ans=max(ans,maxi);
        }
        return ans;
    }
};