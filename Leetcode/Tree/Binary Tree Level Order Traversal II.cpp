// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		queue<TreeNode *> q;
		vector<int> temp;
		if (!root) {
			return res;
		}
		q.push(root);
		q.push(NULL);
		while (!q.empty()) {
			TreeNode *curr = q.front();
			q.pop();
			if (!curr) {
				res.push_back(temp);
				temp.clear();
				if (q.empty()) {
					reverse(res.begin(), res.end());
					return res;
				} else {
					q.push(NULL);
					continue;
				}
			}
			temp.push_back(curr->val);
			if (curr->left) {
				q.push(curr->left);
			}
			if (curr->right) {
				q.push(curr->right);
			}
		}
		return res;
	}
};