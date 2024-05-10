#include<bits/stdc++.h>
using namespace std;

// using recursion
// gives TLE
// class Solution {
// private:
//     int recursion(int prev,int curr,vector<int>& num){
//         int n=num.size();
//         int take=0;    
//         if(curr==n) {
//             return 0;
//         } // agar curr equal hai nums.size() ke to return 0;      
//         int notTake=0+recursion(prev,curr+1,num); 
//         if(prev==-1 || num[curr]>num[prev]){ //agar curr index wala prev se bada hai to we take it and check further 
//             take= 1+ recursion(curr,curr+1,num);     
//         }
//         return max(take,notTake); 
//     }
// public:
//     int lengthOfLIS(vector<int>& nums) {
//     return recursion(-1,0,nums);
//     }
// };

class Solution {
public:
//approach 1: bottom up
// TC=O(n^2)

//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         int dp[n];
//         int ans=1; //ans will be 1 coz there can be atleast one element
//         dp[0]=1; //we start from first element 
//         for(int i=1;i<n;i++){
//             int maxprevlis=0;
//             for(int j=0;j<=i-1;j++){
//                 //if any element before ith index is less than element at ith idx then it will contribute
//                 if(nums[i] > nums[j]){
//                     maxprevlis=max(maxprevlis,dp[j]);
//                 }
//             }
//             dp[i]=maxprevlis+1; //number of elements contribute to ith idx will be in maxprevlis
//             ans=max(ans,dp[i]); //ans will be max of all
//         }
//         return ans;
//     }
// };

//optimize above code using binary search
//TC=O(nlogn)
    int findidx(vector<int>&lis,int num){
        //apply binary search to find the index just greater than or equal to num
        int n=lis.size();
        int low=0;
        int high=n-1;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(lis[mid]==num){
                return mid;
            }
            if(lis[mid]>num){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int lengthOfLIS(vector<int>& nums){
        int n=nums.size();
        vector<int>lisstorage;
        lisstorage.push_back(nums[0]); //push first element to the vector
        for(int i=1;i<n;i++){
            //agar nums[i] bada hai lisstorage ke last element se to it will contribute to usko push krdo
            if(nums[i] > lisstorage[lisstorage.size()-1]){
                lisstorage.push_back(nums[i]);
            }
            else{
                //if nums[i] is small or equal 
                //then we will replace it with the lower bound of lisstorage 
                //finding the idx in lisstorage such tht element at tht idx is just greater than or equal to nums[i];
                int idx=findidx(lisstorage,nums[i]);
                lisstorage[idx]=nums[i]; //replace element at tht idx with nums[i]
            }
        }
        //now our longest increasing subsequence will be in lisstorage so
        return lisstorage.size();
    }
};