// https://leetcode.com/problems/find-bottom-left-tree-value/


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
	int findBottomLeftValue(TreeNode* root) {
		vector<vector<int>> result;
		vector<int> temp;
		list<TreeNode*> q;
		q.push_back(root);
		q.push_back(NULL);

		while (q.size() > 1) {
			TreeNode *node = q.front();
			q.pop_front();

			if (!node) {
				result.push_back(temp);
				temp.clear();
				q.push_back(NULL);
				continue;
			}

			temp.push_back(node->val);

			if (node->left) {
				q.push_back(node->left);
			}

			if (node->right) {
				q.push_back(node->right);
			}
		}
		if (temp.size()) {
			result.push_back(temp);
		}

		return result[result.size() - 1][0];
	}
};