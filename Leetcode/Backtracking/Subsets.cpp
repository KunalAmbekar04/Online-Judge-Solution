// https://leetcode.com/problems/subsets/

class Solution {
	vector<vector<int>> result;

	void solve(vector<int> ar, vector<int> output, int k) {
		if (k == ar.size()) {
			result.push_back(output);
			return;
		}

		solve(ar, output, k + 1);
		output.push_back(ar[k]);
		solve(ar, output, k + 1);
	}

public:
	vector<vector<int>> subsets(vector<int>& ar) {
		vector<int> op;
		solve(ar, op, 0);
		return result;
	}
};