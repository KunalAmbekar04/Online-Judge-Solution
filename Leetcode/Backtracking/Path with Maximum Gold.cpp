// https://leetcode.com/problems/path-with-maximum-gold/

class Solution {
	int dr[4] = { -1, 0, 1, 0};
	int dc[4] = {0, 1, 0, -1};

	bool isSafe(vector<vector<int>>& grid, int r, int c) {
		int n = grid.size();
		int m = grid[0].size();

		if (r >= n || r < 0 || c >= m || c < 0 || grid[r][c] == 0) {
			return false;
		}

		return true;
	}

	int solve(vector<vector<int>>& grid, int r, int c) {
		int result = 0;
		int temp = grid[r][c];
		grid[r][c] = 0;
		for (int i = 0; i < 4; i++) {
			int x = r + dr[i];
			int y = c + dc[i];
			if (isSafe(grid, x, y)) {
				result = max(result, solve(grid, x, y));
			}
		}
		grid[r][c] = temp;

		return grid[r][c] + result;
	}

public:
	int getMaximumGold(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();

		int result = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] > 0) {
					result = max(result, solve(grid, i, j));
				}
			}
		}
		return result;
	}
};