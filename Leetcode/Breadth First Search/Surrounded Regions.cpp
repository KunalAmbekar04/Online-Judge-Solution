// https://leetcode.com/problems/surrounded-regions/

class Solution {

public:

	int dr[4] = { -1, 0, 1, 0};
	int dc[4] = {0, 1, 0, -1};

	bool isSafe(vector<vector<char>>& board, int r, int c) {
		int n = board.size();
		int m = board[0].size();

		if (r < 0 || r == n || c < 0 || c == m) {
			return false;
		}

		if (board[r][c] == 'O') {
			return true;
		}
		return false;
	}

	void dfs(vector<vector<char>>& board, int r, int c) {
		board[r][c] = '1';

		for (int i = 0; i < 4; i++) {
			if (isSafe(board, r + dr[i], c + dc[i])) {
				dfs(board, r + dr[i], c + dc[i]);
			}
		}
	}

	void solve(vector<vector<char>>& board) {
		int n = board.size();
		if (n == 0) {
			return;
		}
		int m = board[0].size();

		for (int i = 0; i < m; i++) {
			if (board[0][i] == 'O') {
				dfs(board, 0, i);
			}
		}

		for (int i = 0; i < n; i++) {
			if (board[i][0] == 'O') {
				dfs(board, i, 0);
			}
		}

		for (int i = 0; i < m; i++) {
			if (board[n - 1][i] == 'O') {
				dfs(board, n - 1, i);
			}
		}

		for (int i = 0; i < n; i++) {
			if (board[i][m - 1] == 'O') {
				dfs(board, i, m - 1);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 'O') {
					board[i][j] = 'X';
				}
				else if (board[i][j] == '1') {
					board[i][j] = 'O';
				}
			}
		}
	}

};