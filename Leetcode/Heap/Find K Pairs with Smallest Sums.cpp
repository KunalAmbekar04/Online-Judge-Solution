// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

#define ppi pair<int,pair<int,int>>
#define ff first
#define ss second
class Solution {
public:
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		int n = nums1.size();
		int m = nums2.size();
		priority_queue<ppi> maxH;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int sum = nums1[i] + nums2[j];
				if (maxH.size() < k) {
					maxH.push({sum, {nums1[i], nums2[j]}});
				}
				else if (sum < maxH.top().ff) {
					maxH.pop();
					maxH.push({sum, {nums1[i], nums2[j]}});
				}
			}
		}

		vector<vector<int>> result;
		while (!maxH.empty()) {
			result.push_back({maxH.top().ss.ff, maxH.top().ss.ss});
			maxH.pop();
		}

		reverse(result.begin(), result.end());

		return result;
	}
};