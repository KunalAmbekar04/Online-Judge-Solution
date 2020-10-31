// https://leetcode.com/problems/letter-tile-possibilities/

class Solution {
	set<string> st;
	void solve(string input, int idx, string output) {
		if (idx == input.size()) {
			st.insert(output);
			return;
		}



		for (int i = 0; i <= output.size(); i++) {
			string op1 = output;
			string op2 = output;
			op1.insert(op1.begin() + i, input[idx]);
			solve(input, idx + 1, op1);
			op1.erase(op1.begin() + i);
			solve(input, idx + 1, op2);
		}
	}
public:
	int numTilePossibilities(string tiles) {
		solve(tiles, 0, "");
		return st.size() - 1;
	}
};