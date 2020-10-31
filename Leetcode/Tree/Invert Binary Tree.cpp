// https://leetcode.com/problems/invert-binary-tree/

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
	TreeNode* invertTree(TreeNode* root) {
		if (!root) {
			return NULL;
		}

		TreeNode *lT = invertTree(root->left);
		TreeNode *rT = invertTree(root->right);

		root->left = rT;
		root->right = lT;

		return root;

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
	TreeNode* invertTree(TreeNode* root) {
		if (!root) {
			return NULL;
		}

		stack<TreeNode *> s;
		s.push(root);
		while (!s.empty()) {
			TreeNode *curr = s.top();
			s.pop();

			if (curr->left) {
				s.push(curr->left);
			}

			if (curr->right) {
				s.push(curr->right);
			}

			TreeNode *temp = curr->left;
			curr->left = curr->right;
			curr->right = temp;
		}

		return root;
	}
};