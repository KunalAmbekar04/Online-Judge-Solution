// https://leetcode.com/problems/search-insert-position/

class Solution {
public:
	int searchInsert(vector<int>& ar, int target) {
		int start = 0;
		int end = ar.size() - 1;

		while (start <= end) {
			int mid = start + (end - start) / 2;

			if (ar[mid] == target) {
				return mid;
			}

			if (ar[mid] > target) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
		}

		return start;
	}
};