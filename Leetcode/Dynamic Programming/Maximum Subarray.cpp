// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
	int maxSubArray(vector<int>& ar) {
		int sum = INT_MIN;
		int max_so_far = 0;

		int n = ar.size();
		for (int i = 0; i < n; i++) {
			max_so_far += ar[i];
			sum = max(sum, max_so_far);
			if (max_so_far < 0) {
				max_so_far = 0;
			}
		}
		return sum;
	}
};