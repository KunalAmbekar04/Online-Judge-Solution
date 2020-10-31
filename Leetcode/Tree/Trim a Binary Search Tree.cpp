// https://leetcode.com/problems/trim-a-binary-search-tree/

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
	TreeNode* insert(TreeNode *root, int val) {
		TreeNode *nn = new TreeNode(val);

		if (!root) {
			return nn;
		}

		if (root->val < val) {
			root->right = insert(root->right, val);
		}
		else {
			root->left = insert(root->left, val);
		}
		return root;
	}
public:
	TreeNode* trimBST(TreeNode* root, int low, int high) {
		if (!root) {
			return NULL;
		}

		TreeNode *new_root = new TreeNode(INT_MIN + 1);
		list<TreeNode *> q;
		q.push_back(root);
		while (!q.empty()) {
			TreeNode *curr = q.front();
			q.pop_front();

			if (curr->val >= low && curr->val <= high) {
				new_root = insert(new_root, curr->val);
			}

			if (curr->left) {
				q.push_back(curr->left);
			}

			if (curr->right) {
				q.push_back(curr->right);
			}
		}
		return new_root->right;
	}
};

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
	TreeNode* trimBST(TreeNode* root, int low, int high) {
		if (!root) {
			return NULL;
		}

		if (root->val >= low && root->val <= high) {
			root->left = trimBST(root->left, low, high);
			root->right = trimBST(root->right, low, high);
			return root;
		}

		if (root->val < low) {
			return trimBST(root->right, low, high);
		}
		return trimBST(root->left, low, high);
	}
};