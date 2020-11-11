// https://leetcode.com/problems/as-far-from-land-as-possible/

class Solution {
	int dx[4] = { -1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
public:
	int maxDistance(vector<vector<int>>& grid) {
		int result = 0;
		list<pair<int, int>> q;
		int n = grid.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					q.push_back({i, j});
				}
			}
		}

		while (!q.empty()) {
			int sz = q.size();

			for (int i = 0; i < sz; i++) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop_front();

				for (int j = 0; j < 4; j++) {
					int nx = x + dx[j];
					int ny = y + dy[j];

					if (nx < 0 || nx == n || ny < 0 || ny == n || grid[nx][ny] != 0) {
						continue;
					}

					q.push_back({nx, ny});
					grid[nx][ny] = grid[x][y] + 1;

					result = max(result, grid[nx][ny]);
				}
			}
		}
		return result ? result - 1 : -1;
	}
};