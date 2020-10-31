// https://leetcode.com/problems/min-stack/


// Solution 1 - O(n) Space
class MinStack {
	stack<int> s;
	stack<int> temp;
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		s.push(x);
		if (temp.empty() || x <= temp.top()) {
			temp.push(x);
		}
	}

	void pop() {
		if (s.top() == temp.top()) {
			temp.pop();
		}
		s.pop();
	}

	int top() {
		if (s.empty()) {
			return NULL;
		}
		return s.top();
	}

	int getMin() {
		if (temp.empty()) {
			return NULL;
		}
		return temp.top();
	}
};


//Solution 2 - Constant Space

class MinStack {
	stack<long> s;
	long curr_min;
public:
	/** initialize your data structure here. */

	void push(int x) {
		if (s.empty()) {
			curr_min = x;
			s.push(x);
			return;
		}

		if (x < curr_min) {
			long temp = x;
			s.push(2 * temp - curr_min);
			curr_min = temp;
		} else {
			s.push(x);
		}
	}

	void pop() {
		if (s.empty()) {
			return;
		}
		if (curr_min > s.top()) {
			curr_min = 2 * curr_min - s.top();
		}
		s.pop();
	}

	int top() {
		if (s.empty()) {
			return NULL;
		}
		if (s.top() < curr_min) {
			return curr_min;
		}
		return s.top();
	}

	int getMin() {
		if (s.empty()) {
			return NULL;
		}
		return curr_min;
	}
};
