// https://leetcode.com/problems/beautiful-arrangement/

class Solution {
	int count = 0;

	void solve(int *ar, int n, int idx = 0) {
		if (idx == n) {
			count++;
			return;
		}

		for (int i = idx; i < n; i++) {
			if (ar[i] % (idx + 1) == 0 || (idx + 1) % ar[i] == 0) {
				swap(ar[idx], ar[i]);
				solve(ar, n, idx + 1);
				swap(ar[i], ar[idx]);
			}
		}
	}
public:
	int countArrangement(int n) {
		int *ar = new int[n];
		for (int i = 0; i < n; i++) {
			ar[i] = i + 1;
		}

		solve(ar, n);

		return count;
	}
};