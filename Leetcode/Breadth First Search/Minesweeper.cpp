// https://leetcode.com/problems/minesweeper/

class Solution {

	int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1};
	int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

	bool isValid(vector<vector<char>>& board, int r, int c) {
		if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) {
			return false;
		}
		return true;
	}

	int countMine(vector<vector<char>>& board, int r, int c) {
		int count = 0;
		for (int i = 0; i < 8; i++) {
			if (isValid(board, r + dr[i], c + dc[i])) {
				if (board[r + dr[i]][c + dc[i]] == 'M') {
					count++;
				}
			}
		}
		return count;
	}

	void solve(vector<vector<char>>& board, vector<vector<bool>> &visited, int r, int c) {
		visited[r][c] = true;

		if (board[r][c] == 'M') {
			board[r][c] = 'X';
			return;
		}

		if (board[r][c] == 'E') {
			int count = countMine(board, r, c);
			if (count == 0) {
				board[r][c] = 'B';
				for (int i = 0; i < 8; i++) {
					if (isValid(board, r + dr[i], c + dc[i]) && !visited[r + dr[i]][c + dc[i]]) {
						solve(board, visited, r + dr[i], c + dc[i]);
					}
				}
			}
			else {
				board[r][c] = '0' + count;
			}
		}
	}

public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		vector<vector<bool>> visited(board.size(), (vector<bool>(board[0].size(), false)));
		solve(board, visited, click[0], click[1]);
		return board;
	}
};