// https://leetcode.com/problems/cousins-in-binary-tree/

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
	int temp = 0;
	TreeNode *parX = NULL;
	TreeNode *parY = NULL;
	bool flag = false;

	void solve(TreeNode *root, TreeNode *parent, int depth, int x, int y) {
		if (!root) {
			return;
		}

		if (root->val == x || root->val == y) {
			if (flag) {
				temp -= depth;
				parY = parent;
				return;
			}
			temp += depth;
			parX = parent;
			flag = true;
			return;
		}

		parent = root;
		solve(root->left, parent, depth + 1, x, y);
		solve(root->right, parent, depth + 1, x, y);
	}
public:
	bool isCousins(TreeNode* root, int x, int y) {
		if (!root) {
			return false;
		}

		solve(root, NULL, 0, x, y);
		if (temp == 0) {
			if (parX != parY && parX != NULL && parY != NULL) {
				return true;
			}
		}
		return false;
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

#define ff first
#define ss second

class Solution {
public:
	bool isCousins(TreeNode* root, int x, int y) {
		if (!root) {
			return false;
		}

		list<pair<TreeNode*, pair<TreeNode*, int>>> q;
		q.push_back({root, {NULL, 0}});

		int temp = 0;
		TreeNode *parX = NULL;
		TreeNode *parY = NULL;
		bool flag = false;
		while (!q.empty()) {
			TreeNode* node = q.front().ff;
			TreeNode* parent = q.front().ss.ff;
			int depth = q.front().ss.ss;
			q.pop_front();

			if (node->val == x || node->val == y) {
				if (flag) {
					temp -= depth;
					parY = parent;
					continue;
				}
				temp += depth;
				parX = parent;
				flag = true;
				continue;
			}

			if (node->left) {
				q.push_back({node->left, {node, depth + 1}});
			}

			if (node->right) {
				q.push_back({node->right, {node, depth + 1}});
			}
		}

		if (temp == 0) {
			if (parX != parY && parX && parY) {
				return true;
			}
		}
		return false;
	}
};