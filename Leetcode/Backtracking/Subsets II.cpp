// https://leetcode.com/problems/subsets-ii/

class Solution {
	set<vector<int>> no_duplicate;

	void solve(vector<int> ar, vector<int> output, int k) {
		if (k == ar.size()) {
			no_duplicate.insert(output);
			return;
		}

		solve(ar, output, k + 1);
		output.push_back(ar[k]);
		solve(ar, output, k + 1);
	}

public:
	vector<vector<int>> subsetsWithDup(vector<int>& ar) {
		vector<int> op;
		sort(ar.begin(), ar.end());
		solve(ar, op, 0);
		vector<vector<int>> result(no_duplicate.begin(), no_duplicate.end());
		return result;
	}
};