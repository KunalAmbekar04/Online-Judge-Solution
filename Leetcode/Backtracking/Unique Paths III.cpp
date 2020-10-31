// https://leetcode.com/problems/unique-paths-iii/

class Solution {
	int dr[4] = { -1, 0, 1, 0};
	int dc[4] = {0, 1, 0, -1};

	int solve(vector<vector<int>>& grid, int r, int c, int zero) {
		int n = grid.size();
		int m = grid[0].size();

		if (r < 0 || r >= n || c < 0 || c >= m) {
			return 0;
		}

		if (grid[r][c] == -1) {
			return 0;
		}

		if (grid[r][c] == 2) {
			return zero == 0;
		}

		grid[r][c] = -1;
		int path = 0;
		for (int i = 0; i < 4; i++) {
			path += solve(grid, r + dr[i], c + dc[i], zero - 1);
		}
		grid[r][c] = 0;
		return path;
	}
public:
	int uniquePathsIII(vector<vector<int>>& grid) {
		int sx = -1;
		int sy = -1;
		int zero = 1;

		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 1) {
					sx = i;
					sy = j;
				}
				else if (grid[i][j] == 0) {
					zero++;
				}
			}
		}

		return solve(grid, sx, sy, zero);

	}
};