// https://leetcode.com/problems/combination-sum/

class Solution {
	vector<vector<int>> result;

	void solve(vector<int> &ar, int idx, vector<int> temp, int curr_sum, int target) {
		if (curr_sum == target) {
			result.push_back(temp);
			return;
		}

		for (int i = idx; i < ar.size(); i++) {
			if (curr_sum + ar[i] <= target) {
				temp.push_back(ar[i]);
				solve(ar, i, temp, curr_sum + ar[i], target);
				temp.pop_back();
			}
		}
	}
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> temp;
		solve(candidates, 0, temp, 0, target);
		return result;
	}
};