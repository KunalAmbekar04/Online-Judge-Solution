// https://leetcode.com/problems/sum-of-left-leaves/

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
	int sumOfLeftLeaves(TreeNode* root) {
		if (!root) {
			return 0;
		}

		int sum = 0;
		list<TreeNode *> q;
		q.push_back(root);
		while (!q.empty()) {
			TreeNode *curr = q.front();
			q.pop_front();

			if (curr->left) {
				if (!curr->left->left && !curr->left->right) {
					sum += curr->left->val;
				}
				q.push_back(curr->left);
			}

			if (curr->right) {
				q.push_back(curr->right);
			}
		}

		return sum;
	}
};