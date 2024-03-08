#include<bits/stdc++.h>
using namespace std;
int solve(int n, vector<int>& nums)
{
	int l = 0, h = nums.size() - 1, ans = nums.size();
	while (l <= h)
	{
		int m = l + (h - l) / 2;
		if (nums[m] >= n)
		{
			ans = m;
			h = m - 1;
		}
		else
			l = m + 1;
	}
	return ans;
}
int main()
{
	int n, q;
	cin >> n >> q;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	sort(nums.begin(), nums.end());
	for (int i = 0; i < q; i++)
	{
		int t;
		cin >> t;
		cout << n - solve(t, nums) << endl;
	}
	return 0;
}
