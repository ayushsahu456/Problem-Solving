#include <bits/stdc++.h>
using namespace std;
// 1: using brute force
int getmaximumsize(vector<int>& a, int s) {
    int n = a.size();
    int ans = 0;
    int sum = 0;
//iterate two loops if sum is less than s then  add the element to the sum
//and update ans with the max of ans , j-i+1(size of subarray)
//else break out the loop and return the subarray size
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if (sum <= s)
                ans= max(ans , j - i + 1);
            else
                break;
        }
    }
    return ans;
}

int main() {
    vector<int> a = {1, 3, 4, 2};
    int s = 7;
    int ans = getmaximumsize(a, s);
    cout << ans << endl;
    return 0;
}


//using sliding window
int getmaximumsize(vector<int>& nums,int target) {
        //initialize ans as maximum
        int ans=INT_MAX;
        //take variable for currsum
        int curr=0;
        //assign two pointers start and end
        int start=0,end=0;
        int n=nums.size();
        while(end<n){
            // keep adding elements from starting till it gets greater than target
            curr=curr+nums[end];
            while(curr>=target){
                //if curr summ is greater than the target than update ans
                //update ans as minimum of ans , curr subarray length(end-start+1)
                ans=min(ans,end-start+1);
                //shrink window remove elements from front of the window
                curr=curr-nums[start++];
            }
            //update end
            end++;
        }
        if(ans==INT_MAX){
            return 0;
        }
        return ans;
    }
