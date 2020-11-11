// https://leetcode.com/problems/find-largest-value-in-each-tree-row/


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
public:
	vector<int> largestValues(TreeNode* root) {
		vector<int> result;
		if (!root) {
			return result;
		}

		list<TreeNode*> q;
		q.push_back(root);
		q.push_back(NULL);

		int max_so_far = INT_MIN;

		while (q.size() > 1) {
			TreeNode *node = q.front();
			q.pop_front();

			if (!node) {
				result.push_back(max_so_far);
				max_so_far = INT_MIN;
				q.push_back(NULL);
				continue;
			}

			if (node->val > max_so_far) {
				max_so_far = node->val;
			}

			if (node->left) {
				q.push_back(node->left);
			}

			if (node->right) {
				q.push_back(node->right);
			}
		}

		result.push_back(max_so_far);

		return result;
	}
};