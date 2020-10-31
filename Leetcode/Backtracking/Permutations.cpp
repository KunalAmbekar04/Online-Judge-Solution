// https://leetcode.com/problems/permutations/

class Solution {
	vector<vector<int>> result;

	void solve(vector<int>& ar, int idx, vector<int> output) {
		if (idx == ar.size()) {
			result.push_back(output);
			return;
		}

		for (int i = 0; i <= output.size(); i++) {
			output.insert(output.begin() + i, ar[idx]);
			solve(ar, idx + 1, output);
			output.erase(output.begin() + i);
		}
	}
public:
	vector<vector<int>> permute(vector<int>& ar) {
		vector<int> output;
		solve(ar, 0, output);

		return result;
	}
};