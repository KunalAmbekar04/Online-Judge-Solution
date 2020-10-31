// https://leetcode.com/problems/generate-parentheses/

class Solution {
	vector<string> result;

	void solve(int open, int close, string output) {
		if (open == 0 && close == 0) {
			result.push_back(output);
			return;
		}

		if (open == close) {
			string op = output;
			op.push_back('(');
			solve(open - 1, close, op);
			return;
		}

		if (open == 0 && close > 0) {
			string op = output;
			op.push_back(')');
			solve(open, close - 1, op);
			return;
		}

		string op1 = output;
		op1.push_back('(');
		string op2 = output;
		op2.push_back(')');

		solve(open - 1, close, op1);
		solve(open, close - 1, op2);
	}
public:
	vector<string> generateParenthesis(int n) {
		solve(n, n, "");
		return result;
	}
};