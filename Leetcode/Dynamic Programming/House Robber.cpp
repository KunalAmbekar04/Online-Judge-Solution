// https://leetcode.com/problems/house-robber/

// Top Down Approach
class Solution {
	int dp[107];
	int solve(vector<int> &ar, int n) {
		if (n == 0) {
			return 0;
		}

		if (n == 1) {
			return ar[0];
		}

		if (dp[n] != -1) {
			return dp[n];
		}

		return dp[n] = max(ar[n - 1] + solve(ar, n - 2), solve(ar, n - 1));
	}
public:
	int rob(vector<int>& ar) {
		memset(dp, -1, sizeof(dp));
		int n = ar.size();
		if (n == 0) {
			return 0;
		}

		return solve(ar, n);
	}
};

// Bottom Up Approach
class Solution {
public:
	int rob(vector<int>& ar) {
		int n = ar.size();
		if (n == 0) {
			return 0;
		}
		int dp[n + 1];
		dp[0] = 0;
		dp[1] = ar[0];

		for (int i = 2; i <= n; i++) {
			dp[i] = max(ar[i - 1] + dp[i - 2], dp[i - 1]);
		}
		return dp[n];
	}
};