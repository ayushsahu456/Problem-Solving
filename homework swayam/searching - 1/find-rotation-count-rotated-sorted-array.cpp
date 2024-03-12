#include <bits/stdc++.h> 
using namespace std; 
  
int countRotations(int arr[], int n) 
{ 
    int low = 0, high = n - 1; 
    if (arr[low] <= arr[high]) 
        return 0; 
        
    while (low <= high){ 
        int mid = low + (high - low) / 2; 
        int prev = (mid - 1 + n) % n; 
        int next = (mid + 1) % n; 
        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]) 
            return mid; 
        else if (arr[mid] <= arr[high]) 
         high = mid - 1; 
        else if (arr[mid] >= arr[0]) 
            low = mid + 1; 
    } 
    return 0; 
} 