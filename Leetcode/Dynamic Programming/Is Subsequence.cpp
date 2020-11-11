// https://leetcode.com/problems/is-subsequence/

// Top Down Approach
class Solution {
	bool solve(string x, string y, int n, int m) {
		if (n == 0) {
			return true;
		}

		if (m == 0) {
			return false;
		}

		if (x[n - 1] == y[m - 1]) {
			return solve(x, y, n - 1, m - 1);
		}

		return solve(x, y, n, m - 1);
	}
public:
	bool isSubsequence(string s, string t) {
		return solve(s, t, s.length(), t.length());
	}
};

// Bottom Up Approach
class Solution {
public:
	bool isSubsequence(string s, string t) {
		int n = s.length();
		int m = t.length();
		bool dp[n + 1][m + 1];

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (i == 0) {
					dp[i][j] = true;
					continue;
				}

				if (j == 0) {
					dp[i][j] = false;
					continue;
				}

				if (s[i - 1] == t[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = dp[i][j - 1];
				}
			}
		}
		return dp[n][m];
	}
};

// Two Pointer Approach
class Solution {
public:
	bool isSubsequence(string s, string t) {
		int n = t.length();
		int m = s.length();

		int i = 0;
		int j = 0;

		while (i < n && j < m) {
			if (t[i] == s[j]) {
				j++;
			}
			i++;
		}

		return j == m;
	}
};