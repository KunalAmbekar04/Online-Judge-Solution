// https://leetcode.com/problems/toeplitz-matrix/

class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& ar) {
		int n = ar.size();
		int m = ar[0].size();

		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m - 1; j++) {
				if (ar[i][j] != ar[i + 1][j + 1]) {
					return false;
				}
			}
		}
		return true;
	}
};