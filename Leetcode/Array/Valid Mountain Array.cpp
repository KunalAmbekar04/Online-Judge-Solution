// https://leetcode.com/problems/valid-mountain-array/

// Solution 1
class Solution {
public:
	bool validMountainArray(vector<int>& ar) {
		int n = ar.size();

		if (n < 3) {
			return false;
		}

		int peak = 0;
		int valley = 0;

		for (int i = 1; i < n - 1; i++) {
			if (ar[i - 1] < ar[i] && ar[i] > ar[i + 1]) {
				peak++;
			}
			else if (ar[i - 1] >= ar[i] && ar[i] <= ar[i + 1]) {
				valley++;
			}
		}

		if (peak == 1 && valley == 0) {
			return true;
		}
		return false;
	}
};

// Solution 2
class Solution {
public:
	bool validMountainArray(vector<int>& ar) {
		int n = ar.size();
		int i = 1;

		while (i < n) {
			if (ar[i - 1] < ar[i]) {
				i++;
			}
			else {
				break;
			}
		}

		if (i == 1 || i == n) {
			return false;
		}

		while (i < n) {
			if (ar[i - 1] > ar[i]) {
				i++;
			}
			else {
				break;
			}
		}

		if (i == n) {
			return true;
		}
		return false;
	}
};