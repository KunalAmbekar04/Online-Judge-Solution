// https://leetcode.com/problems/leaf-similar-trees/

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
	void solve(TreeNode *root, vector<int> &leap) {
		if (!root) {
			return;
		}

		if (!root->left && !root->right) {
			leap.push_back(root->val);
		}

		solve(root->left, leap);
		solve(root->right, leap);
	}


public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		if (!root1 && !root2) {
			return true;
		}

		if (!root1 || !root2) {
			return false;
		}

		vector<int> leap1;
		solve(root1, leap1);

		vector<int> leap2;
		solve(root2, leap2);

		int n = leap1.size();
		int m = leap2.size();
		if (n != m) {
			return false;
		}

		for (int i = 0; i < n; i++) {
			if (leap1[i] != leap2[i]) {
				return false;
			}
		}

		return true;
	}
};