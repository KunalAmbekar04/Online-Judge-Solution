// https://leetcode.com/problems/find-pivot-index/

// Solution 1
class Solution {
public:
	int pivotIndex(vector<int>& ar) {
		int n = ar.size();

		if (n == 0) {
			return -1;
		}

		int rsum = 0;
		for (int i = 0; i < n; i++) {
			rsum += ar[i];
		}

		int lsum = 0;
		for (int i = 0; i < n; i++) {
			rsum -= ar[i];
			if (rsum == lsum) {
				return i;
			}
			lsum += ar[i];
		}
		return -1;
	}
};


// Solution 2 - Using Suffix n Prefix Array
class Solution {
public:
	int pivotIndex(vector<int>& ar) {
		int n = ar.size();

		if (n == 0) {
			return -1;
		}

		int *suff = new int[n];
		int *pref = new int[n];

		pref[0] = ar[0];
		suff[n - 1] = ar[n - 1];

		for (int i = 1; i < n; i++) {
			pref[i] = pref[i - 1] + ar[i];
		}

		for (int i = n - 2; i >= 0; i--) {
			suff[i] = suff[i + 1] + ar[i];
		}

		for (int i = 0; i < n; i++) {
			if (suff[i] == pref[i]) {
				return i;
			}
		}
		return -1;
	}
};