// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> minH;

		for (auto itr : nums) {
			minH.push(itr);
			if (minH.size() > k) {
				minH.pop();
			}
		}
		return minH.top();
	}
};