// https://leetcode.com/problems/permutations-ii/

class Solution {
	set<vector<int>> ans;

	void solve(vector<int> &ar, int idx) {
		if (ar.size() == idx) {
			ans.insert(ar);
			return;
		}

		for (int i = idx; i < ar.size(); i++) {
			swap(ar[idx], ar[i]);
			solve(ar, idx + 1);
			swap(ar[i], ar[idx]);
		}
	}
public:
	vector<vector<int>> permuteUnique(vector<int> &ar) {
		solve(ar, 0);

		vector<vector<int>> result;
		for (auto itr : ans) {
			result.push_back(itr);
		}

		return result;
	}
};