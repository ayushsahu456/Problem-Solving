#include<bits/stdc++.h>
using namespace std;
int minimumSize(vector<int>& nums, int maxOperations) {
        //search space will be from 1 to max element in array
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        //ans me hum maximum element dal dege
        int ans=high;
        while(low<=high){
            //we will assume mid as our penalty to count number of operations required
            int mid=(low+high)/2;
            int countop=0;//to count how many operation it is taking to minimize the penalty we assume as pout mid
            //blacbox function to count operation
            for(int i=0;i<nums.size();i++){
                //agar hamra nums[i] greater hoga penalty se to hi uspe operation lagega divide krne ke liye
                if(nums[i]>mid){
                    //agar wo exactly dic=visible hai penalty se 
                    //mtlb 6%3==0 (exactly divisible) to mtlb ek hi opertion lagega
                    if(nums[i]%mid==0){
                        countop+=(nums[i]/mid)-1;
                    }
                    else{
                    // agar completely divisible nai h to
                    countop+=nums[i]/mid;
                     }
                }
                
            }
            //if countop is less or equal maxoperation
            //then mid can be out answer so store it in ans
            if(countop<=maxOperations){
                ans=mid;
                //for more optimal result we will decrease out penalty
                //penalty kam krege to operations badege
                high=mid-1;
            }
            else{
                //agar countop zada hai to penalty ko bada denge jisse operations kam hojaye
                low=mid+1;
            }
        }
        return ans;
    }