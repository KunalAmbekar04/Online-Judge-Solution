// https://leetcode.com/problems/combinations/

class Solution {
	vector<vector<int>> result;

	void solve(int n, int k, vector<int> ar, int idx) {
		if (ar.size() == k) {
			result.push_back(ar);
			return;
		}

		for (int i = idx; i <= n; i++) {
			ar.push_back(i);
			solve(n, k, ar, i + 1);
			ar.pop_back();
		}
	}
public:
	vector<vector<int>> combine(int n, int k) {
		vector<int> temp;
		solve(n, k, temp, 1);

		return result;
	}
};