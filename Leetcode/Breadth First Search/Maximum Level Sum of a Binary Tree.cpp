// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
	int maxLevelSum(TreeNode* root) {
		if (!root) {
			return 0;
		}

		list<TreeNode*> q;
		q.push_back(root);
		int max_sum = INT_MIN;
		int level = 0;
		int result = 0;
		while (!q.empty()) {
			int n = q.size();
			int sum = 0;
			level++;
			for (int i = 0; i < n; i++) {
				TreeNode *node = q.front();
				q.pop_front();

				sum += node->val;
				if (node->left) {
					q.push_back(node->left);
				}

				if (node->right) {
					q.push_back(node->right);
				}
			}

			if (sum > max_sum) {
				max_sum = sum;
				result = level;
			}
		}

		return result;
	}
};