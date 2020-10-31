// https://leetcode.com/problems/top-k-frequent-elements/

#define pii pair<int,int>
#define ff first
#define ss second
class Solution {
public:
	vector<int> topKFrequent(vector<int>& ar, int k) {
		int n = ar.size();
		unordered_map<int, int> hash;
		for (int i = 0; i < n; i++) {
			hash[ar[i]]++;
		}

		priority_queue<pii, vector<pii>, greater<pii>> minH;

		for (auto itr : hash) {
			minH.push({itr.ss, itr.ff});
			if (minH.size() > k) {
				minH.pop();
			}
		}

		vector<int> result;
		while (!minH.empty()) {
			result.push_back(minH.top().ss);
			minH.pop();
		}
		return result;
	}
};