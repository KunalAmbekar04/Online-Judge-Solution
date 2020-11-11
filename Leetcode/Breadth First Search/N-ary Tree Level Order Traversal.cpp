// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

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
	vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> result;
		if (!root) {
			return result;
		}

		vector<int> temp;
		list<Node*> q;
		q.push_back(root);
		q.push_back(NULL);

		while (q.size() > 1) {
			Node *node = q.front();
			q.pop_front();

			if (!node) {
				result.push_back(temp);
				temp.clear();
				q.push_back(NULL);
				continue;
			}

			temp.push_back(node->val);

			for (auto itr : node->children) {
				if (itr) {
					q.push_back(itr);
				}
			}
		}
		if (temp.size()) {
			result.push_back(temp);
		}

		return result;
	}
};