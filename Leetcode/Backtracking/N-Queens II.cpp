// https://leetcode.com/problems/n-queens-ii/

class Solution {
	int count = 0;

	bool isSafe(vector<vector<int>> &board, int r, int c) {
		int n = board.size();

		for (int i = 0; i < n; i++) {
			if (board[i][c] || board[r][i]) {
				return false;
			}
		}

		int i = r;
		int j = c;
		while (i >= 0 && j >= 0) {
			if (board[i][j]) {
				return false;
			}
			i--;
			j--;
		}

		i = r;
		j = c;
		while (i >= 0 && j < n) {
			if (board[i][j]) {
				return false;
			}
			i--;
			j++;
		}
		return true;
	}

	bool solve(vector<vector<int>> &board, int r) {
		if (r == board.size()) {
			count++;
			return false;
		}

		for (int i = 0; i < board.size(); i++) {
			if (isSafe(board, r, i)) {
				board[r][i] = 1;
				if (solve(board, r + 1)) {
					return true;
				}
				board[r][i] = 0;
			}
		}
		return false;
	}
public:
	int totalNQueens(int n) {
		vector<vector<int>> board;
		for (int i = 0; i < n; i++) {
			vector<int> temp(n, 0);
			board.push_back(temp);

		}

		solve(board, 0);
		return count;

	}
};