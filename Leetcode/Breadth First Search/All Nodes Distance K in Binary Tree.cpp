// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
		unordered_map<TreeNode*, TreeNode*> parent;
		list<TreeNode*> q;
		q.push_back(root);

		while (!q.empty()) {
			TreeNode *node = q.front();
			q.pop_front();

			if (node->left) {
				parent[node->left] = node;
				q.push_back(node->left);
			}

			if (node->right) {
				parent[node->right] = node;
				q.push_back(node->right);
			}
		}

		unordered_map<TreeNode*, bool> visited;
		q.push_back(target);
		visited[target] = true;
		int level = 0;
		while (!q.empty()) {
			int n = q.size();
			if (level == K) {
				break;
			}
			for (int i = 0; i < n; i++) {
				TreeNode *node = q.front();
				q.pop_front();

				if (node->left && !visited[node->left]) {
					q.push_back(node->left);
					visited[node->left] = true;
				}

				if (node->right && !visited[node->right]) {
					q.push_back(node->right);
					visited[node->right] = true;
				}

				if (parent[node] && !visited[parent[node]]) {
					q.push_back(parent[node]);
					visited[parent[node]] = true;
				}
			}
			level++;
		}

		vector<int> result;
		while (!q.empty()) {
			result.push_back(q.front()->val);
			q.pop_front();
		}

		return result;
	}

};