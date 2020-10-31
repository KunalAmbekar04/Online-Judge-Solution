// https://leetcode.com/problems/count-number-of-teams/


// Solution 1
// Time Complexity - O(n^3)
class Solution {
public:
	int numTeams(vector<int>& ar) {
		int n = ar.size();
		int count = 0;

		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				for (int k = j + 1; k < n; k++) {
					if ((ar[i] < ar[j] && ar[j] < ar[k]) || (ar[i] > ar[j] && ar[j] > ar[k])) {
						count++;
					}
				}
			}
		}

		return count;
	}
};


// Solution 2
// Time Complexity - O(n^2)
class Solution {
public:
	int numTeams(vector<int>& ar) {
		int n = ar.size();
		int count = 0;

		for (int i = 1; i < n - 1; i++) {
			int lS = 0;
			int lG = 0;
			for (int j = 0; j < i; j++) {
				if (ar[i] < ar[j]) {
					lG++;
				}
				else if (ar[i] > ar[j]) {
					lS++;
				}
			}

			int rS = 0;
			int rG = 0;
			for (int k = i + 1; k < n; k++) {
				if (ar[i] < ar[k]) {
					rG++;
				}
				else if (ar[i] > ar[k]) {
					rS++;
				}
			}

			count += (lS * rG) + (lG * rS);
		}

		return count;
	}
};