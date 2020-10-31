// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

#define ppi pair<int,pair<int,int>>
#define ff first
#define ss second
class Solution {
public:
	int kthSmallest(vector<vector<int>>& ar, int k) {
		int n = ar.size();
		priority_queue<ppi, vector<ppi>, greater<ppi>> minH;

		for (int i = 0; i < n; i++) {
			minH.push({ar[0][i], {0, i}});
		}

		int result = -1;
		while (k--) {
			int r = minH.top().ss.ff;
			int c = minH.top().ss.ss;

			result = minH.top().ff;

			minH.pop();

			if (r != n - 1) {
				minH.push({ar[r + 1][c], {r + 1, c}});
			}
		}
		return result;
	}
};