// https://leetcode.com/problems/binary-tree-right-side-view/


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
	vector<int> rightSideView(TreeNode* root) {
		vector<int> result;
		if (!root) {
			return result;
		}

		list<TreeNode*> q;
		q.push_back(root);
		q.push_back(NULL);

		TreeNode *temp = root;
		while (q.size() > 1) {
			TreeNode *node = q.front();
			q.pop_front();

			if (!node) {
				result.push_back(temp->val);
				q.push_back(NULL);
				continue;
			}

			temp = node;

			if (node->left) {
				q.push_back(node->left);
			}

			if (node->right) {
				q.push_back(node->right);
			}
		}

		if (temp) {
			result.push_back(temp->val);
		}

		return result;
	}
};