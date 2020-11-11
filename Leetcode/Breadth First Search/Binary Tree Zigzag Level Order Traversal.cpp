// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
	vector<vector<int>> result;
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (!root) {
			return result;
		}
		list<TreeNode*> q;
		vector<int> temp;
		q.push_back(root);
		q.push_back(NULL);

		while (q.size() > 1) {
			TreeNode *node = q.front();
			q.pop_front();

			if (!node) {
				result.push_back(temp);
				temp.clear();
				q.push_back(NULL);
				continue;
			}

			temp.push_back(node->val);

			if (node->left) {
				q.push_back(node->left);
			}

			if (node->right) {
				q.push_back(node->right);
			}
		}

		if (!temp.empty()) {
			result.push_back(temp);
		}

		for (int i = 0; i < result.size(); i++) {
			if (i % 2) {
				reverse(result[i].begin(), result[i].end());
			}
		}

		return result;
	}
};