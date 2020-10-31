// https://leetcode.com/problems/k-closest-points-to-origin/

#define pip pair<int,pair<int,int>>
#define ff first
#define ss second
class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
		int n = points.size();
		priority_queue<pip> maxH;

		for (int i = 0; i < n; i++) {
			int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
			maxH.push({dist, {points[i][0], points[i][1]}});
			if (maxH.size() > k) {
				maxH.pop();
			}
		}

		vector<vector<int>> result;
		while (!maxH.empty()) {
			result.push_back({maxH.top().ss.ff, maxH.top().ss.ss});
			maxH.pop();
		}

		return result;
	}
};
