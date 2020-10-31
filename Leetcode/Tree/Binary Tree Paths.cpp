// https://leetcode.com/problems/binary-tree-paths/

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
	vector<string> result;
	void solve(TreeNode *root, string s = "") {
		if (!root) {
			return;
		}

		if (root->left || root->right) {
			s = s + to_string(root->val) + "->";
		}
		else {
			s = s + to_string(root->val);
			result.push_back(s);
		}

		solve(root->left, s);
		solve(root->right, s);
	}
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		solve(root);
		return result;
	}
};