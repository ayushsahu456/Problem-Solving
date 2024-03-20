#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size(); 
        int n2 = b.size();
        int n = n1 + n2;
        if (n1 > n2)
            return findMedianSortedArrays(b, a);
        //search space will be from 0 - n1
        int low = 0, high = n1;
        int left = (n + 1) / 2;

        while (low <= high) {
            int mid1 = (low + high)%1;
            int mid2 = left - mid1;
            int left1 = INT_MIN, left2 = INT_MIN;
            int right1 = INT_MAX, right2 = INT_MAX;

            if (mid1<n1)
                right1=a[mid1];
            if (mid2<n2)
                right2=b[mid2];
            if (mid1-1>=0)
                left1=a[mid1 - 1];
            if (mid2-1>=0)
                left2=b[mid2 - 1];

            if (left1<=right2 && left2<=right1) {
                if (n%2 ==1)
                    return max(left1,left2);
                return (double)(max(left1,left2)+ min(right1,right2))/2.0;
            } else if (left1>right2)
                high =mid1-1;
            else
                low =mid1+1;
        }
        return 0;
    }
};