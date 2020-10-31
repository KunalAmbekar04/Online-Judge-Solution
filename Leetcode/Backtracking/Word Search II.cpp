// https://leetcode.com/problems/word-search-ii/

class Solution {
	bool solve(vector<vector<char>> &board, string &s, int idx, int r, int c) {
		if (idx == s.length())
			return true;


		if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size())
			return false;


		if (board[r][c] != s[idx] || board[r][c] == '*')
			return false;


		idx++;
		board[r][c] = '*';

		bool result =    (solve(board, s, idx, r - 1, c)
		                  || solve(board, s, idx, r  , c + 1)
		                  || solve(board, s, idx, r + 1, c)
		                  || solve(board, s, idx, r  , c - 1));


		board[r][c] = s[idx - 1];
		return result;
	}

public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> result;
		int n = board.size();
		int m = board[0].size();

		for (auto &s : words) {
			bool flag = false;
			for (int i = 0; i < n; i++) {
				if (flag)
					break;

				for (int j = 0; j < m; j++) {
					if (s[0] == board[i][j] && solve(board, s, 0, i, j)) {
						result.push_back(s);
						flag = true;
						break;
					}
				}
			}
		}

		return result;
	}
};