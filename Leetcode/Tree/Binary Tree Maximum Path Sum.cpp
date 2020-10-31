// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
	int path_sum = INT_MIN;
	int solve(TreeNode *root) {
		if (!root) {
			return 0;
		}

		int lT = max(0, solve(root->left));
		int rT = max(0, solve(root->right));

		int temp_path1 = max(lT, rT) + root->val;
		int temp_path2 = lT + rT + root->val;

		path_sum = max(path_sum, max(temp_path1, temp_path2));

		return temp_path1;
	}
public:
	int maxPathSum(TreeNode* root) {
		solve(root);
		return path_sum;
	}
};


class Solution {
	int path_sum = INT_MIN;
	int solve(TreeNode *root) {
		if (!root) {
			return 0;
		}

		int lT = max(0, solve(root->left));
		int rT = max(0, solve(root->right));

		path_sum = max(path_sum, lT + rT + root->val);

		return max(lT, rT) + root->val;
	}
public:
	int maxPathSum(TreeNode* root) {
		solve(root);
		return path_sum;
	}
};