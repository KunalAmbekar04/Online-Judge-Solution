// https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/

class Solution {
public:
	bool hasGroupsSizeX(vector<int>& deck) {
		if (deck.size() < 2) {
			return false;
		}

		unordered_map<int, int> mp;

		for (auto itr : deck) {
			mp[itr]++;
		}

		int minVal = INT_MAX;
		for (auto itr : mp) {
			minVal = min(minVal, itr.second);
		}


		for (int i = 2; i <= minVal; i++) {
			int flag = 0;
			for (auto itr : mp) {
				if (itr.second % i) {
					flag = 1;
					break;
				}
			}
			if (!flag) {
				return true;
			}
		}

		return false;
	}
};