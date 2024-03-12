#include <bits/stdc++.h>
using namespace std;

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
