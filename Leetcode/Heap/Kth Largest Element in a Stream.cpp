// https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
	priority_queue<int, vector<int>, greater<int>> minH;
	int k;
public:
	KthLargest(int k, vector<int>& nums) {
		this->k = k;
		for (auto itr : nums) {
			minH.push(itr);
			if (minH.size() > k) {
				minH.pop();
			}
		}
	}

	int add(int val) {
		minH.push(val);
		if (minH.size() > k) {
			minH.pop();
		}
		return minH.top();
	}
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */