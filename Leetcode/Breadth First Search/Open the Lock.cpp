// https://leetcode.com/problems/open-the-lock/

class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		int count = 0;
		unordered_set<string> visited;
		for (auto itr : deadends) {
			if (itr == "0000") {
				return -1;
			}
			visited.insert(itr);
		}
		list<string> q;
		q.push_back("0000");
		visited.insert("0000");

		while (!q.empty()) {
			int n = q.size();
			for (int i = 0; i < n; i++) {
				string s = q.front();
				q.pop_front();

				if (s == target) {
					return count;
				}

				for (int j = 0; j < 4; j++) {
					char ch = s[j];
					s[j] = ch == '9' ? '0' : ch + 1;
					if (visited.find(s) == visited.end()) {
						q.push_back(s);
						visited.insert(s);
					}

					s[j] = ch == '0' ? '9' : ch - 1;
					if (visited.find(s) == visited.end()) {
						q.push_back(s);
						visited.insert(s);
					}

					s[j] = ch;
				}

			}
			count++;
		}

		return -1;
	}
};