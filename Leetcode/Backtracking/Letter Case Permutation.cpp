// https://leetcode.com/problems/letter-case-permutation/

class Solution {
	vector<string> result;

	void solve(string input, string output) {
		if (input == "") {
			result.push_back(output);
			return;
		}

		if (input[0] >= '0' && input[0] <= '9') {
			string op = output;
			op.push_back(input[0]);
			input.erase(input.begin() + 0);
			solve(input, op);
			return;
		}

		string op1 = output;
		op1.push_back(input[0]);

		string op2 = output;
		if (input[0] >= 'a' && input[0] <= 'z') {
			op2.push_back(input[0] - 'a' + 'A');
		}
		else {
			op2.push_back(input[0] - 'A' + 'a');
		}

		input.erase(input.begin() + 0);

		solve(input, op1);
		solve(input, op2);
	}

public:
	vector<string> letterCasePermutation(string S) {
		solve(S, "");
		return result;
	}
};