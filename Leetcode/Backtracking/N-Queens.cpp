// https://leetcode.com/problems/n-queens/

class Solution {
	vector<vector<string>> result;

	vector<string> buildBoard(vector<vector<int>> &board) {
		vector<string> temp;
		for (int i = 0; i < board.size(); i++) {
			string s = "";
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j]) {
					s.push_back('Q');
				}
				else {
					s.push_back('.');
				}
			}
			temp.push_back(s);
		}
		return temp;
	}

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
			result.push_back(buildBoard(board));
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
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<int>> board;
		for (int i = 0; i < n; i++) {
			vector<int> temp(n, 0);
			board.push_back(temp);

		}
		solve(board, 0);
		return result;
	}
};