// https://leetcode.com/problems/range-sum-of-bst/

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
	int sum = 0;
	void inorder(TreeNode *root, int L, int R) {
		if (root) {
			inorder(root->left, L, R);
			if (root->val >= L && root->val <= R) {
				sum += root->val;
			}
			inorder(root->right, L, R);
		}
	}
public:
	int rangeSumBST(TreeNode* root, int L, int R) {
		inorder(root, L, R);
		return sum;
	}
};