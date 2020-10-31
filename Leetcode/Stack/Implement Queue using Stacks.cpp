// https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
private:
	stack<int> s;
	stack<int> temp;

public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		s.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		while (!s.empty()) {
			temp.push(s.top());
			s.pop();
		}

		int top = temp.top();
		temp.pop();
		while (!temp.empty()) {
			s.push(temp.top());
			temp.pop();
		}

		return top;
	}

	/** Get the front element. */
	int peek() {
		while (!s.empty()) {
			temp.push(s.top());
			s.pop();
		}

		int top = temp.top();
		while (!temp.empty()) {
			s.push(temp.top());
			temp.pop();
		}

		return top;

	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return s.empty();
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */