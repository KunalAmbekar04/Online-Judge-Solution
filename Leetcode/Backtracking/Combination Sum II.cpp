// https://leetcode.com/problems/combination-sum-ii/

class Solution {
	set<vector<int>> ans;

	void solve(vector<int> &ar, int idx, vector<int> temp, int curr_sum, int target) {
		if (curr_sum == target) {
			ans.insert(temp);
			return;
		}

		for (int i = idx; i < ar.size(); i++) {
			if (i > idx && ar[i] == ar[i - 1]) {
				continue;
			}

			if (curr_sum + ar[i] <= target) {
				temp.push_back(ar[i]);
				solve(ar, i + 1, temp, curr_sum + ar[i], target);
				temp.pop_back();
			}
		}
	}

public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<int> temp;
		solve(candidates, 0, temp, 0, target);
		vector<vector<int>> result;
		for (auto itr : ans) {
			result.push_back(itr);
		}
		return result;
	}
};