// https://leetcode.com/problems/n-ary-tree-postorder-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
	vector<int> postorder(Node* root) {
		vector<int> result;
		if (!root) {
			return result;
		}

		stack<Node *> s;
		s.push(root);
		while (!s.empty()) {
			Node *curr = s.top();
			s.pop();
			result.push_back(curr->val);

			for (auto itr : curr->children) {
				s.push(itr);
			}
		}
		reverse(result.begin(), result.end());
		return result;
	}
};