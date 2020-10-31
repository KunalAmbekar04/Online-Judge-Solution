//https://leetcode.com/problems/rotate-array/

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int n = nums.size();

		k %= n;

		vector<int> res(nums.end() - k, nums.end());
		for (int i = 0; i < n - k; i++) {
			res.push_back(nums[i]);
		}

		nums.clear();
		nums = res;
	}
};