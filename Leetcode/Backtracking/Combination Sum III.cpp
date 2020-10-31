// https://leetcode.com/problems/combination-sum-iii/

class Solution {
	vector<vector<int>> result;

	int sumOfArr(vector<int> &ar) {
		int sum = 0;
		for (auto itr : ar) {
			sum += itr;
		}
		return sum;
	}

	void solve(vector<int> ar, int idx, int last_num, int k, int sum) {
		if (idx == k) {
			if (sumOfArr(ar) == sum) {
				result.push_back(ar);
			}
			return;
		}

		for (int i = last_num + 1; i <= 9; i++) {
			ar[idx] = i;
			solve(ar, idx + 1, i, k, sum);
			ar[idx] = 0;
		}
	}
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<int> ar(k);
		solve(ar, 0, 0, k, n);
		return result;
	}
};