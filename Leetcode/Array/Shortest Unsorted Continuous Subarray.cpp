// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
	int findUnsortedSubarray(vector<int>& ar) {
		int n = ar.size();
		int start = 0;
		int end = n - 1;

		while (start < n - 1 && ar[start] <= ar[start + 1]) {
			start++;
		}

		while (end > 0 && ar[end - 1] <= ar[end]) {
			end--;
		}

		if (start == n - 1) {
			return 0;
		}

		int minVal = ar[start];
		int maxVal = ar[start];

		for (int i = start; i <= end; i++) {
			minVal = min(minVal, ar[i]);
			maxVal = max(maxVal, ar[i]);
		}

		for (int i = 0; i < start; i++) {
			if (ar[i] > minVal) {
				start = i;
			}
		}

		for (int i = end + 1; i < n; i++) {
			if (ar[i] < maxVal) {
				end = i;
			}
		}

		return end - start + 1;
	}
};