// https://leetcode.com/problems/shortest-path-in-binary-matrix/

class Solution {
	int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1};
	int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

	bool isSafe(vector<vector<int>>& grid, int r, int c) {
		int n = grid.size();

		if (r < 0 || r == n || c < 0 || c == n || grid[r][c] != 0) {
			return false;
		}
		return true;
	}

public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		int n = grid.size();

		if (grid[0][0] || grid[n - 1][n - 1]) {
			return -1;
		}

		list<pair<int, int>> q;
		q.push_back({0, 0});
		grid[0][0] = 1;

		while (!q.empty()) {
			int sz = q.size();

			for (int i = 0; i < sz; i++) {
				int r = q.front().first;
				int c = q.front().second;

				q.pop_front();

				if (r == n - 1 && c == n - 1) {
					return grid[n - 1][n - 1];
				}

				for (int j = 0; j < 8; j++) {
					if (isSafe(grid, r + dr[j], c + dc[j])) {
						q.push_back({r + dr[j], c + dc[j]});
						grid[r + dr[j]][c + dc[j]] = grid[r][c] + 1;
					}
				}
			}
		}

		return -1;
	}

};