// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution {
public:
	string removeDuplicates(string s) {
		int n = s.length();
		stack<char> st;

		for (int i = n - 1; i >= 0; i--) {
			if (st.empty()) {
				st.push(s[i]);
				continue;
			}

			if (st.top() != s[i]) {
				st.push(s[i]);
			}
			else {
				st.pop();
			}
		}

		string ans = "";
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}

		return ans;
	}
};