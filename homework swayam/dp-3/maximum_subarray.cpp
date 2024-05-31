#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sumcurrent=0;
        int summax=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sumcurrent=sumcurrent+nums[i];
            if(sumcurrent>summax){
                summax=sumcurrent;
            }
            if(sumcurrent<0){
                sumcurrent=0;
            }
        }
        return summax;
    }
};