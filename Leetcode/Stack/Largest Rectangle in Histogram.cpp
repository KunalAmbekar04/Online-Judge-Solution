// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
	vector<int> smallL(vector<int> heights) {
		int n = heights.size();
		stack<int> s;
		vector<int> nsL;

		for (int i = 0; i < n; i++) {
			if (s.empty()) {
				nsL.push_back(-1);
				s.push(i);
			}
			else if (heights[i] <= heights[s.top()]) {
				while (s.size() > 0 && heights[i] <= heights[s.top()]) {
					s.pop();
				}

				if (s.empty()) {
					nsL.push_back(-1);
					s.push(i);
				}
				else if (heights[s.top()] < heights[i]) {
					nsL.push_back(s.top());
					s.push(i);
				}
			}
			else {
				nsL.push_back(s.top());
				s.push(i);
			}
		}

		return nsL;
	};

	vector<int> smallR(vector<int> heights) {
		int n = heights.size();
		stack<int> s;
		vector<int> nsR;

		for (int i = n - 1; i >= 0; i--) {
			if (s.empty()) {
				nsR.push_back(n);
				s.push(i);
			}
			else if (heights[i] <= heights[s.top()]) {
				while (s.size() > 0 && heights[i] <= heights[s.top()]) {
					s.pop();
				}

				if (s.empty()) {
					nsR.push_back(n);
					s.push(i);
				}
				else if (heights[s.top()] < heights[i]) {
					nsR.push_back(s.top());
					s.push(i);
				}
			}
			else {
				nsR.push_back(s.top());
				s.push(i);
			}
		}
		reverse(nsR.begin(), nsR.end());

		return nsR;
	}
public:
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		vector<int> nsL = smallL(heights);
		vector<int> nsR = smallR(heights);

		int area = 0;
		for (int i = 0; i < n; i++) {
			area = max(area, heights[i] * (nsR[i] - nsL[i] - 1));
		}
		return area;
	}
};