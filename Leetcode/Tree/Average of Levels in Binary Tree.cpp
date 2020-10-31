// https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> result;
		if (!root) {
			return result;
		}

		list<TreeNode *> q;
		q.push_back(root);
		q.push_back(NULL);
		long sum = 0;
		long sz = 0;
		while (q.size() > 1) {
			TreeNode *curr = q.front();
			q.pop_front();
			if (!curr) {
				q.push_back(NULL);
				result.push_back((double)sum / sz);
				sum = 0;
				sz = 0;
				continue;
			}
			sum += curr->val;
			sz++;

			if (curr->left) {
				q.push_back(curr->left);
			}

			if (curr->right) {
				q.push_back(curr->right);
			}
		}

		if (q.size() == 1) {
			result.push_back((double)sum / sz);
		}

		return result;
	}
};