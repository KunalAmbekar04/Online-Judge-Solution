// https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
	int dp[1003];
	int solve(vector<int> &ar, int n) {
		if (n < 0) {
			return 0;
		}

		if (n == 0 || n == 1) {
			return ar[n];
		}

		if (dp[n] != -1) {
			return dp[n];
		}

		return dp[n] = ar[n] + min(solve(ar, n - 1), solve(ar, n - 2));
	}
public:
	int minCostClimbingStairs(vector<int>& cost) {
		memset(dp, -1, sizeof(dp));
		int n = cost.size();
		return min(solve(cost, n - 1), solve(cost, n - 2));
	}
};