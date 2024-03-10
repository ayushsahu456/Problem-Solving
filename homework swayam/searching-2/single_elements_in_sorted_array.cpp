#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        //if size=1
        if(n==1){
            return nums[0];
        }
        //if the first element is the answer
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        //if last element is the answer
        if(nums[n-1]!=nums[n-2]){
            return nums[n-1];
        }
        int low=0;
        int high=n-1;
        while(low<=high){
            //calculate mid
            int mid=(low+high)/2;
            //check if mid is our answer
            if(nums[mid] != nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            //same occurences are in pairs
            //first occurence is always even
            //second occurence is odd
            //if all the even odd occurences are true then our answer is in right part
            if(mid%2==1 && nums[mid-1]==nums[mid] || mid%2==0 && nums[mid+1]==nums[mid] ){
                low=mid+1;
            }
            // else our answer will be in left part if the even odd order is breaked
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};