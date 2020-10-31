// https://leetcode.com/problems/sudoku-solver/

class Solution {
	int n = 9;
	bool isSafe(vector<vector<char>>& board, int r, int c, int val) {
		for (int i = 0; i < n; i++) {
			if (board[r][i] == '0' + val || board[i][c] == '0' + val) {
				return false;
			}
		}

		int idxR = r - r % 3;
		int idxC = c - c % 3;

		for (int i = idxR; i < idxR + 3; i++) {
			for (int j = idxC; j < idxC + 3; j++) {
				if (board[i][j] == '0' + val) {
					return false;
				}
			}

		}
		return true;
	}

	bool solve(vector<vector<char>>& board, int r, int c) {
		if (r == n) {
			return true;
		}

		if (board[r][c] != '.') {
			if (c + 1 == n) {
				return solve(board, r + 1, 0);
			}
			return solve(board, r, c + 1);
		}

		for (int i = 1; i <= 9; i++) {
			if (isSafe(board, r, c, i)) {
				board[r][c] = '0' + i;
				bool status;
				if (c + 1 == n) {
					status = solve(board, r + 1, 0);
				}
				else {
					status = solve(board, r, c + 1);
				}
				if (status) {
					return true;
				}
				board[r][c] = '.';
			}
		}
		return false;
	}
public:
	void solveSudoku(vector<vector<char>>& board) {
		solve(board, 0, 0);
	}
};