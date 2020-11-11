// https://leetcode.com/problems/longest-common-subsequence/

// Top Down Approach - all testcases passed but TLE
class Solution {
	int dp[1007][1007];
	int solve(string x, string y, int n , int m) {
		if (n == 0 || m == 0) {
			return 0;
		}

		if (dp[n][m] != -1) {
			return dp[n][m];
		}

		if (x[n - 1] == y[m - 1]) {
			return dp[n][m] = 1 + solve(x, y, n - 1, m - 1);
		}

		return dp[n][m] = max(solve(x, y, n - 1, m), solve(x, y, n, m - 1));
	}
public:
	int longestCommonSubsequence(string text1, string text2) {
		memset(dp, -1, sizeof(dp));
		return solve(text1, text2, text1.length(), text2.length());
	}
};

// Top Down Approach + Optimisation
class Solution {
	int dp[1007][1007];
	int solve(string x, string y, int n , int m) {
		if (n == 0 || m == 0) {
			return 0;
		}

		if (dp[n][m] != -1) {
			return dp[n][m];
		}

		if (x[n - 1] == y[m - 1]) {
			if (dp[n - 1][m - 1] == -1) {
				dp[n - 1][m - 1] = solve(x, y, n - 1, m - 1);
			}
			return dp[n][m] = 1 + dp[n - 1][m - 1];
		}

		if (dp[n - 1][m] == -1) {
			dp[n - 1][m] = solve(x, y, n - 1, m);
		}

		if (dp[n][m - 1] == -1) {
			dp[n][m - 1] = solve(x, y, n, m - 1);
		}

		return dp[n][m] = max(dp[n - 1][m], dp[n][m - 1]);
	}
public:
	int longestCommonSubsequence(string text1, string text2) {
		memset(dp, -1, sizeof(dp));
		return solve(text1, text2, text1.length(), text2.length());
	}
};

// Bottom Up Approach
class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int n = text1.length();
		int m = text2.length();

		int dp[n + 1][m + 1];
		memset(dp, -1, sizeof(dp));

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (i == 0 || j == 0) {
					dp[i][j] = 0;
					continue;
				}

				if (text1[i - 1] == text2[j - 1]) {
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[n][m];
	}
};