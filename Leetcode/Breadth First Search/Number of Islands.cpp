// https://leetcode.com/problems/number-of-islands/

class Solution {
	int dr[4] = { -1, 0, 1, 0};
	int dc[4] = {0, 1, 0, -1};

	bool isSafe(vector<vector<char>>& grid, int r, int c) {
		int n = grid.size();
		int m = grid[0].size();

		if (r < 0 || r >= n || c < 0 || c >= m) {
			return false;
		}

		if (grid[r][c] == '0') {
			return false;
		}

		return true;
	}

	void dfs(vector<vector<char>>& grid, int r, int c) {
		grid[r][c] = '0';

		for (int i = 0; i < 4; i++) {
			if (isSafe(grid, r + dr[i], c + dc[i])) {
				dfs(grid, r + dr[i], c + dc[i]);
			}
		}
	}
public:
	int numIslands(vector<vector<char>>& grid) {
		int cc = 0;

		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == '1') {
					dfs(grid, i, j);
					cc++;
				}
			}
		}

		return cc;
	}
};