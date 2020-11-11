// https://leetcode.com/problems/rotting-oranges/

class Solution {
	int dr[4] = { -1, 0, 1, 0};
	int dc[4] = {0, 1, 0, -1};

	bool isSafe(vector<vector<int>>& grid, int r, int c) {
		int n = grid.size();
		int m = grid[0].size();

		if (r < 0 || r == n || c < 0 || c == m || grid[r][c] == 0 || grid[r][c] == 2) {
			return false;
		}

		return true;
	}
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int minute = 0;
		int fresh = 0;
		list<pair<int, int>> q;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 2) {
					q.push_back({i, j});
				}
				else if (grid[i][j] == 1) {
					fresh++;
				}
			}
		}

		while (!q.empty() && fresh) {
			int n = q.size();
			for (int i = 0; i < n; i++) {
				int r = q.front().first;
				int c = q.front().second;
				q.pop_front();

				for (int j = 0; j < 4; j++) {
					if (isSafe(grid, r + dr[j], c + dc[j])) {
						q.push_back({r + dr[j], c + dc[j]});
						grid[r + dr[j]][c + dc[j]] = 2;
						fresh--;
					}
				}

			}
			minute++;
		}
		return fresh == 0 ? minute : -1;
	}
};