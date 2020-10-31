//https://leetcode.com/problems/sort-characters-by-frequency/

#define pii pair<int,char>
#define ff first
#define ss second
class Solution {
public:
	string frequencySort(string s) {
		int n = s.length();
		unordered_map<char, int> hash;
		for (int i = 0; i < n; i++) {
			hash[s[i]]++;
		}

		priority_queue<pii> maxH;

		for (auto itr : hash) {
			maxH.push({itr.ss, itr.ff});
		}

		string result = "";
		while (!maxH.empty()) {
			int count = maxH.top().ff;
			char element = maxH.top().ss;
			while (count--) {
				result.push_back(element);
			}
			maxH.pop();
		}
		return result;
	}
};