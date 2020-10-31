// https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		map<int, int> mp;
		stack<int> st;
		int n = nums2.size();

		for (int i = n - 1; i >= 0; i--) {
			if (st.empty()) {
				mp[nums2[i]] = -1;
			}
			else if (st.top() <= nums2[i]) {
				while (!st.empty() && st.top() <= nums2[i]) {
					st.pop();
				}

				if (st.empty()) {
					mp[nums2[i]] = -1;
				}
				else if (st.top() > nums2[i]) {
					mp[nums2[i]] = st.top();
				}
			}
			else {
				mp[nums2[i]] = st.top();
			}
			st.push(nums2[i]);
		}

		for (int i = 0; i < nums1.size(); i++) {
			auto itr = mp.find(nums1[i]);
			if (itr != mp.end()) {
				res.push_back(itr->second);
			}
		}

		return res;
	}
};