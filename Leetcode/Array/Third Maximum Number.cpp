// https://leetcode.com/problems/third-maximum-number/


// Using Array logic
#define ll long long int
class Solution {
public:
	int thirdMax(vector<int>& ar) {
		ll a = LONG_MIN;
		ll b = LONG_MIN;
		ll c = LONG_MIN;

		int n = ar.size();
		for (int i = 0; i < n; i++) {
			if (ar[i] > a) {
				c = b;
				b = a;
				a = ar[i];
			}
			else if (ar[i] > b && ar[i] != a) {
				c = b;
				b = ar[i];
			}
			else if (ar[i] > c && ar[i] != a && ar[i] != b) {
				c = ar[i];
			}
		}

		return (c == LONG_MIN) ? a : c;
	}
};

// Using Heap
class Solution {
public:
	int thirdMax(vector<int>& ar) {
		priority_queue<int, vector<int>, greater<int>> hp;
		set<int> st(ar.begin(), ar.end());

		for (auto itr : st) {
			if (hp.size() < 3) {
				hp.push(itr);
			}
			else {
				if (hp.top() < itr) {
					hp.pop();
					hp.push(itr);
				}
			}
		}

		if (hp.size() == 3) {
			return hp.top();
		}

		int max_num = -1;
		while (!hp.empty()) {
			max_num = hp.top();
			hp.pop();
		}

		return max_num;
	}
};