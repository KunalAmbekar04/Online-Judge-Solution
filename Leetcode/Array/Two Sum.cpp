// https://leetcode.com/problems/two-sum/

// Solution 1 - HashTable
// Time Complexity - O(n)
// Space Complexity - O(n)
class Solution {
public:
	vector<int> twoSum(vector<int>& ar, int target) {
		vector<int> res;
		map<int, int> mp;
		int n = ar.size();

		for (int i = 0; i < n; i++) {
			int tmp = target - ar[i];
			if (mp.find(tmp) != mp.end()) {
				res.push_back(mp[tmp]);
				res.push_back(i);
				break;
			}
			mp[ar[i]] = i;
		}

		return res;
	}
};


// Solution 2
// Time Complexity - O(n)
// Space Complexity - O(1)
class Solution {
public:
	vector<int> twoSum(vector<int>& ar, int target) {
		vector<int> res;
		int n = ar.size();

		for (int i = 0; i < n; i++) {
			int tmp = target - ar[i];
			auto itr = find(ar.begin(), ar.end(), tmp);
			if (itr != ar.end() && (itr - ar.begin()) != i) {
				res.push_back(i);
				res.push_back(itr - ar.begin());
				break;
			}
		}

		return res;
	}
};