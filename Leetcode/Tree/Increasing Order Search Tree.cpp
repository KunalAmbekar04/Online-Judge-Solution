// https://leetcode.com/problems/increasing-order-search-tree/

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
	TreeNode* increasingBST(TreeNode* root) {
		stack<TreeNode *> s;
		TreeNode *head = new TreeNode(0);
		TreeNode *pre = head;
		while (!s.empty() || root) {
			while (root) {
				s.push(root);
				root = root->left;
			}
			root = s.top();
			s.pop();
			pre->right = root;
			pre = pre->right;

			root->left = NULL;
			root = root->right;
		}
		return head->right;
	}
};