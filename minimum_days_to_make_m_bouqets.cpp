#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ek boolean function banaya jo batayega ki possible hai bhi ya nhi bana bouquets 
    bool isPossible(vector<int>&nums, int m, int k , int day){
        int count=0;
        //kitne number of bouquet bana skte hai
        int bouquet=0;
        //traverse nums array to check
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=day){
                count++;
            }
            else{
                bouquet+=(count/k);
                count=0;
            }
        }
        bouquet+=(count/k);
        if(bouquet>=m){
            return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // long long me convert krlo
        long long val= m*1LL *k * 1LL;
        //not possible
        if(val>bloomDay.size()){
            return -1;
        }
        int mini=INT_MAX , maxi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }
        int low=mini, high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(bloomDay,m,k,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return low;
    }
};