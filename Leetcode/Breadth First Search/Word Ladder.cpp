// https://leetcode.com/problems/word-ladder/

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
			return 0;
		}

		unordered_set<string> s(wordList.begin(), wordList.end());
		int level = 0;
		list<string> q;
		q.push_back(beginWord);

		while (!q.empty()) {
			int n = q.size();

			for (int i = 0; i < n; i++) {
				string word = q.front();
				q.pop_front();

				if (word == endWord) {
					return level + 1;
				}


				for (int j = 0; j < word.length(); j++) {
					char ch = word[j];

					for (int k = 0; k < 26; k++) {
						word[j] = 'a' + k;
						if (s.find(word) != s.end()) {
							q.push_back(word);
							s.erase(word);
						}
					}

					word[j] = ch;
				}
			}
			level++;
		}
		return 0;
	}
};