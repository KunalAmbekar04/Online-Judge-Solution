// https://leetcode.com/problems/word-search/

class Solution {
	int dr[4] = { -1, 0, 1, 0};
	int dc[4] = {0, 1, 0, -1};

	bool solve(vector<vector<char>>& board, string &s, int r, int c) {
		int n = board.size();
		int m = board[0].size();

		if (!s.size()) {
			return true;
		}

		if (r < 0 || r >= n || c < 0 || c >= m) {
			return false;
		}

		if (board[r][c] != s[0]) {
			return false;
		}
		char temp = board[r][c];
		board[r][c] = '.';
		string ss = s.substr(1);
		for (int i = 0; i < 4; i++) {
			if (solve(board, ss, r + dr[i], c + dc[i])) {
				return true;
			}
		}
		board[r][c] = temp;

		return false;
	}
public:
	bool exist(vector<vector<char>>& board, string s) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (solve(board, s, i, j)) {
					return true;
				}
			}
		}
		return false;
	}
};