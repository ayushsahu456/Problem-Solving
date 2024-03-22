#include<bits/stdc++.h>
using namespace std;

int solve(int a[MAX][MAX], int n, int mid)
{
    int count = 0;
    int i = n - 1;
    int j = 0;

    while (i >= 0 && j < n)
    {
        if (a[i][j] <= mid){
            count += (i + 1);
            j++;
        }
        else i--;
    }
    return count;
}
int kthSmallest(int matrix[MAX][MAX], int n, int k)
{
    //Your code here
    int low = matrix[0][0];
    int high = matrix[n - 1][n - 1];

    while (low < high){
        int mid = low + (high - low) / 2;
        int count = solve(matrix, n, mid);
        // agar count k se chota hai to hum larger value lege goto right part
        if (count < k) 
            low = mid + 1;
        //else goto smaller value left part including mid
        else
            high = mid;
    }
    return low;
}